#include <iostream>
using namespace std;


class Time {


private:
    int hours;
    int minutes;

public:
    Time(int hours, int minutes) : hours(hours), minutes(minutes) {}

    int getHours() { return hours; }
    int getMinutes() { return minutes; }

    void setHours(int h) { hours = h; }
    void setMinutes(int m) { minutes = m; }

    void printTime() const {
        std::cout << hours << ":" << minutes;
    }
};    