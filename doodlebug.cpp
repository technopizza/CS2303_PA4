/*
 * Doodlebug.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: kdesrosiers
 */
#include "organism.h"
#include "doodlebug.h"
#include "world.h"
#include <cstdlib>

Doodlebug::Doodlebug(int row, int col) :
		Organism(row, col) {
	mBreedTime = 0;
	mStarveTime = 0;
}

bool Doodlebug::isPrey() {
	return false;
}
void Doodlebug::update(World world) {
	Organism * null;
	if (mStarveTime >= STARVE_TIME) {
		delete (world.getOrganism(mRow, mCol));
		world.setOrganism(mRow, mCol, null);
		return;
	} else {
		mStarveTime++;

	}
	if (mBreedTime >= BREED_TIME && Organism::breed(world)) {
		mBreedTime = 0;
	} else {
		mBreedTime++;
	}
}
void Doodlebug::move(World world) {
	Organism * null;
	int n = 0;
	int nPrey = 0;
	//Organism** neighbors = new Organism*[4];
	int* preyX = new int[4];
	int* preyY = new int[4];
	int* neighborX = new int[4];
	int* neighborY = new int[4];
	Organism* tmp;
	//Check bounds and if neighbor found at (col, row), if so, add to list of neighbors
	if (mCol > 0) { //check left bound
		tmp = world.getOrganism(mRow, mCol - 1); //get Organism at (row, col)
		if (tmp && tmp->isPrey()) {
			preyX[nPrey] = -1;
			preyY[nPrey] = 0;
			nPrey++;
		} else if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = -1;
			neighborY[n] = 0;
			n++;
		}
	}
	if (mCol < world.getSize()) { //check right bound
		tmp = world.getOrganism(mRow, mCol + 1); //get Organism at (row, col)
		if (tmp && tmp->isPrey()) { //no organism at (row, col)
				//neighbors[n] = tmp;
			preyX[nPrey] = 1;
			preyY[nPrey] = 0;
			nPrey++;
		} else if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = 1;
			neighborY[n] = 0;
			n++;
		}
	}
	if (mRow > 0) { //check lower bound
		tmp = world.getOrganism(mRow - 1, mCol); //get Organism at (row, col)

		if (tmp && tmp->isPrey()) { //no organism at (row, col)
				//neighbors[n] = tmp;
			preyX[nPrey] = 0;
			preyY[nPrey] = -1;
			nPrey++;
		} else if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = 0;
			neighborY[n] = -1;
			n++;
		}
	}
	if (mRow < world.getSize()) { //check upper bound
		tmp = world.getOrganism(mRow + 1, mCol); //get Organism at (row, col)
		if (tmp && tmp->getCol()) { //no organism at (row, col)
				//neighbors[n] = tmp;
			neighborX[nPrey] = 0;
			neighborY[nPrey] = 1;
			nPrey++;
		} else if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = 0;
			neighborY[n] = 1;
			n++;
		}
	}
	//randomly elect one of the neighbors
	int neighbor;

	if (nPrey) {
		neighbor = (rand() % (nPrey + 1));
		world.setOrganism(preyY[neighbor], preyX[neighbor], this);
		world.setOrganism(mRow, mCol, null);
	} else if (n) {
		neighbor = (rand() % (n + 1));
		world.setOrganism(neighborY[neighbor], neighborX[neighbor], this);
		world.setOrganism(mRow, mCol, null);
	}

}
