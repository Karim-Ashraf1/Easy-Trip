#pragma once
#include <iostream>
#include <vector>
#include "Time.h"  

class Passenger {
private:
    int id;
    int startStation;
    int endStation;
    int OnTime;
    int OFFTime;
    std::string type;
    std::string subtype;

public:
    // Constructors
    Passenger() : id(0), startStation(0), endStation(0), OnTime(), OFFTime(), type(" ") {}

    Passenger(int idx, int startStationx, int endStationx, int OnTimex, int OFFTimex, const std::string& typex)
        : id(idx), startStation(startStationx), endStation(endStationx), OnTime(OnTimex), OFFTime(OFFTimex), type(typex) {}

    // Getter method for each attribute
    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    int getOFFTime() const { return OFFTime; }
    int getOnTime() const { return OnTime; }
    std::string getType() const { return type; }
    std::string getsubtype() const { return subtype; }
    // Setter method for each attribute
    void setId(int idx) { id = idx; }
    void setStartStation(int startStationx) { startStation = startStationx; }
    void setEndStation(int endStationx) { endStation = endStationx; }
    void setOnTime(int getOnTimex) { OnTime = getOnTimex; }
    void setOFFTime(int getOFFTimex) { OFFTime = getOFFTimex; }
    void setType(const std::string& typex) { type = typex; }
    void setsubtype(const std::string& subtypex) { subtype = subtypex; }
};
