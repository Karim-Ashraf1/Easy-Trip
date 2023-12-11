#pragma once
#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
      Time()
    {
        int hours = 0;
        int minutes = 0;
        int secound = 0;
    }

    Time(int h, int m, int s)
    {
        int hours = h;
        int minutes = m;
        int secound = s;
    }
    void toString(){
        cout<<hours<<":"<<minutes<< "/n";
    }
    
    Time& operator=(const Time& other) {
        if (this != &other) {
            hours = other.hours;
            minutes = other.minutes;
            seconds = other.seconds;
        }
        return *this;
    }
    Time operator/(const Time& otherTime) const {
    // Convert both times to seconds
    int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
    int totalSeconds2 = otherTime.hours * 3600 + otherTime.minutes * 60 + otherTime.seconds;

    // Avoid division by zero
    if (totalSeconds2 == 0) {
        std::cerr << "Error: Division by zero!\n";
        // Return a default-constructed Time object
        return Time();
    }

    int resultSeconds = totalSeconds1 / totalSeconds2;

    // Calculate new hours, minutes, and seconds for the result
    Time resultTime;
    resultTime.hours = resultSeconds / 3600;
    resultTime.minutes = (resultSeconds % 3600) / 60;
    resultTime.seconds = resultSeconds % 60;

    return resultTime;
}

    Time operator-(const Time& otherTime) const {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = otherTime.hours * 3600 + otherTime.minutes * 60 + otherTime.seconds;

        int differenceSeconds = totalSeconds1 - totalSeconds2;

        // Calculate new hours, minutes, and seconds for the difference
        Time result;
        result.hours = differenceSeconds / 3600;
        result.minutes = (differenceSeconds % 3600) / 60;
        result.seconds = differenceSeconds % 60;

        return result;
    }

    Time simulateTimePassage(const Time &currentTime, int secondsPassed)
    {
        Time newTime = currentTime;

        // Convert everything to seconds and add the simulated time passage
        int totalSeconds = currentTime.hours * 3600 + currentTime.minutes * 60 + currentTime.seconds + secondsPassed;

        // Calculate new hours, minutes, and seconds
        newTime.hours = totalSeconds / 3600 % 24;
        newTime.minutes = (totalSeconds % 3600) / 60;
        newTime.seconds = totalSeconds % 60;

        return newTime;
    }
};