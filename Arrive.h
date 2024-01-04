#pragma once
#include "Company.h"

class Arrive : public Events
{
    private:
        PriorityQueue<Passenger *> PassWait; // list of pointers to passengers
        string PassenegerType;
        int startStation;
        int endStation;

    public:
     Arrive(int Time, int Id, string PassenegerType, int startStation, int endStation)
        :Events(Time, Id),
        PassenegerType(PassenegerType), startStation(startStation - 1), endStation(endStation - 1) {}
        /// overloaded Excute() in Events class
        void Execute(Station *stationsArray)
        {
          /// Takes Attrubiutes of Arrive and sets the passenger instance by them
          Passenger* Psngr=new Passenger(Id,Time,PassenegerType,startStation, endStation);
          
          stationsArray[startStation]

           /// adding The passenger to linked list
        }
};