#include <iostream>
#include <fstream>
#include <sstream>
#include "Events.h"
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
    void ReadFile(const string& filename, vector<vector<string>>& InputList) {
        // Open the file
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        // Read lines from the file
        string line;
        while (getline(file, line)) {
            // Split the line into words
            istringstream iss(line);
            vector<string> words;
            string word;
            while (iss >> word) {
                words.push_back(word);
            }

            // Add the vector of words to InputList
            InputList.push_back(words);
        }

        // Close the file
        file.close();

        // print result
        for (const auto& line : InputList) {
        for (const auto& word : line) {
            cout << word << " ";
            }
        cout << endl;
        }
    }

    void StartProgram() {
        // read the file
       void StartProgram(ifstream& fileName,string ArrayOut[])
{
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
	ReadFile.close();
}

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