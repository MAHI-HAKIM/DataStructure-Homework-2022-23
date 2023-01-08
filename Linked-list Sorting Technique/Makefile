all: compile combine run
compile:
	g++ -I ./include/ -o ./lib/RowNode.o -c ./src/RowNode.cpp
	g++ -I ./include/ -o ./lib/Rowlist.o -c ./src/RowList.cpp
	g++ -I ./include/ -o ./lib/ManagerNode.o -c ./src/ManagerNode.cpp
	g++ -I ./include/ -o ./lib/ManagerList.o -c ./src/ManagerList.cpp
combine:
	g++ -I ./include/ -o ./bin/Program  ./lib/RowNode.o ./lib/RowList.o ./lib/ManagerNode.o ./lib/ManagerList.o ./src/main.cpp
run:
	./bin/program