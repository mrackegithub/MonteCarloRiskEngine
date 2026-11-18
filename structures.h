#ifndef strukt
#define strukt
typedef struct Analytics{
    int simulated;
    double average;
    double std;
    double skewness;
    double Kurtosis;
    double var95;
    double var99;
    double cvar95;
    

} Analytics;
typedef struct Stock
{
    char ticker[20];
    double spot_price;
    double drift_rate;
    double volatility;
    int simulation_days;
    double new_price;
} Stock;

typedef struct Node
{
    // figure out how bst tree works, how to implement optimally
    Stock data;
    struct Node *left;
    struct Node *right;
} Node;

#endif