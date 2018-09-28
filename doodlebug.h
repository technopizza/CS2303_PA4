/*
 * doodlebug.h
 *
 *  Created on: Sep 27, 2018
 *      Author: jconklin
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

class Doodlebug{
private:
	int breedTime;
	int starveTime;
public:
	Doodlebug(int row, int col);
	void starve();
};

#endif /* DOODLEBUG_H_ */
