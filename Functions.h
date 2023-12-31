#pragma once
#include "Time.h"
#include "Company.h"
using namespace std;




// conversion from string to integer 
int* ConvertToInt(string Array[])
{   
    int Arr[3];//to be implented using linked list
    for (int i = 0;i < 3;i++) {
        Arr[i] = stoi(Array[i]);
    }
    return Arr;
}








// Takes string and slices it by Space and returns an array converted to integer 
string* SplitString(string str)
{
    string word = "";
    string sentence[2];//to be implmentedby linked list
    int count = 0;
    for (auto x : str)
    {
        if (x == ' ')
        {
            sentence[count] = word;
            word = "";
            count++;
        }
        else {
            word = word + x;
        }
    }
    sentence[count] = word;
    return sentence;
}



    Time GetTimeFromString(const std::string*& timeStr2) {
        string timestr=*timeStr2;
        stringstream ss(timestr);
		int hours = 0, minutes = 0;
		char delimiter;
		if (ss >> hours >> delimiter >> minutes && delimiter == ':') {
			// Set the OFFTime attribute
			Time T(hours,minutes);
		}
		
	}
    int calculateTotalMinutes(const std::string*& timeStr2) 
    {   int totalMinutes;
        Time T= GetTimeFromString(timeStr2);
        totalMinutes=((T.getHours()*60)+T.getMinutes());
        return totalMinutes;
    }



int* CalcCapacity(const string& fileName){
// Use the ifstream object file to read the file
    ifstream file;
    string* FileArray;//to be changed to linked list
    // filename will store the name of the file and line_number the line number
    string filename=fileName;
    int line_number=6;
    int* Capacity;

    // Open the file with the provided filename
    file.open(filename);

    // If there was a failure opening the file (perhaps it does not exist) then
    // exit with an error message and status.
    if (file.fail())
    {
        cout << "File failed to open." << endl;
        return 0;
    }

    int current_line = 0;
    string line;

    // Continue to read the file one line at a time, unless we reach the end of 
    while (!file.eof())
    {
        // Increment the current line number being read as we are reading in the 
        current_line++;

        // Read the next line from the 'file' into the 'line' string 
        getline(file, line);

        // If current line number of the line we've read in matches the line number 
        // that we're looking for, use break to stop the loop
        if (current_line == line_number)
            Capacity=ConvertToInt(SplitString(line));//to be fixed when linked list
            return Capacity;
        }
}