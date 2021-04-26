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
			to avoid this epigenetic mimicry, you could instead define the unique functions after the object is instantiated so they
		wouldn't have to be included in the class.  Though if the functions are going to be interacting with those within the class, 
		it would still need a presence in the class for them to reference.  This seems to be the purpose of virtual functions as they 
		provide a place holder for a function that will be defined later...  Though isn't that the job of function prototypes?  
		Couldn't you just define the methods after the object instantiation?  Maby if a prototype is used instead of a virtual function
		it would only accept one definition and you couldn't overwrite it later in the program... 
	
	Maintenance Log:
	---------------------------------
		4/26/2021 AD/CE:
			`ship.h`:
			+ created ship.h file
			+ added to notes
===================================
*/
#pragma once
