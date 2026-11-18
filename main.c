#include "def.h"
#define SIMS 1000000
int main(void)
{
    Node *root = NULL;
    while(1){
        int choice;
        printf("=========================================================\n"
               "MONTE CARLO FINANCIAL RISK ANALYSIS ENGINE\n"
               "=========================================================\n"
               "1. Load Asset Data from File\n"
               "2. Display Loaded Assets\n"
               "3. Run Monte Carlo Simulation\n"
               "4. Export Risk Report to File\n"
               "5. Exit Program\n"
               "=========================================================\n"
               "Enter your choice: ");
        if(scanf("%d", &choice)!=1){
            clear_input();
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            continue;
        }
        clear_input();
        switch (choice)
        {
        case 1:{
            char name[256];
            printf("Enter the filename to load (max 255 characthers) (or press Enter for default 'sim_config.txt'): ");
            if(fgets(name,sizeof(name),stdin)==NULL){//Using fgets as I need to detect user pressing just Enter
                printf("Error fetching name try again.\n");
                break;
            }
            if(strchr(name,'\n')==NULL){//Checks for overflow
                clear_input();
                printf("Input too long.\n");
                break;
            } else{
                name[strcspn(name,"\r\n")]='\0';//Turns input into terminated string
            }
            if(name[0]=='\0'){//In this case user just pressed enter
                strcpy(name,"sim_config.txt");
            }
            FILE *input = fopen(name, "r");
            if (input == NULL)
                {
                    perror("Error opening file");
                    break;
                }
            int lines_read = read_file(input,&root);
            fclose(input);
            if(lines_read>=0){
                printf("Succesfuly loaded %d lines from %s\n",lines_read,name);
            }
            break;}
        case 2:{
            if(root==NULL){
                printf("Nothing to print yet.\n");
            } else{
                print_tree(root);
            }
            break;}
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            free_tree(root);
            return 0;
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
        }
    }

    
    
    
}