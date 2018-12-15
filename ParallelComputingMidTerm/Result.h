//
// Created by admin on 19-Nov-18.
//

#ifndef PARALLELCOMPUTINGMIDTERM_RESULT_H
#define PARALLELCOMPUTINGMIDTERM_RESULT_H

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


class Result {

private:
    int index;
    double distance;
    double elapsedTimeMs;

public:
    Result(int index, double distance, double elapsedTimeMs);

    int getIndex() const;

    void setIndex(int index);

    double getDistance() const;

    void setDistance(double distance);

    double getElapsedTimeMs() const;

    void setElapsedTimeMs(double elapsedTimeMs);

};


#endif //PARALLELCOMPUTINGMIDTERM_RESULT_H
