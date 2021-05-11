/*
	file: ship.h
===============================
	Notes:
	--------------------
		> have a class serving as a frame work for objects.  each object needs to act a little different from each other. 
		If you placed each behaviorable difference in the class, and set each object's behavior by selecting what parts of 
		the class to use, every object would needlessly be carying all the data needed for all the other objects unique functionalities.
		Like how you can get a full genome from cells of different types, they would not only contain the information needed for their 
		own functionality, but for all the other member objects as well
			to avoid this epigenetic mimicry, you could instead create a new class for each varient of the frame work class, have each one
		inheirite everything from the base class, 
			^?(the pressence of "public" in the section of code "Ship : public GameObject" makes 
			  me question if "inheirite everything from the base class" is the right statement to put here.) 
		and then individualy add, 
		(or replace in cases when you want to overwrite virtual functions), the functions and variables needed for each class's unique 
		features in the body of their class definition.  
			
		Though if the functions are going to be interacting with those within the
		frame work class, it would still need a presence in the class for them to reference.  This seems to be the purpose of
		virtual functions as they provide a place holder for a function that will be defined later...  Though isn't that the job of 
		function prototypes?  Couldn't you just define the methods after the object instantiation?  
		Maby if a prototype is used instead of a virtual function it would only accept one definition and you couldn't overwrite 
		it later in the program... 

			^!? revaluate if the statement "you could instead define the unique functions after the object is instantiated..." is valid in
			this context.  Emphasis on "after the object is instantiated".

			^! the procedure described in the second paragraph would involve two classes, not a class and an object
				^~ amending in progress...

		>? Double colon (::) for specifying a namespace, single colon (:) for modifing namespace?
			^! single colon (:) to include a instantiating 

		virtual function overwriting:
				

		> instance variables: variables present in an object of a class that are unique to that object
			^ Are all variables stored within a class instance variables?
			^ I guess constants wouldn't change from object to object, so maby they're not instance variables.
			^ Is "unique" in this case refering to the a variable having a unique value or is it refering to variables declared in 
			an object that weren't declared in the parrent class, simmilar to how virtual functions can be redefined outside of 
			the parent class? The later of these seems more likely to me.

		> Class: a place to put functions and variables that can have verying levels of isolation from the rest of the code

	Maintenance Log:
	---------------------------------
		4/26/2021 AD/CE:
			`ship.h`:
			+ created ship.h file
			+ added to notes
		4/27/2021 AD/CE:
			+ added to notes
			+ started object `ship`
		4/28/2021 AD/CE:
			+ added to notes
			+ added to code
			~ capitalized things named `ship`
			! tried renameing ship.h to Ship.h and a popup said I couldn't because something with 
			that name already existed in it's location.
			+ added to notes
		5/3/2021 AD/CE:
			+ added to notes
		5/10/2021 AD/CE:
			~+ added to and modified notes section

===================================
*/

#pragma once
#include "Engine/GameEngine.h" //< `Engine/...` is needed as GameEngine.h isn't located in the same file as ship.h

class Ship : public GameObject
{
	public:
		Ship();
		void draw();

	private:
		sf::Sprite sprite_; //< The tutorial says that `sprite_` is a class instance and an instance variable. 
							//  Can something be considered a class and a variable?
							//	^ Well string seems to be a class since it has methods and we still consider it a type of variable.
};
typedef std::shared_ptr<Ship> ShipPtr; //

