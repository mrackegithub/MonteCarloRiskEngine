#ifndef strukt
#define strukt

typedef struct Stock
{
    char name[20];
    double volatility;
    double initial_price;
    double drift;
    double new_price;
} Stock;


typedef struct Node
{
    //figure out how bst tree works, how to implement optimally
    Stock data;
    struct Node *left;
    struct Node *right;
} Node;

#endif