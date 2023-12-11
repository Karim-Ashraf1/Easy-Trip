#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

void CheckIndex(string event);

int main()
{
    string event1 = "A NP 10:12 1 2 5";
    string event2 = "L 1 2";
    string event3 = "A NP 13:29 2 10 4";
    string event4 = "A SP 12:35 4 5 9 Pregnant";
    string event5 = "A WP 16:15 8 4 8";
}

void CheckIndex(const string event)
{
    string EventArr[event.length()];
    Passenger Pass1;
    if (event[0] == 'A')
    {
        EventArr[0] = "A";
        for (int i = 2; i < event.length(); i++)
        {
            if (event[i] == 'S')
            {
                EventArr[1] = "SP";
                Pass1.setType("SP");
                if (event[7] == "Pregnant")
                { // Pass1.setSPType("Pregnant"); // tbi
                    EventArr[6] = "Pregnant";
                }
                else if (event[7] == "Aged")
                { // Pass1.setSPType("Aged"); // tbi
                    EventArr[6] = "Aged";
                }
                else if (event[7] == "POD")
                { // Pass1.setSPType("POD"); // tbi
                    EventArr[6] = "POD";
                }
            }
            else if (event[i] == 'N')
            {
                EventArr[1] = "NP";
                Pass1.setType("NP");
            }
            else if (event[i] == 'W')
            {
                EventArr[1] = "WP";
                Pass1.setType("WP");
            }
        }
        // timestep --> tbi
        // Pass1.setid();
        EventArr[3] = event[12];
        // strtStation;
        EventArr[4] = event[14];
        // end station
        EventArr[5] = event[16];
    }
}
