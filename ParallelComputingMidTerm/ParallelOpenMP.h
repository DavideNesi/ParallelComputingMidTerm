//
// Created by admin on 19-Nov-18.
//

#ifndef PARALLELCOMPUTINGMIDTERM_PARALLELOPENMP_H
#define PARALLELCOMPUTINGMIDTERM_PARALLELOPENMP_H

#include <iostream>
#include <random>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Result.h"

Result ParallelOpenMPExecution(int m, int dataValueUpperBound, int patternLength, int dataSetLength,const std::vector<double> &data,
                               const  std::vector<double> &pattern,  std::vector<double> result, int verbosity);


#endif //PARALLELCOMPUTINGMIDTERM_PARALLELOPENMP_H
