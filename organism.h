
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
	bool breed(World world);
public:
	Organism(int row, int col);
	void setRow(int row);
	int getRow();
	void setCol(int col);
	int getCol();
	void update(World world);
	bool isPrey();
	void move(World world);
};

#endif /* ORGANISM_H_ */
