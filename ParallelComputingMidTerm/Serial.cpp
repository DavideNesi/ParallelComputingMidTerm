//
// Created by admin on 19-Nov-18.
//

#include "Serial.h"
#include <iostream>
#include <iomanip>
#include <ctime>


Result SerialExecution(int m,
                       int dataValueUpperBound,
                       int patternLength,
                       int dataSetLength,
                       const std::vector<double> &data,
                       const std::vector<double> &pattern,
                       std::vector<double> result,
                       int verbosity) {
    double smallestDifference = dataValueUpperBound * patternLength;
    int indexOfMin = 0;
    int resultLength = dataSetLength - patternLength;
    timeval t1, t2;
    switch (m) {
        case 0 :
            gettimeofday(&t1, NULL);
            for (int i = 0; i < resultLength; i++) {
                for (int j = 0; j < patternLength; j++) {
                    result[i] += abs(data[i + j] - pattern[j]);
                }
            }
            for (int i = 0; i < resultLength; i++) {
                if (result[i] < smallestDifference) {
                    indexOfMin = i;
                    smallestDifference = result[i];
                }
            }
            gettimeofday(&t2, NULL);
            break;
        case 1 :
            gettimeofday(&t1, NULL);
            for (int j = 0; j < patternLength; j++) {
                for (int i = 0; i < resultLength; i++) {
                    result[i] += abs(data[i + j] - pattern[j]);
                }
            }
            for (int i = 0; i < resultLength; i++) {
                if (result[i] < smallestDifference) {
                    indexOfMin = i;
                    smallestDifference = result[i];
                }
            }
            gettimeofday(&t2, NULL);
            break;
        case 2 :
            gettimeofday(&t1, NULL);
            for (int i = 0; i < resultLength; i++) {
                float tmp = 0;
                for (int j = 0; j < patternLength; j++) {
                    tmp += abs(data[i + j] - pattern[j]);
                }
                result[i] = tmp;
            }
            for (int i = 0; i < resultLength; i++) {
                if (result[i] < smallestDifference) {
                    indexOfMin = i;
                    smallestDifference = result[i];
                }
            }
            gettimeofday(&t2, NULL);
            break;
        case 3:
            gettimeofday(&t1, NULL);
            for (int i = 0; i < resultLength; i++) {
                float tmp = 0;
                for (int j = 0; j < patternLength; j++) {
                    tmp += abs(data[i + j] - pattern[j]);
                }
                //result[i] = tmp;
                if (tmp < smallestDifference) {
                    indexOfMin = i;
                    smallestDifference = tmp;
                }
            }
            gettimeofday(&t2, NULL);
            break;
        default:
            std::cout << "Mode not supported\n";
            break;
    }
    double elapsedTimeMs = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTimeMs += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    if (verbosity > 0) {
        printf("\nSERIAL MODE:%d  -Result:(%d)  -Time:%f ms", m, indexOfMin, elapsedTimeMs);
    }
    if (verbosity > 1) {
        printf("\nShowing Result vector\n");
        for (int i = 0; i < resultLength; i++) {
            printf("%d: %f \n", i, result[i]);
        }
    }
    return Result(indexOfMin, smallestDifference, elapsedTimeMs);
}
