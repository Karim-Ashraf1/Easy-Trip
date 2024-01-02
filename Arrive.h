#pragma once
#include "Time.h"
#include "Passenger.h"
#include "PriorityQueue.h"
#include "Events.h"
#include <String>
using namespace std;

class Arrive : public Events
{
    private:
        Passenger Psngr;// Creating a Passenger instance
        PriorityQueue<Passenger *> PassWait; // list of pointers to passengers

    public:
        /// overloaded Excute() in Events class
        void Execute(string* FileArray)
        {
          /// Takes Attrubiutes of Arrive and sets the passenger instance by them
          Psngr.setOnTime(*FileArray);         
          Psngr.setType(*(FileArray+1));            
          Psngr.setId(*(ConvertToInt(FileArray+3)));
          Psngr.setStartStation(*(ConvertToInt(FileArray+5)));
          Psngr.setEndStation(*(ConvertToInt(FileArray+5)));

          Passenger *psgr_ptr = &Psngr;
          PassWait.enqueue(psgr_ptr); /// adding The passenger to linked list
        }
};