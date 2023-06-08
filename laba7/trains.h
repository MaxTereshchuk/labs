#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <msclr/marshal.h>
#include <time.h>

// Клас, що представляє рейс поїзда
class Train {
public:
    int trainNumber;
    std::string destination;
    std::string departureTime;

    Train();

    // Конструктор класу
    Train(int number, const std::string& dest, const std::string& time)
        : trainNumber(number), destination(dest), departureTime(time) {}

    int getTrainNumber() const {
        return trainNumber;
    }

    std::string getDestination() const {
        return destination;
    }

    std::string getDepartureTime() const {
        return departureTime;
    }
};



