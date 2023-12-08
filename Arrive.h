#include<iostream> 
#include<Station.h>
#include<Passenger.h>
using namespace std;

class Arrival_Event{
private:
    bool A ; // means this is a LEAVE event line
    Passenger TYP ; // passenger type
    int ET ; // event timestep
    int ID ; // unique number to identifies each passenger
    Station STRT ; // start station of the passenger
    Station END; //  end station of the passenger
public:
    void Execute(){
        //to be implented later
    }
};