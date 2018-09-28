/*
 * world.h
 *
 *  Created on: Sep 25, 2018
 *      Author: kdesrosiers
 */

#ifndef WORLD_H_
#define WORLD_H_
#include <iostream>
#include <cstdlib>
#include "organism.h"
class World {
private:
	//const int MAXSIZE;
	Organism **aWorld;
	int _gridSize;
	int _startNumAnts;
	int _startNumDoodles;
public:
	World(int space, int ants, int doodles);
	//function for displaying the board
	void displayTheworld();


	//function for checking if all cells are empty
	bool isWorldEmpty();

	//functions for starting and ending the game
	void playOne();

	//function to populate the board
	void populatetheWorld();

	int currentNumAnts();
	int currentNumDoodle();

	Organism* getOrganism(int row, int column);
	void setOrganism(int row, int columns, Organism* organism);

	//setters
	void setSizeOfBoard(int SIZE);
	void setStartamountOfAnts(int ANTS);
	void setStartamountOfDoodlebugs(int BUGS);

	//getters
	int getSize();

	//destructer
	~World();
};




#endif /* WORLD_H_ */
