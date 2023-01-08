#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include <cmath>

class Radix {
private:
	int* Numbers;
	int* Sorted;
	int LineSize;
	int MaxStep;
	Queue<int>** queues;

	int MaxStepNumber();
	int power(int);
	int StepCount(int);
	int* QueueCurrentLengths();
public:
	Radix(int*,int);
	~Radix();
	void print();
	void ContainNumbers(int,int);
	int* Sort();
};

#endif //!Radix_HPP
