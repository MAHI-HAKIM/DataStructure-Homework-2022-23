all: compile combine run

compile:
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/Cell.o -c ./src/Cell.cpp
	g++ -I ./include/ -o ./lib/TestProgram.o -c ./src/TestProgram.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/Organism.o -c ./src/Organism.cpp
	g++ -I ./include/ -o ./lib/System.o -c ./src/System.cpp
	g++ -I ./include/ -o ./lib/Tissue.o -c ./src/Tissue.cpp
	g++ -I ./include/ -o ./lib/Organ.o -c ./src/Organ.cpp
	g++ -I ./include/ -o ./lib/Control.o -c ./src/Control.cpp

combine:
	g++ -I ./include/ -o ./bin/Program  ./lib/BST.o ./lib/Cell.o ./lib/TestProgram.o ./lib/Node.o ./lib/Organism.o ./lib/Radix.o ./lib/System.o  ./lib/Tissue.o ./lib/Organ.o ./lib/Control.o ./src/main.cpp

run:
	./bin/Program