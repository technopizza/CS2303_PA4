/*
 * main.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: kdesrosiers
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//using namespace std;
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"
#include "world.h"



int main (int argc, char **argv) {
	int gridSize;
	int startNumDoodles;
	int startNumAnts;
	int timeSteps;
	int seed;
	int doPause;

	if (argc > 7) {
		cout << "Too many arguments!!" << endl;
		cout << "./PA4  gridSize  #doodleBugs  #ants  #timeSteps  seed  pause" << endl;
		return EXIT_FAILURE;
	}

	if (argc  >= 2) {
		gridSize = atoi(argv[1]);
	}
	if (argc >= 3) {
		startNumDoodles = atoi(argv[2]);
	}
	if (argc >= 4) {
		startNumAnts = atoi(argv[3]);
	}
	if (argc >= 5) {
		timeSteps = atoi(argv[4]);
	}
	if (argc >= 6) {
		seed = atoi(argv[5]);
	}
	if (argc == 7) {
		doPause = atoi(argv[6]);
	}
	//making the world
	World aWholeNewWorld = new World(gridSize, startNumAnts, startNumDoodles);
	aWholeNewWorld.displayTheworld();

	return 0;
}
