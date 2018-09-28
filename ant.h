/*
 * ant.h
 *
 *  Created on: Sep 27, 2018
 *      Author: jconklin
 */
#include "organism.h"
#ifndef ANT_H_
#define ANT_H_

class Ant : Organism{
private:
	int mBreedTime;
public:
	Ant(int row, int col);
};

#endif /* ANT_H_ */
