#include "def.h"

//takes in all required parameters to run a step of geometric brownian motion, returns the price of stock after one timestamp
 double brownian_step(double volatility, double drift, double timestep,double Z, double initial){
    double after_step = initial*exp((drift-volatility*volatility/2)*timestep+volatility*sqrt(timestep)*Z);
    return after_step;
 }

 
