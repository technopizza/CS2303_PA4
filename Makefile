CFLAGS = -g -Wall

all: PA4

PA4: main.o ant.o doodlebug.o organism.o world.o
 	g++ $(CFLAGS) main.o organism.o ant.o doodlebug.o world.o
main.o: main.cpp organism.h ant.h doodlebug.h world.h
	g++ $(CFLAGS) -c main.cpp
ant.o: ant.cpp ant.h
	g++ $(CFLAGS) -c ant.cpp
doodlebug.o: doodlebug.cpp doodlebug.h
	g++ $(CFLAGS) -c doodlebug.cpp
organism.o: organism.cpp organism.h world.h
	g++ $(CFLAGS) -c organism.cpp
world.o: world.cpp organism.h ant.h doodlebug.h world.h
	g++ $(CFLAGS) -c world.cpp
clean:
 	rm -f *.o PA4
 	rm -f -r html latex
docs:
	doxygen