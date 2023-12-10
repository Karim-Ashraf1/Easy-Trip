#pragma once
#include <iostream>
#include <vector>
#include "Time.h"  

class Passenger {
private:
    int id;
    int startStation;
    int endStation;
    Time OnTime;
    Time OFFTime;
    std::string type;

public:
    // Constructors
    Passenger() : id(0), startStation(0), endStation(0), OnTime(), OFFTime(), type(" ") {}

    Passenger(int idx, int startStationx, int endStationx, const Time& OnTimex, const Time& OFFTimex, const std::string& typex)
        : id(idx), startStation(startStationx), endStation(endStationx), OnTime(OnTimex), OFFTime(OFFTimex), type(typex) {}

    // Getter method for each attribute
    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    Time getOFFTime() const { return OFFTime; }
    Time getOnTime() const { return OnTime; }
    std::string getType() const { return type; }
    
    // Setter method for each attribute
    void setId(int idx) { id = idx; }
    void setStartStation(int startStationx) { startStation = startStationx; }
    void setEndStation(int endStationx) { endStation = endStationx; }
    void setOnTime(const Time& getOnTimex) { OnTime = getOnTimex; }
    void setOFFTime(const Time& getOFFTimex) { OFFTime = getOFFTimex; }
    void setType(const std::string& typex) { type = typex; }
};
