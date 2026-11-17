#include "def.h"

// takes in all required parameters to run a step of geometric brownian motion, returns the price of stock after one timestamp
// uses geometric modification of standard brownian motion/weiner process as stock values cannot be negative
// and change is relative instead of absolute, derived with Ito lemma
double brownian_step(double volatility, double drift, double timestep, double Z, double initial)
{
    double after_step = initial * exp((drift - volatility * volatility / 2) * timestep + volatility * sqrt(timestep) * Z);
    return after_step;
}

// input memory adresses where you want standard distribution variables to be stored
void box_muller_transform(double *z1, double *z2)
{
    // generates random uniform distribution double in range (0,1]
    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);
    // Polar coordinate transformation into standard distribution box muller transform
    //Had to turn into polar so Jacobian produces extra factor necessary for u-substitution as the inverse couldnt be calculated
    double R = sqrt(-2.0 * log(u1));
    // Turning the polar coordinate with standard distribution into two standard distribution random variables
    // And sets them to their corresponding memory adress which was passed
    *z1 = R * cos(2.0 * M_PI * u2);
    *z2 = R * sin(2.0 * M_PI * u2);
}
