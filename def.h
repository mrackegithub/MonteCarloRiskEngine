#ifndef TITO
#define TITO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include "structures.h"
void box_muller_transform(double *z1,double *z2 );
double brownian_step(double volatility, double drift, double timestep,double Z, double initial);

#endif
