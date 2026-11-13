#include "def.h"
#define SIMS 1000000
int main(void){
    
    FILE* output =  fopen("output.txt","w");
    if (output == NULL) {
        perror("Error opening file");
        return 1;
    }
    

    
    fclose(output);
    
    
    return 0;
}