#include "def.h"


 double brownian_step(double volatility, double drift, double timestep,double Z, double initial){
    double after_step = initial*exp((drift-volatility*volatility/2)*timestep+volatility*sqrt(timestep)*Z);
    return after_step;
 }