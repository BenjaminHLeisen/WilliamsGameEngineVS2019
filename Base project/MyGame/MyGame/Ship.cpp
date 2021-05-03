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



=========================
*/

#include "ship.h"

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);//< At first I thought that this line was indexing to a function inside the `getRenderWindow()` 
										 // function (something that I'm not sure is even possible), but after mousing over `getRenderWindow()` 
										 // and looking at it's description, It seems that this function is just providing a reference to the 
										 // RenderWindow which houses a `draw()` function.  I wonder why you can't just directly reference the
										 //`RenderWindow`. Maybe the OS desides the location of each new window created so the engine can't 
										 // automaticaly know... No, that doesn't seem right.  Does the engine need to keep track of multipule
										 // windows? 
}										 