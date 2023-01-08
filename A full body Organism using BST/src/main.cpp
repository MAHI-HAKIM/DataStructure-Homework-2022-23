/** 
* @file         main.cpp
* @description  main program to ReadFile and Perform all operation
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/


#include "TestProgram.hpp"

int main()
{
   TestProgram* fr = new TestProgram("veri.txt");
    fr->ReadFile();
    delete fr;
    return 0;

}