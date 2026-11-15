#include "def.h"
#define SIMS 1000000
int main(void){
    
    while(1){
        int choice;
        printf("1. File insertion\n2.List companies\n3.Run simulation\n4.Display metrics\n5.Exit\nEnter your choice: ");//Just a placeholder
        scanf("%d",&choice);
        //After this input a switch menu and for each option call their corresponding function
    }

    //code below for file loading
    FILE* output =  fopen("sim_config","r");
    if (output == NULL) {
        perror("Error opening file");
        return 1;
    }
    

    
    fclose(output);
    
    
    return 0;
}