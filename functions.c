

#include "def.h"

void box_muller_transform(double *z1,double *z2 ){//input memory adresses where you want standard distribution variables to be stored
    double u1 = (rand()+1.0)/(RAND_MAX+2.0);//generates random uniform distribution double in range [0,1]
    double u2 = (rand()+1.0)/(RAND_MAX+2.0);

    double R = sqrt(-2.0*log(u1)); //Polar coordinate transformation into standard distribution box muller transform
    *z1 = R*cos(2.0*M_PI*u2);//Turning the polar coordinate with standard distribution into two standard distribution random variables
    *z2 = R*sin(2.0*M_PI*u2);//And sets them to their corresponding memory adress which was passed
}





