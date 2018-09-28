
/*
 * organism.h
 *
 *  Created on: Sep 27, 2018
 *      Author: jconklin
 */

class World;

#ifndef ORGANISM_H_
#define ORGANISM_H_


class Organism{
protected:
	int mRow;
	int mCol;
public:
	Organism(int row, int col);
	void setRow(int row);
	int getRow();
	void setCol(int col);
	int getCol();
	void move(World world);
	void breed(World world);
	bool isPrey();
};

#endif /* ORGANISM_H_ */
