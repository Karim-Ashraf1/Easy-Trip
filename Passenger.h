#include <iostream>
#include <vector>
using namespace std;

class Passenger {
private:
    int id;
    int startStation;
    int endStation;
    int getOnTime;
    int getOFFTime;
    string type;

public:
    // Constructor 
    Passenger(int id, int startStation, int endStation, int getOnTime, int getOFFTime;, string type)
        : id(id), startStation(startStation), endStation(endStation), getOnTime(getOnTime), getOFFime(getOFFTime) type(type) {}

    // Getter method for each attribute
    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    int getGetOnOffTime() const { return getOnOffTime; }
    string getType() const { return type; }




};