#include "def.h"
#define SIMS 1000000
int main(void){
    
    FILE* output =  fopen("output.txt","w");
    if (output == NULL) {
        perror("Error opening file");
        return 1;
    }
    double n1; double n2;
    for(int i = 0; i < SIMS;i++){
        box_muller_transform(&n1,&n2);
        fprintf(output,"%lf %lf ",n1,n2);
    }
    
    fclose(output);
    return 0;
}