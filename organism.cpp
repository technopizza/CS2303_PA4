/*
 * organism.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: jconklin
 */

#include "organism.h"
#include <cstdlib>
/** constructor for organism
 * @param row organism row location
 * @param col organism col location
 */
Organism::Organism(int row, int col) {
	mRow = row;
	mCol = col;
}
/** sets organism row to given value
 * @param row integer for new row
 */
void Organism::setRow(int row) {
	mRow = row;
}
/** returns organism row
 * @return row
 */
int Organism::getRow() {
	return mRow;
}
/** sets organism col to given value
 * @param col integer for new col
 */
void Organism::setCol(int col) {
	mCol = col;
}
/** returns organism col
 * @return col
 */
int Organism::getCol() {
	return mCol;
}

void Organism::breed(World world) {
	int n = 0;
	Organism** neighbors = new Organism*[4];
	int* neighborX = new int[4];
	int* neighborY = new int[4];
	Organism* tmp;
	//Check bounds and if neighbor found at (col, row), if so, add to list of neighbors
	if (mCol > 0) { //check left bound
		tmp = world.getOrganism(mRow, mCol - 1); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			neighbors[n] = tmp;
			neighborX[n] = -1;
			neighborY[n] = 0;
			n++;
		}
	}
	if (mCol < world.getSize()) { //check right bound
		tmp = world.getOrganism(mRow, mCol + 1); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			neighbors[n] = tmp;
			neighborX[n] = 1;
			neighborY[n] = 0;
			n++;
		}
	}
	if (mRow > 0) { //check lower bound
		tmp = world.getOrganism(mRow - 1, mCol); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			neighbors[n] = tmp;
			neighborX[n] = 0;
			neighborY[n] = -1;
			n++;
		}
	}
	if (mRow < world.getSize()) { //check upper bound
		tmp = world.getOrganism(mRow + 1, mCol); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			neighbors[n] = tmp;
			neighborX[n] = 0;
			neighborY[n] = 1;
			n++;
		}
	}
	//randomly elect one of the neighbors
	int neighbor = (rand() % (n + 1));
	world.setOrganism(neighborY[n], neighborX[n], neighbor[n]);
}

void Organism::move(World world) {
	int n = 0;
	Organism** neighbors = new Organism*[4];
	int* neighborX = new int[4];
	int* neighborY = new int[4];
	Organism* tmp;
	//Check bounds and if neighbor found at (col, row), if so, add to list of neighbors
	if (mCol > 0) { //check left bound
		tmp = world.getOrganism(mRow, mCol - 1); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = -1;
			neighborY[n] = 0;
			n++;
		}
	}
	if (mCol < world.getSize()) { //check right bound
		tmp = world.getOrganism(mRow, mCol + 1); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = 1;
			neighborY[n] = 0;
			n++;
		}
	}
	if (mRow > 0) { //check lower bound
		tmp = world.getOrganism(mRow - 1, mCol); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = 0;
			neighborY[n] = -1;
			n++;
		}
	}
	if (mRow < world.getSize()) { //check upper bound
		tmp = world.getOrganism(mRow + 1, mCol); //get Organism at (row, col)
		if (!tmp) { //no organism at (row, col)
			//neighbors[n] = tmp;
			neighborX[n] = 0;
			neighborY[n] = 1;
			n++;
		}
	}
	//randomly elect one of the neighbors
	int neighbor = (rand() % (n + 1));
	Organism* null;
	world.setOrganism(neighborY[n], neighborX[n], this);
	world.setOrganism(mRow, mCol, null);
}
