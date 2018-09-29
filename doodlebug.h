/*
 * doodlebug.h
 *
 *  Created on: Sep 27, 2018
 *      Author: jconklin
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

class Organism;
class World;

class Doodlebug : Organism{
private:
	int mBreedTime;
	int mStarveTime;
	static const int BREED_TIME = 8;
	static const int STARVE_TIME = 3;
public:
	Doodlebug(int row, int col);
	bool isPrey();
	void move(World world);
	void update(World world);
	};
#endif /* DOODLEBUG_H_ */
