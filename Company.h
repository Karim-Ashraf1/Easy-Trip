#include <iostream>
#include <Events.h>
#include <Bus.h>
#include <Station.h>
#include<LinkedList.h>
#include <UI.h>
using namespace std;

class Company {
private:
    LinkedList<Events*> EventsList;
    LinkedList<Bus*> BusesList;
    LinkedList<Station*> StationsList;
    string InputFile;
    string OutputFile;

public:
    Company(string& inputFile, string& outputFile)
        : InputFile(inputFile), OutputFile(outputFile) {}

    void StartProgram() {
        // read the file

        // add events to EventsList

        // add buses to BusesList
    }

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