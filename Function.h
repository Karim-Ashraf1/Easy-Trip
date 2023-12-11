#include <cstdlib> 
#include <iostream> 
#include <LinkedQueue.h>
using namespace std;

template<typename T>
void RandomEvent(LinkedQueue<T>* EventQueue)
{
    int UpperBound = 100;
    int LowerBound = 1;
    int random = (rand() % (UpperBound-LowerBound + 1)) + LowerBound;
    if(random <=25 )
        // move to SP passenger to the finish list
    if(random >= 35 && random <= 45)
        // move to WP passenger to the finish list
    if(random >= 50 && random <= 60)
        // move to NP passenger to the finish list
}