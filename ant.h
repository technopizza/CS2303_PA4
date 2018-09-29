
/*
 * ant.h
 *
 *  Created on: Sep 27, 2018
 *      Author: jconklin
 */
#ifndef ANT_H_
#define ANT_H_

class Organism;
class World;

class Ant : Organism{
private:
	int mBreedTime;
	static const int BREED_TIME = 3;
public:
	Ant(int row, int col);
	bool isPrey();
	void update(World world);

};

#endif /* ANT_H_ */
