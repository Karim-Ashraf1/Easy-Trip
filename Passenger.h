#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"
#include "Functions.h"
using namespace std;

class Passenger
{
private:
    int id;
    int startStation;
    int endStation;
    int OnTime;
    int OFFTime;
    int WaitingTime;
    int maxW;
    string type;
    string subtype;

public:
    // Constructors
    Passenger() : id(0), startStation(0), endStation(0), OnTime(00), OFFTime(00), WaitingTime(00), maxW(00), type(" "), subtype("") {}

    Passenger(int idx, int startStationx, int endStationx, int OnTimex, int OFFTimex, int waitingTime, int MaxW, string &typex, string &subtypex)
        : id(idx), startStation(startStationx), endStation(endStationx), OnTime(OnTimex), OFFTime(OFFTimex), WaitingTime(waitingTime), maxW(MaxW), type(typex), subtype(subtypex) {}

    // Getter method for each attribute
    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    int getOnTime() const { return OnTime; }
    int getOFFTime() const { return OFFTime; }
    string getType() const { return type; }
    string getsubtype() const { return subtype; }
    // Setter method for each attribute
    void setId(int idx) { id = idx; }
    void setStartStation(int startStationx) { startStation = startStationx; }
    void setEndStation(int endStationx) { endStation = endStationx; }
    void setOnTime(int getOnTimex) { OnTime = getOnTimex; }
    void setOFFTime(int getOFFTimex) { OFFTime = getOFFTimex; }
    void setMaxWTime(int maxw, const string &filename)
    {
        maxw = GetFileLine(filename, 5, 'O');
    }
    void setWaitingTime(int wait) { ; }
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