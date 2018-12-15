//
// Created by admin on 19-Nov-18.
//

#include "Result.h"

int Result::getIndex() const {
    return index;
}

void Result::setIndex(int index) {
    Result::index = index;
}

double Result::getDistance() const {
    return distance;
}

void Result::setDistance(double distance) {
    Result::distance = distance;
}

double Result::getElapsedTimeMs() const {
    return elapsedTimeMs;
}

void Result::setElapsedTimeMs(double elapsedTimeMs) {
    Result::elapsedTimeMs = elapsedTimeMs;
}

Result::Result(int index, double distance, double elapsedTimeMs) : index(index), distance(distance),
                                                                     elapsedTimeMs(elapsedTimeMs) {}
