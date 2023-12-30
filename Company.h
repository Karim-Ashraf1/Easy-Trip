#pragma once
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
    LinkedQueue<Bus*> GarageQueue;
public:

    // conversion from string to integer 
    int* ConvertToInt(string Array[], int size)
    {   
        int Arr[2];
        for (int i = 0;i < size;i++) {
            Arr[i] = stoi(Array[i]);
        }
        return Arr;
    }

    // Takes string and slices it by Space and returns an array converted to integer 
    int* StoreBusToGarage(string str)
    {
        string word = "";
        string sentence[2];
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
        int* FinalArrayPtr=ConvertToInt(sentence, 2);
        return FinalArrayPtr;
    }




    // function to Enque busess to a queue according to their number from the inout file
    LinkedQueue<Bus*> EnqueueGarage(const string& fileName)
    {
        ifstream file;
        string filename="file.txt";
        int current_line=0;
        string line;
        LinkedQueue<Bus*> BusQueue;
        LinkedList<Bus*> WBusList;
        LinkedList<Bus*> MBusList;
        int* BussesNumber;
        int counter=0;

        file.open(filename);
        if (file.fail())
        {
            cout <<"Failed";
            return;
        }
        while(!file.eof())
        {
            current_line++;
            getline(file,line);
            if (current_line == 2)break;
        }
    BussesNumber= StoreBusToGarage(line);
    //  functions to create objects according to number of busses available
        for (int i=0; i < *(BussesNumber); i++)
        {
            Bus *MixedBus = new Bus ();
            MixedBus->setdirection('F');
            MixedBus->setId(i);
            MixedBus->setType("MB");
            WBusList.InsertEnd(MixedBus);
        }

        for (int i=0; i < *(BussesNumber+1); i++)
        {
            Bus *WheelChairBus = new Bus ();
            WheelChairBus->setdirection('F');
            WheelChairBus->setId(i);
            WheelChairBus->setType("WB");
            WBusList.InsertEnd(WheelChairBus);
        }

        bool W=false;
        bool M=false;
        do
        {   
            if(MBusList.FindByIndex(counter))
            {
                M=true;
            }
            if(WBusList.FindByIndex(counter))
            {
                W=true;
            }
            if (W && M)
            {
                BusQueue.enqueue(WBusList.FindByIndex(counter));
                BusQueue.enqueue(MBusList.FindByIndex(counter));
                counter ++;
            }
            if (W && !MBusList.FindByIndex(counter))
            {
                M=false;
                BusQueue.enqueue(WBusList.FindByIndex(counter));
                counter ++;
            }
            if (M && !WBusList.FindByIndex(counter))
            {
                W=false;
                BusQueue.enqueue(MBusList.FindByIndex(counter));
                counter ++;
            }

        }while(W || M);
    //    NpBusQueue.enqueue(BussesNumber+1);// to be solved later
        
    }
        Arrive arival;
        Leave_Event Leaver;
        string ArrayArrive[6];
        string ArrayLeave[3];
        string ArrayOut[6];
        ifstream ReadFile;
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
    };
        