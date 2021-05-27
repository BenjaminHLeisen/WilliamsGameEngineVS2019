/*
File: Ship.cpp
========================
Notes:
--------------
> dot notation exploration
struct 1
{
	int a = 5;
}
struct 2
{
	*** pointer to `struct 1` named point1
}


Maintenance Log:
---------------
	5/3/2021 AD/CE:
		+ added to `Ship::Ship()` function definition
		+ added `Ship::draw()` function definition
			^+ added note
		+ added to notes section
	5/5/2021 AD/CE:
		+~ added to and modified comment in method, `Ship()`, definition
	5/6/2021 AD/CE:
		+ created and included a new ship sprite, `5hip.bmp`, to the Resources folder
		~ changed the ship image from `ship.png` to `5hip.bmp`
		~!? attempted to use the the built in image editor on `5hip.bmp` and completely obliterated the image.
		^~ relized it was missing a 5, so I copied one of the others.
	5/11/2021 AD/CE:
		~ changed replaced the `draw` function in someplaces to try and get a better understanding of virtual functions
	5/20/2021 AD/CE:
		+ added note
	5/25/2021 AD/CE:
		+ added notes
		+ added some stuff for ship movement

=========================
*/

#include "ship.h"

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/5hip.bmp"));//< `setTexture` method, of object `sprite_`, 
															  // of class `Sprite`, being passed the value of `getTexture` 
															  // method of the class at the address specified by the method 
															  // `GAME`(Game::instance() <<<(Why isn't `instance()` called 
															  // through dot notation and why does it have its definition in 
															  // the `Game.h` file instead of a .cpp file?)) when given an argument 
															  // of the value of file `ship.png`, located in folder `Resources`.
	sprite_.setPosition(sf::Vector2f(100, 100));
}

//void Ship::drawT()//<! Why can't I call the `draw` method of `getRenderWindow`  when I rename the `draw` methond of class`Ship` to `drawT`?
//				  //	^ Maybe it's not that `draw` isn't being called, but perhaps `sprite_` doesn't like the renaming.
//				  //	^ I mean the rename doesn't seem like it should cause any problems since the original body it would have over writen doesn't have any code
//				  //	^ investigate `Scene.cpp`
//				  //		^ investigate the indexing used to access the contents of `gameObjects_` list in `Scene.h` 
//				  //		  to see if virtual functions are being used to simplify member selection.  
void Ship::draw()
{ 
	GAME.getRenderWindow().draw(sprite_);//< At first I thought that this line was indexing to a function inside the `getRenderWindow()` 
										 // function (something that I'm not sure is even possible given the namespace restrictions and 
										 // limmited lifetime of data within functions), but after mousing over `getRenderWindow()` 
										 // and looking at it's description, It seems that this function is just providing a reference 
										 // to the RenderWindow which houses a `draw()` function.  I wonder why you can't just directly
										 // reference the `RenderWindow`. Maybe the OS desides the location of each new window created 
										 // so the engine can't automaticaly know... No, that doesn't seem right.  Does the engine need 
										 // to keep track of multipule windows? 

}	
const float SPEED = 0.3f;//< I was wondering what the "f" in "0.3f" was, and, from mousing 
						 // over the section before and after taking it away, with the f it seems that whatever the prossess that 
						 // creates float numbers, converts the 0.3 into 0.2999..., and those 9s go on for so long that 
						 // the number is stored as a double format.  The "f" prevents this somehow and results in the 0.3 
						 // being converted to something that can be stored in a regular float format.

void Ship::update(sf::Time elapsed)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//< Interesting how you can do operations with 
														// classes without instantiating them.
														// seems to work about the same as if you 
														// were using an instance of `Keyboard`, except that 
														// you use `::` to call methods instead of dot notation
	{
		x += SPEED * msElapsed;
	}

	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)71))// :)
	{
		x -= SPEED * msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		y -= SPEED * msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		y += SPEED * msElapsed;
	}
	//sprite_.setPosition(sf::Vector2f(x, y));//< this is how the position is set in the tutorial, but I don't see why they 
	//										  // don't just use the `pos` Vector2 `x` and `y` are already stored in.
	sprite_.setPosition(pos); //let's see why!
							  //^...
							  //	^Ok so neither of them work, must need to add something that was ommited.

}