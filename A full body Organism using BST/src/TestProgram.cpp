/** 
* @file         TestProgram.cpp
* @description  Reads File and Perform Multiple Operation to Build Organism
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/


#include "TestProgram.hpp"
#include "System.hpp"
#include "Organism.hpp"
#include "Control.hpp"


TestProgram::TestProgram(string File)
{
    this->FileName = File;
    this->organs = new Organ[100];
    this->tissue = new Tissue[20];
    this->cell = new Cell();
    this->SystemIterator = 0;
    this->OrganIterator = 0;
    this->TissueIterator = 0;
    this->LineSize = 0;
    this->ArrayIterator = 0;
}
TestProgram::~TestProgram()
{
    delete[] organs;
    delete[] tissue;
    delete cell;
}
void TestProgram::ReadFile()
{
    ifstream file;
    string line = "";
    int chunk = 0;
    int LineCounter = 0;

    int FileLineSize = getFileSize();
    int SystemSize = FileLineSize / 2000;

   System* systems = new System[SystemSize];
   Organism* organisms = new Organism(); 

    file.open(FileName);

    if (!file.is_open())
    {
        cout << "File couldn't be opened!" << endl;
        return;
    }

    while (getline(file, line))
    {
        if (line.empty()) continue;  // If there is an empty line it will pass it 

        stringstream stream(line);

        LineSize = GetLineSize(line);

       tissue[TissueIterator].InitializeCellObject(LineSize);

        while (stream >> cell->DNA_Length)
        {
            tissue[TissueIterator].InsetIntoTissue(cell->DNA_Length, ArrayIterator);
            ArrayIterator++;
        }

        ArrayIterator = 0;

       tissue[TissueIterator].SortElementsInTissue();
 
       organs[OrganIterator].trees->Insert(tissue[TissueIterator].GetMidElement());

       TissueIterator++;
       LineCounter++;

        if (LineCounter % 20 == 0)
        {
            organs[OrganIterator].InitializeTissue(tissue);
            TissueIterator = 0;
            tissue = new Tissue[20];
            OrganIterator++;
        }

        if (LineCounter % 2000 == 0)
        {
            systems[SystemIterator].InsertOrganIntoSystem(organs);
            OrganIterator = 0;
            organs = new Organ[100];
            SystemIterator++;
        }
    }

    organisms->PerformMutation(systems,SystemSize);
    system("CLS");
    organisms->PrintOrganism();

    cout << endl << endl;

        if (cin.get() == '\n') {
            system("CLS");

            Control* control = new Control(organisms, SystemSize);
            control->PerformMutation();
            control->PrintinControl();
            cout << endl << endl;
            cout << "Press ENTER To Exit Program : ";
            delete control;
        }
        if (cin.get() == '\n') 
        {
            cout << endl;
            exit(0);
        }
}

//This finds out the size of the lineArray to be created
int TestProgram::GetLineSize(string line)
{
    stringstream stream(line);
    int chunk;
    int size = 0;
    while (stream >> chunk)
    {
        size++;
    }
    return size;
}

//This finds out the number of queues to be made from a file
int TestProgram::getFileSize()
{
    int size = 0;
    ifstream file(FileName);
    if (!file.is_open())
    {
        cout << "File couldn't be opened!" << endl;
        exit(0);
    }
    string line;
    while (getline(file, line))
    {
        size++;
    }
    return size;
}