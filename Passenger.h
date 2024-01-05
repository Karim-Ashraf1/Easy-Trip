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
    int id;
    int startStation;
    int endStation;
    int priority;
    int OFFTime;
    int maxW;
    int arrival;
    int totalTrip;
    string type;
    string subtype;

public:
    // Constructors
    Passenger() : id(0), startStation(0), endStation(0), OFFTime(), maxW(00), arrival(00), totalTrip(00), type(" "), subtype("") {}

    Passenger(int id, int arrival, string type, int startStation, int endStation,int priority)
        : type(type), arrival(arrival), startStation(startStation), endStation(endStation), id(id),priority(priority) {}



    // Getter method for each attribute
    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    int getOFFTime() const { return OFFTime; }
    int getMaxWait() const { return maxW; }
    // int getWaitingTime() const { return OnTime.getMinutes() - arrival; }
    int getArrival() const { return arrival; }
    // int getTotalTrip() const { return OFFTime.getMinutes() - OnTime.getMinutes(); }
    int getWaitingTime() const { return OFFTime;}
    string getType() const { return type; }
    string getsubtype() const { return subtype; }



    // Setter method for each attribute
    void setId(int idx) { id = idx; }
    void setStartStation(int startStationx) { startStation = startStationx; }
    void setEndStation(int endStationx) { endStation = endStationx; }
    void setOFFTime(int getOFFTimex) { OFFTime = getOFFTimex; }

    void setMaxWTime(int maxw, const string &filename)
    {
        maxw = *(ConvertToInt(GetFileLine(filename, 5, 'O')));
        maxW = maxw;
    }











    // void setOnTimeFromString(const string &timeStr)
    // {
    //     std::stringstream ss(timeStr);
    //     int hours = 0, minutes = 0;
    //     char delimiter;

    //     if (ss >> hours >> delimiter >> minutes && delimiter == ':')
    //     {
    //         // Set the OnTime attribute
    //         OnTime.setHours(hours);
    //         OnTime.setMinutes(minutes);
    //     }
    // }

    // void setOFFTimeFromString(const string &timeStr)
    // {
    //     stringstream ss(timeStr);
    //     int hours = 0, minutes = 0;
    //     char delimiter;

    //     if (ss >> hours >> delimiter >> minutes && delimiter == ':')
    //     {
    //         // Set the OFFTime attribute
    //         OFFTime.setHours(hours);
    //         OFFTime.setMinutes(minutes);
    //     }
    // }
    void setType(const string &typex) { type = typex; }
    void setSubtype(const string &subtypex) { subtype = subtypex; }
};