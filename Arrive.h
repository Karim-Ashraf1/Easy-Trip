#pragma once
#include "Time.h"
#include "Passenger.h"
#include "PriorityQueue.h"
#include<Events.h>
using namespace std;


class Arrive : public Events
{
private:
    Passenger Psngr ; // Creating a Passenger instance 
    Time On; // Setting the on time for the passenger
    Time Off; // Setting the off time for the passenger
    int ID ; // Unique number that identifies each passenger
    int StartStation ; // Shows the starting station
    bool A; // true if an arrival has been activated
    int EndStation ; // Shows the ending station
    int OnTime ; // Shows the time of the passenger getting on th bus
    int OffTime ; // Shows the time the passenger gets off the bus
    string Type ; // The type of passenger
    PriorityQueue<Passenger*> appropiate ; //list of pointers to passengers 

public:

    /// setters for all attrubiutes of arrive(which will be used to set the attributes of passenger)
    void SetID(int id){ID=id;}
    void SetStartStation(int start){StartStation=start;}
    void SetEndStation(int End){EndStation=End;}
    void SetOnTime(int on_time){OnTime=on_time;}
    void SetOffTime(int Off_time){OffTime=Off_time;}
    void SetType(string type){Type=type;}


    /// getters for all attrubiutes of arrive(which are for passenger)
    int GetID() const {return ID;}
    int GetStartStation()const {return StartStation;}
    int GetEndStation() const {return EndStation;}
    int GetOnTime() const {return OnTime;}
    int GetOffTime() const {return OffTime;}
    string GetType() const {return Type;}


    /// overloaded Excute() in Events class
    void Execute()
    {

        /// Takes Attrubiutes of Arrive and sets the passenger instance by them 
        Psngr.setId(ID);
        Psngr.setStartStation(StartStation);
        Psngr.setEndStation(EndStation);
        Psngr.setOFFTime( On);
        Psngr.setOnTime(Off);
        Psngr.setType(Type);

        Passenger *psgr_ptr=&Psngr;

        appropiate.enqueue(psgr_ptr); /// adding The passenger to linked list
    }
    
};