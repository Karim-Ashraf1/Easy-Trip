#include <iostream>
#include <iomanip>
#include <thread>  // for std::this_thread::sleep_for
#include <chrono>  // for std::chrono::seconds

struct Time {
    int hours;
    int minutes;
    int seconds;
};

Time simulateTimePassage(const Time& currentTime, int secondsPassed) {
    Time newTime = currentTime;

    // Convert everything to seconds and add the simulated time passage
    int totalSeconds = currentTime.hours * 3600 + currentTime.minutes * 60 + currentTime.seconds + secondsPassed;

    // Calculate new hours, minutes, and seconds
    newTime.hours = totalSeconds / 3600 % 24;
    newTime.minutes = (totalSeconds % 3600) / 60;
    newTime.seconds = totalSeconds % 60;

    return newTime;
}
