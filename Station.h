class Station {

private:
    int number;
    int timeBetweenStations;

public:
    Station(int number, int timeBetweenStations)
        : number(number), timeBetweenStations(timeBetweenStations) {}

    int getNumber() { return number; }
    int getTimeBetweenStations() { return timeBetweenStations; }


};