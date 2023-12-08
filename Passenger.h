#include <iostream>
#include <vector>
using namespace std;

class Passenger {

private:
    int id;
    int startStation;
    int endStation;
    int getOnOffTime;
    string type;

public:
    Passenger(int id, int startStation, int endStation, int getOnOffTime, string type)
        : id(id), startStation(startStation), endStation(endStation), getOnOffTime(getOnOffTime), type(type) {}

    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    int getGetOnOffTime() const { return getOnOffTime; }
    string getType() const { return type; }


};