#ifdef _OPENMP

#include <omp.h> // for OpenMP library functions

#endif

#include <iostream>
#include <random>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include<cstdio>
#include <iomanip>
#include <iostream>

#include "Serial.h"
#include "ParallelOpenMP.h"

using namespace std;

int main() {

    int MAXdataSetLength = 10000000;
    int MAXpatternLength = 1000;
    int dataValueLowerBound = 0;
    int dataValueUpperBound = 1000;
    int verbosity = 1;

    std::vector<double> data(MAXdataSetLength);
    std::vector<double> pattern(MAXpatternLength);
    int MAXresultLength = MAXdataSetLength - MAXpatternLength;
    std::vector<double> result(MAXresultLength);

    std::default_random_engine eng{static_cast<long unsigned int>(time(0))};
    std::uniform_real_distribution<double> uniform(dataValueLowerBound, dataValueUpperBound);

    if (verbosity > 0)printf("Creating data vector... \n");
    for (int i = 0; i < MAXdataSetLength; i++) {
        data[i] = uniform(eng);
        if (verbosity > 1)printf("%d: %f \n", i, data[i]);
    }
    if (verbosity > 0)printf("Data vector created \n");

    if (verbosity > 0)printf("Creating pattern vector... \n");
    for (int i = 0; i < MAXpatternLength; i++) {
        pattern[i] = uniform(eng);
        if (verbosity > 1)printf("%d: %f \n", i, pattern[i]);
    }
    if (verbosity > 0)printf("Pattern vector created \n");

    if (verbosity > 0)printf("Creating result vector... \n");
    for (int i = 0; i < MAXresultLength; i++) {
        result[i] = 0;
        if (verbosity > 1)printf("%d: %f \n", i, result[i]);
    }
    if (verbosity > 0)printf("Result vector created \n");



/*
    printf("\nExecuting research of pattern... ");

    printf("\n\n---------------------------SERIAL---------------------------");
    SerialExecution(0,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    SerialExecution(1,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    SerialExecution(2,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    SerialExecution(3,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    */


    printf("\n\n---------------------------OpenMP---------------------------");
    std::cout << "\nNum processors (Phys+HT): " << omp_get_num_procs();
    ParallelOpenMPExecution(0,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    ParallelOpenMPExecution(1,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    ParallelOpenMPExecution(2,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    ParallelOpenMPExecution(3,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    ParallelOpenMPExecution(4,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    ParallelOpenMPExecution(5,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);
    ParallelOpenMPExecution(6,dataValueUpperBound,MAXpatternLength,MAXdataSetLength,data, pattern,result,verbosity);




    int startingDataSetLength = 100000; //100000:100000:10000000
    int dataSetIncrement = 100000;
    int startingPatternLength = 100; //100:100:1000
    int patternLengthIncrement = 100;

    /*DONE
    //approx. 1H
    printf("\n");
    printf("Zparallel = [\n ");
    for (int i = startingDataSetLength; i <= MAXdataSetLength; i = i + dataSetIncrement) {
        for (int j = startingPatternLength; j <= MAXpatternLength; j = j + patternLengthIncrement) {
            Result tmpResult = ParallelOpenMPExecution(4, dataValueUpperBound, j, i, data, pattern, result, 0);
            printf("%.3f\n", tmpResult.getElapsedTimeMs());
            if (j != MAXpatternLength) {
                printf(" ");
            }
        }
        printf("; ");
    }
    printf("]\n");
    //*/


    /*DONE
    //approx. 9H
    printf("\n");
    printf("Zserial = [\n ");
    for (int i = startingDataSetLength; i <= MAXdataSetLength; i = i + dataSetIncrement) {
        for (int j = startingPatternLength; j <= MAXpatternLength; j = j + patternLengthIncrement) {
            Result tmpResult = SerialExecution(0, dataValueUpperBound, j, i, data, pattern, result, 0);
            printf("%.3f\n", tmpResult.getElapsedTimeMs());
            if (j != MAXpatternLength) {
                printf(" ");
            }
        }
        printf("; ");
    }
    printf("]\n");
    */

    return 0;
}



