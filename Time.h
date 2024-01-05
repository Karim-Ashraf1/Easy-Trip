#pragma once
#include <iostream>

class Time {
private:
    int hours;
    int minutes;

public:
    Time() : hours(0), minutes(0) {}

    void setHours(int h)
    {
        hours = h;
    }

    void setMinutes(int m) {
        minutes = m;
    }

    Time(int h, int m) : hours(h), minutes(m) {}
    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }
    void toString() {
        std::cout << hours << ":" << minutes << "\n";
    }

    Time& operator=(const Time& other) {
        if (this != &other) {
            hours = other.hours;
            minutes = other.minutes;
        }
        return *this;
    }

    Time operator/(const Time& otherTime) const {
        int totalMinutes1 = hours * 60 + minutes;
        int totalMinutes2 = otherTime.hours * 60 + otherTime.minutes;

        if (totalMinutes2 == 0) {
            std::cerr << "Error: Division by zero!\n";
            return Time();
        }

        int resultMinutes = totalMinutes1 / totalMinutes2;

        Time resultTime;
        resultTime.hours = resultMinutes / 60;
        resultTime.minutes = resultMinutes % 60;

        return resultTime;
    }

    Time operator*(int multiplier) const {
        int totalMinutes = hours * 60 + minutes;
        totalMinutes *= multiplier;

        Time resultTime;
        resultTime.hours = totalMinutes / 60;
        resultTime.minutes = totalMinutes % 60;

        return resultTime;
    }

    Time operator-(const Time& otherTime) const {
        int totalMinutes1 = hours * 60 + minutes;
        int totalMinutes2 = otherTime.hours * 60 + otherTime.minutes;

        int differenceMinutes = totalMinutes1 - totalMinutes2;

        Time result;
        result.hours = differenceMinutes / 60;
        result.minutes = differenceMinutes % 60;

        return result;
    }

    Time operator+(const Time& otherTime) const {
        int totalMinutes1 = hours * 60 + minutes;
        int totalMinutes2 = otherTime.hours * 60 + otherTime.minutes;

        int totalMinutes = totalMinutes1 + totalMinutes2;

        Time result;
        result.hours = totalMinutes / 60;
        result.minutes = totalMinutes % 60;

        return result;
    }

    Time operator*(int multiplier) const {
        int totalMinutes = hours * 60 + minutes;
        totalMinutes *= multiplier;

        Time resultTime;
        resultTime.hours = totalMinutes / 60;
        resultTime.minutes = totalMinutes % 60;

        return resultTime;
    }

    Time simulateTimePassage(int minutesPassed) const {
        Time newTime = *this;

        int totalMinutes = hours * 60 + minutes + minutesPassed;

        newTime.hours = totalMinutes / 60 % 24;
        newTime.minutes = totalMinutes % 60;

        return newTime;
    }


    void addMinute() 
    {
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            hours = (hours + 1) % 24;
        }
    }

    int calculateTotalMinutes() 
    {   int totalMinutes;
        
        totalMinutes=(hours*60+minutes);
        return totalMinutes;
    }

    Time convertTotalMinutesToTime(int totalMinutes) {
    Time resultTime;

    // Calculate hours and minutes
    resultTime.setHours(totalMinutes / 60 % 24);
    resultTime.setMinutes(totalMinutes % 60);

    return resultTime;
}
};
