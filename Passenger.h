#pragma once
#include <iostream>
#include <vector>


class Passenger {
private:
    int id;
    int startStation;
    int endStation;
    int getOnTime;
    int getOFFTime;
    std::string type;

public:
    // Constructors
    Passenger()
    {
        id=0;
       startStation=0;
       endStation=0;
       getOnTime=0;
       getOFFTime=0;
       type=" "; 
    } 
    Passenger(int idx, int startStationx, int endStationx, int getOnTimex, int getOFFTimex, std::string typex) 
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
    std::string getType() const { return type; }
    
    //Setter method for each attribute
    void setId(int idx) 
    { 
        id = idx; 
    }
    void setStartStation(int startStationx) 
    {
         startStation = startStationx; 
    }

    void setEndStation(int endStationx) 
    { 
        endStation = endStationx; 
    }
    void setGetOnTime(int getOnTimex) 
    {
         getOnTime = getOnTimex; 
    }
    void setGetOFFTime(int getOFFTimex) 
    { 
        getOFFTime = getOFFTimex; 
    }
    void setType(std::string typex) 
    {
         type = typex; 
    }



};