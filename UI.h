#include <iostream>
#include <Passenger.h>
#include <Bus.h>
#include <Station.h>
#include <Events.h>
#include <LinkedQueue.h>
#include <PriorityQueue.h>
#include<Arrive.h>

class UI
{
private:
    int count_Sp;
    int count_np;
    int count_wp;
public:
    // setters
    void set_count_sp(int sp){count_Sp=sp;}
    void set_count_np(int np){count_np=np;}
    void set_count_wp(int wp){count_wp=wp;}

    // getters
    int get_count_sp(){return count_Sp;}
    int get_count_np(){return count_np;}
    int get_count_wp(){return count_wp;}
    
    
    void PrintOutput()
    {

    }
    void waitingpassengers()
    {
        Arrive;
    }
};