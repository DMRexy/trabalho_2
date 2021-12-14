#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMESIZE 15 
struct data{
    char name[15];
    int mind; 
    int body;
    int level; 
}; 

typedef struct data Data; 
typedef struct node Node;
typedef Node* Root; 


Root* create_tree();

int compare_alphabetically(char *name1, char *name2); 

int addto_tree(Root* root, Data data);