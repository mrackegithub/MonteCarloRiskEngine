#include "def.h"


//Takes in a line and adress of the place where we return the stock, returns 1 if it worked and 0 on failure
int read_stock(char *line, Stock* out){
    Stock new_stock;
    line[strcspn(line,"\r\n")] = '\0';//Replaced end of the line with \0
    char *comma = strchr(line,',');//Points to the first occurence of ','
    if(comma== NULL){return 0;}
    size_t len = (size_t)(comma-line);//Computes length of ticker
    if(len == 0 || len > 8) { return 0;}
    for(int i = 0;i<len;i++){
        if(!(isupper((unsigned char)line[i]) || isdigit((unsigned char)line[i]))){ return 0;}//Format check
    }
    memcpy(new_stock.ticker,line,len);
    new_stock.ticker[len]='\0';
    char *p = comma+1;//Start of number parsing
    char *end;
    new_stock.spot_price=strtod(p,&end);//Adress where number parsing ended goes into end
    if(end==p||*end!=','){return 0;}//Checks if end matches our expectations
    p=end+1;
    new_stock.drift_rate=strtod(p,&end);
    if(end==p||*end!=','){return 0;}
    p=end+1;
    new_stock.volatility=strtod(p,&end);
    if(end==p||*end!=','){return 0;}
    p=end+1;
    new_stock.simulation_days=strtol(p,&end,10);
    if(end==p||*end!='\0'){return 0;}//Repeats the same thing over and over but for the last one we check for \0 that we set
    if(!(new_stock.simulation_days>0||new_stock.spot_price > 0||new_stock.volatility > 0)){return 0;}
    new_stock.new_price = new_stock.spot_price;
    *out = new_stock;//Modifies the passed by pointer
    return 1;//Signals that it worked
}

void read_file(FILE *file){
    
    //reads lines untill EOF and parses them with read_stock and calls add_node
}