/*
 * world.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: kdesrosiers
 */

#include <iostream>
using std::cout;
using std::endl;
#include <cstdlib>
#include "world.h"
#include "ant.h"
#include "doodlebug.h"
#include "organism.h"

/**Constructor for the world, fills it with nulls.
 *
 */

World::World(int space, int ants, int doodles) {
	_startNumAnts = ants;
	_startNumDoodles = doodles;
	_gridSize = space;
	int i;
	aWorld = new Organism*[_gridSize];
	for (i = 0; i < _gridSize; i++) {
		aWorld[i] = new Organism[_gridSize];
	}

}

/**this function fills the world with ants and doodlebugs randomly
 */
void World::populatetheWorld() {
	int countAnts;
	int countDoodle;
	// fill the world with ants
	for(countAnts = 0; countAnts < _startNumAnts; countAnts++) {
		int i = rand() % _gridSize;
		int j = rand() % _gridSize;
		if (aWorld[i][j] == NULL) {
			countAnts++;
			new Ant(i, j);
		}
	}
	for (countDoodle = 0; countDoodle < _startNumDoodles; countDoodle++) {
		int x = rand() % _gridSize;
		int y = rand() % _gridSize;
		if (aWorld[x][y] == NULL) {
			countDoodle++;
			new Doodlebug(x, y);
		}
	}
}


/**This function displays the world
 *
 */
void World::displayTheworld() {
	for (int i = 0; i < _gridSize; i++) {
		for (int j = 0; j < _gridSize; j++) {
			Organism* tmp = aWorld[i][j];
			if ((tmp != NULL) && (tmp->isPrey())) {
				cout << 'o ';
			}
			if ((tmp != NULL) && !(tmp->isPrey())) {
				cout << 'x ';
			}
			if (tmp == NULL) {
				cout << '  ';
			}
		}
	}
}

/**checks to see if the world is empty
 * @return true if the world is empty, and false if not
 */
bool World::isWorldEmpty() {
	int numEmpty = 0;
	int numCells = 0;
	for (int i = 0; i < _gridSize; i++) {
		for (int j =0; j < _gridSize; j++) {
			numCells++;
			if (aWorld[i][j] == NULL) {
				numEmpty++;
			}
			if (numEmpty == numCells) {
				return true;
			}
		}
	}
	return false;
}

/** setter for size of world
 * @param SIZE passed in size of board
 */
void World::setSizeOfBoard(int SIZE) {
	_gridSize = SIZE;
}

/** setter for number of ants
 * @param ANTS passed in number of ants
 */
void World::setStartamountOfAnts(int ANTS) {
	_startNumAnts = ANTS;
}

/** setter for number of doodlebugs
 * @param BUGS passed in number of doodlebugs
 */
void World::setStartamountOfDoodlebugs(int BUGS) {
	_startNumDoodles = BUGS;
}

/** returns the size of the board
 * @return size
 */
int World::getSize() {
	return _gridSize;
}





/** finds the current number of ants on the board
 * @return the number of ants
 */
int World::currentNumAnts() {
	int x;
	Organism* tmp;
	for (int i = 0; i < _gridSize; i++){
		for (int j = 0; j < _gridSize; j++) {
			if ((tmp != NULL) && (tmp -> isPrey())) {
				x++;
			}
		}
	}
	return x;
}


/** finds the current number of doodleBugs on the board
 * @return the number of doodleBugs
 */
int World::currentNumDoodle() {
	int x;
	Organism* tmp;
	for (int i = 0; i < _gridSize; i++){
		for (int j = 0; j < _gridSize; j++) {
			if ((tmp != NULL) && !(tmp -> isPrey())) {
				x++;
			}
		}
	}
	return x;
}


/** plays one round of the game
 *
 *
 */
/*void world::playOne() {
	// move every doodlebug
}*/

Organism* World::getOrganism(int row, int column) {
	Organism* x = new Organism(row, column);
	//= aWorld[row][column];
	return x;
}

void World::setOrganism(int row, int column, Organism * t) {
	aWorld[row][column] = t;
}
