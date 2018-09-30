/*
 * Ant.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: kdesrosiers
 */
#include "organism.h"
#include "ant.h"
/** constructor for Ant; invokes superclass constructor
 * @param row organism row location
 * @param col organism col location
 * @return new D object
 */
Ant::Ant(int row, int col) : Organism(row, col){
	mBreedTime = 0;
}
/** determines if Ant is prey
 * @return boolean corresponding to prey status
 */
bool Ant::isPrey() {
	return true;
}
/** Updates status of Ant in world; checks for breeding
 * @param world the world in which to manipulate the organism
 */
void Ant::update(World world){
	if (mBreedTime >= BREED_TIME && Organism::breed(world)){
		mBreedTime = 0;
	}
	else{
		mBreedTime++;
	}
}
