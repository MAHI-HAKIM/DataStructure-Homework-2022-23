/** 
* @file         Radix.cpp
* @description  Performs Radix Sort
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "Radix.hpp"
#include "Cell.hpp"

int Radix::MaxStepNumber()
{
    int Max = 0;

    for (int i = 0; i < LineSize; i++) 
    {
        if (StepCount(Numbers[i]) > Max) 
            Max = StepCount(Numbers[i]);
    }
    return Max;
}
int Radix::StepCount(int Num)
{
    Num = abs(Num);
    int DecimalSize = 0;
    while (Num > 0) {
        DecimalSize++;
        Num /= 10;
    }
    return DecimalSize;
}

Radix::Radix(int * CellsElement , int length)
{
    this->Numbers = new int[length];
    this->LineSize = length;
    this->Sorted = new int[LineSize];

    for (int i = 0; i < LineSize; i++)
    {
        this->Numbers[i] = CellsElement[i];
    }

    queues = new Queue<int>*[10];

    for (int j = 0; j < 10; j++)
    {
        queues[j] = new Queue<int>();
    }

    MaxStep = MaxStepNumber();
}

void Radix::ContainNumbers(int TobeSorted,int itr)
{
        this->Numbers[itr] = TobeSorted;   
}

int* Radix::QueueCurrentLengths()
{
    int* lengths = new int[10];
    for (int i = 0; i < 10; i++)
    {
        lengths[i] = queues[i]->count();
    }
    return lengths;
}
int Radix::power(int e)
{
    int result = 1;
    for (int i = 0; i < e; i++) 
        result *= 10;
    return result;
}
int* Radix::Sort() {
    int numberIndex = 0;
    // read from array once and add to queues
    for (; numberIndex < LineSize; numberIndex++)
    {
        int stepValue = Numbers[numberIndex] % 10;

        int num = Numbers[numberIndex];

        queues[stepValue]->enqueue(num);
    }
    //i starting from 1 because of first digit processed
    for (int i = 1; i < MaxStep; i++) 
    {
        //get the current LineSize in all queues
        int* qlengths = QueueCurrentLengths();

        for (int index = 0; index < 10; index++)
        {
            int len = qlengths[index];
            for (; len > 0; len--) 
            {
                int number = queues[index]->peek();
                queues[index]->dequeue();
                int stepValue = (number / power(i)) % 10;
                queues[stepValue]->enqueue(number);
            }
        }
        delete[] qlengths;
    }

    numberIndex = 0;

    for (int index = 0; index < 10; index++) 
    {
        while (!queues[index]->isEmpty()) {
            int number = queues[index]->peek();
            Sorted[numberIndex++] = number;
            queues[index]->dequeue();
        }
    }
    return Sorted;
}
void Radix::print()
{
    for (int i = 0; i < LineSize; i++)
    {
        cout << Sorted[i] << " ";
    }
}
Radix::~Radix()
{
    delete[] Numbers;
    delete[] Sorted;
    for (int i = 0; i < 10; i++) delete queues[i];
    delete[] queues;
}
