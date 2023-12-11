#include <iostream>
#include <fstream>
#include <sstream>
#include "Events.h"
#include "Leave.h"
#include "Bus.h"
#include "Station.h"
#include "LinkedQueue.h"
#include "DoubleLinkedList.h"
#include "UI.h"
using namespace std;

class Company {
private:
    LinkedQueue <Events*> EventsList;
    DoubleLinkedList <Station*> StationsList;

public:

int StartProgram(ifstream& fileName)
{
    int FileArray[9];
    Arrive arival;
    Leave_Event Leaver;
    string ArrayArrive[9];
    string ArrayLeave[3];
    string ArrayOut[9];
    fstream ReadFile;
    string word, t, q, filename;

    // filename of the file
    filename = "filename.txt";

    // opening file
    ReadFile.open(filename.c_str());

    

    // extracting words from the file
	int i=0;
    while (ReadFile >> word)
    {
    	ArrayOut[i]=word;
        // displaying content
		i++;
    }

    if (ArrayOut[0] == "A")
    {
        arival.Execute(FileArray);
    }
    if (ArrayOut[0] == "L"){
        Leaver.Execute(FileArray);
    }

	ReadFile.close();
}

        // add events to EventsList

        // add buses to BusesList

    void simulateProgram() {
        // Execute the events that should be executed at that min

        // Move buses from available to moving to checkup to available again

        // Collect statistics that are needed to create output file

        // Calls UI class functions to print details on the output screen

    }

    void produceOutputFile() {
        // Generate the output file at the end of the simulation
    }
};