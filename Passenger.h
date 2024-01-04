#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"
#include "Functions.h"
using namespace std;
#include "LinkedQueue.h"
#include "linkedlist.h"

class Passenger
{
private:
    LinkedList<Passenger*> waitingFNP;
	LinkedList<Passenger*> waitingBNP;
	PriorityQueue<Passenger*> waitingFSP;
	PriorityQueue<Passenger*> waitingBSP;
	LinkedQueue<Passenger*> waitingFWP;
	LinkedQueue<Passenger*> waitingBWP;


    int id;
    int startStation;
    int endStation;
    Time OnTime;
    Time OFFTime;
    int WaitingTime;
    int maxW;
    int arrival;
    int totalTrip;
    string type;
    string subtype;

public:
    // Constructors
    Passenger() : id(0), startStation(0), endStation(0), OnTime(), OFFTime(), WaitingTime(00), maxW(00), arrival(00), totalTrip(00), type(" "), subtype("") {}

    Passenger(int idx, int startStationx, int endStationx, Time OnTimex, Time OFFTimex, int waitingTime, int MaxW, int Arrival, int TotalTrip, string &typex, string &subtypex)
        : id(idx), startStation(startStationx), endStation(endStationx), OnTime(OnTimex), OFFTime(OFFTimex), WaitingTime(waitingTime), maxW(MaxW), arrival(Arrival), totalTrip(TotalTrip), type(typex), subtype(subtypex) {}

    Passenger( int id, int arrival,string type, int startStation, int endStation)
        : type(type), arrival(arrival), startStation(startStation), endStation(endStation), id(id){}

    // Getter method for each attribute
    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    Time getOnTime() const { return OnTime; }
    Time getOFFTime() const { return OFFTime; }
    int getMaxWait() const { return maxW; }
    int getWaitingTime() const { return OnTime.getMinutes() - arrival; }
    int getArrival() const { return arrival; }
    int getTotalTrip() const { return OFFTime.getMinutes() - OnTime.getMinutes(); }
    string getType() const { return type; }
    string getsubtype() const { return subtype; }
    // Setter method for each attribute
    void setId(int idx) { id = idx; }
    void setStartStation(int startStationx) { startStation = startStationx; }
    void setEndStation(int endStationx) { endStation = endStationx; }
    void setOnTime(Time getOnTimex) { OnTime = getOnTimex; }
    void setOFFTime(Time getOFFTimex) { OFFTime = getOFFTimex; }
    void setMaxWTime(int maxw, const string &filename)
    {
        maxw = *(ConvertToInt(GetFileLine(filename, 5, 'O')));
        maxW = maxw;
    }
    void setOnTimeFromString(const string &timeStr)
    {
        std::stringstream ss(timeStr);
        int hours = 0, minutes = 0;
        char delimiter;

        if (ss >> hours >> delimiter >> minutes && delimiter == ':')
        {
            // Set the OnTime attribute
            OnTime.setHours(hours);
            OnTime.setMinutes(minutes);
        }
    }

    void setOFFTimeFromString(const string &timeStr)
    {
        stringstream ss(timeStr);
        int hours = 0, minutes = 0;
        char delimiter;

        if (ss >> hours >> delimiter >> minutes && delimiter == ':')
        {
            // Set the OFFTime attribute
            OFFTime.setHours(hours);
            OFFTime.setMinutes(minutes);
        }
    }
    void setType(const string &typex) { type = typex; }
    void setSubtype(const string &subtypex) { subtype = subtypex; }

    
    

};