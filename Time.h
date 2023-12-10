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