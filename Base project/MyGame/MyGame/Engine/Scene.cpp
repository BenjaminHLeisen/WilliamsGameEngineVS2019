#include "Scene.h"
#include "Game.h"

void Scene::addGameObject(GameObjectPtr gameObjectPtr)
{
	// This "pushes" the game object onto the back (the end) of the list of game objects.
	gameObjects_.push_back(gameObjectPtr);
}

// This function allows game objects to respond to events.
void Scene::handleEvents()
{
	sf::Event event;

	// Go through all the system events that have happend since we last checked
	// for them, and let all the game objects handle them if they want to.
	while (GAME.getRenderWindow().pollEvent(event))
	{
		// If the event indicates we should close the window, just do that.
		if (event.type == sf::Event::Closed)
		{
			GAME.getRenderWindow().close();
			return;
		}

		// Send the event to every game object to handle if it so desires.
		for (auto& gameObject : gameObjects_)//< how is `gameObject` inheriting from `gameObjects_` when 
											 //`gameObjects_` is a list?
											 //		^ I'm pretty sure non-primitive data types 
											 //		are all just classes so this is fine
											 //^ it's so weird that `auto&` is being used to reference a class,
											 // while, at the same time, it seems to be a part of the declaration of 
											 // the class it's refering to.
											 //^ Is this a foreach loop?
											 //		^ for (*type* *parameter for holding currently selected member data* : *array argument*)? 

		//^reminder that the colon isn't*
		// being used to divide for loop 
		// components such as increment, 
		// initial, and looping condition, 
		// semicolon is used for that.
		//		^ 
		//		*Though in this case it is separating loop components 
		//		because part of the syntax used for inheritance is 
		//		reused for foreach loops.									 
											
		{
			gameObject->handleEvent(event);
			//        ^
			// dereferencing argument
		}
	}
}

// This function lets game objects respond to collisions.
void Scene::handleCollisions()
{
	for (auto& gameObject : gameObjects_)
	{
		// Only check objects that ask to be checked.
		if (!gameObject->isCollisionCheckEnabled())
		{
			continue;
		}

		sf::FloatRect collisionRect = gameObject->getCollisionRect();

		// Don't bother checking if this game object has a collision rectangle with no area.
		if (collisionRect.height == 0 || collisionRect.width == 0)
		{
			continue;
		}

		// See if this game object is colliding with any other game object.
		for (auto& otherGameObject : gameObjects_)
		{
			// Don't check an object colliding with itself.
			if (gameObject == otherGameObject)
			{
				continue;
			}

			if (gameObject->isDead())
			{
				return;
			}

			// When we find a collision, invoke the collision handler for both objects.
			if (collisionRect.intersects(otherGameObject->getCollisionRect()))
			{
				gameObject->handleCollision(*otherGameObject);
				otherGameObject->handleCollision(*gameObject);
			}
		}
	}
}

// This function calls update on each of our game objects.
void Scene::updateGameObjects(sf::Time& time)
{
	for (auto& gameObject : gameObjects_)
	{
		gameObject->update(time);
	}
}

// This function calls draw on each of our game objects.
void Scene::drawGameObjects()
{
	for (auto& gameObject : gameObjects_) //<? this for loop doesn't seem to have a incremented variable, a run condition,
										  //   or a break condition
										  //   `gameObjects_` = list of `GameObjectPtr`s
										  //	^ because it's a foreach loop I think
	{
		gameObject->draw();
	}
}

// This function removes objects that indicate they are dead from the scene.
void Scene::removeDeadGameObjects()
{
	// This is a "lambda", which is a fancy name for an anonymous function.
	// It's "anonymous" because it doesn't have a name. We've declared a variable
	// named "isDead", and that variable can be used to call the function, but the
	// function itself is nameless.
	auto isDead = [](GameObjectPtr& p) { return p->isDead(); };

	// Here we use the lambda declared above by passing it to the standard library
	// function remove_if, which calls our lambda once for each element in
	// gameObjects. If our lambda returns true, that game object ends up being
	// removed from our list.
	gameObjects_.erase(
		remove_if(gameObjects_.begin(), gameObjects_.end(), isDead),
		gameObjects_.end()
	);
}

// This function is called once per frame and updates the scene.
void Scene::update(sf::Time& time)
{
	// Clear the window.
	GAME.getRenderWindow().clear();

	// Go through our normal sequence of game loop stuff.
	handleEvents();
	handleCollisions();
	updateGameObjects(time);
	removeDeadGameObjects();
	drawGameObjects();

	// Draw the window as updated by the game objects.
	GAME.getRenderWindow().display();
}