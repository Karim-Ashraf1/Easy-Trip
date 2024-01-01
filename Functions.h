#pragma once
#include "Company.h"
using namespace std;

void MoveBus(LinkedQueue<Bus*> &GarageQueue){
    LinkedQueue<Bus*>Moving_WBus;
    LinkedQueue<Bus*>Moving_Mbus;
    Bus* BussCheck;
    Bus* BussArray[2];
    while(!GarageQueue.isEmpty()){ 
        GarageQueue.dequeue(BussCheck);
        if (BussCheck->getType() == "WB"){
            Moving_WBus.enqueue(BussCheck);
        }
        if (BussCheck->getType() == "MB"){
            Moving_Mbus.enqueue(BussCheck);
        }
    }    
}


// conversion from string to integer 
int* ConvertToInt(string Array[])
{   
    int Arr[2];//to be implented using linked list
    for (int i = 0;i < 2;i++) {
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

string* GetFileLine(const string& fileName,int lineNum,char Functionality/*R to read from, O to read only this line*/)
{
    // Use the ifstream object file to read the file
    ifstream file;
    string* FileArray;//to be changed to linked list

    // filename will store the name of the file and line_number the line number
    string filename=fileName;
    int line_number=lineNum;

    // Open the file with the provided filename
    file.open(filename);

    // If there was a failure opening the file (perhaps it does not exist) then
    // exit with an error message and status.
    if (file.fail())
    {
        cout << "File failed to open." << endl;
        return;
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

    if (Functionality=='O'){
        // If current line number of the line we've read in matches the line number 
        // that we're looking for, use break to stop the loop
        if (current_line == line_number)
           // FileArray=ConvertToInt(SplitString(line));//to be fixed when linked list
            break;
        }
    if (Functionality=='R'){
        // If current line number of the line we've read in matches the line number 
        // that we're looking for, use break to stop the loop
        if (current_line >= line_number) {
            FileArray=SplitString(line); 
        }
    }
    }
    return FileArray;

}