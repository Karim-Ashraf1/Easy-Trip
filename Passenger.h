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
    Passenger(int idx, int startStationx, int endStationx, int getOnTimex, int getOFFTimex, string typex) 
    {
       id=idx;
       startStation=startStationx;
       endStation=endStationx;
       getOnTime=getOnTimex;
       getOFFTime=getOFFTimex;
       type=typex; 


    }

    // Getter method for each attribute
    int getId() const { return id; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    int getOFFTime() const { return getOFFTime; }
    int getOnTime() const { return getOnTime; }
    string getType() const { return type; }




};