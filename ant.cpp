/*
 * Ant.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: kdesrosiers
 */
#include "organism.h"
#include "ant.h"

Ant::Ant(int row, int col) : Organism(row, col){
	mBreedTime = 0;
}

bool Ant::isPrey() {
	return true;
}
void Ant::update(World world){
	if (mBreedTime >= BREED_TIME && Organism::breed(world)){
		mBreedTime = 0;
	}
	else{
		mBreedTime++;
	}
}
