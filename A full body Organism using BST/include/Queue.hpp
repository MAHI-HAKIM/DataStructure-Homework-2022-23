#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;
template <typename Object>

class Queue
{
private:

	int Front;
	int Back;
	int Capacity;
	int LineSize;
	Object* Items;

	void Reserve(int _NewCapacity) 
	{
		Object* temp = new Object[_NewCapacity];

		for (int i = Front, j = 0; j < LineSize; j++)
		{
			temp[j] = Items[i];
			i = (i + 1) % Capacity;
		}
		Capacity = _NewCapacity;
		delete[] Items;
		Items = temp;
		Front = 0;
		Back = LineSize - 1;
	}
public:

	Queue() {
		Capacity = 1;
		Front = 0;
		Back = -1;
		LineSize = 0;
		Items = new Object[Capacity];
	}
	void clear()
	{
		Front = 0;
		Back = -1;
		LineSize = 0;
	}
	int count() const 
	{
		return LineSize;
	}
	bool isEmpty() const
	{
		if (LineSize == 0) return true;
		return false;
	}
	const Object& peek() 
	{
		if (isEmpty()) throw "Empty List";
		return Items[Front];
	}
	void enqueue(const Object& item)
	{
		if (LineSize == Capacity) Reserve(2 * Capacity);
		Back = (Back + 1) % Capacity;
		Items[Back] = item;
		LineSize++;
	}
	void dequeue() 
	{
		if (isEmpty()) throw "Empty List";
		Front = (Front + 1) % Capacity;
		LineSize--;
	}
	~Queue() {
		delete[] Items;
	}
};
#endif
