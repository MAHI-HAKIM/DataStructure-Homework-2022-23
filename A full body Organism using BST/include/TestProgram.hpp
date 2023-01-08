#ifndef TESTPROGRAM_HPP
#define TESTPROGRAM_HPP

#include "Cell.hpp"
#include "Organ.hpp"

class TestProgram
{
public:

	TestProgram(string);
	~TestProgram();
	void ReadFile();

private:
	int LineSize;
	int TissueIterator;
	int OrganIterator;
	int SystemIterator;
	int ArrayIterator;

	string FileName;
	Cell* cell;
	Organ* organs;
	Tissue* tissue;

	int GetLineSize(string);
	int getFileSize();
};

#endif // !TESTPROGRAM_HPP
