#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_Search.h"

struct node{
    Data info; 
    Node* right;
    Node* left;
};

Root* create_tree(){

    Root* new_tree = malloc(sizeof(Root)); 
    if(new_tree != NULL){
        *new_tree = NULL; //create the root node, and it will point to nothing for now. 
                        //but will point to the first node when it's created.  
    }
    return new_tree; 

}

int addto_tree(Root* tree, Data data){
    if(tree != NULL){
       return -1; // -1 is code for allocation error. 
    }

    Node *new_node = malloc(sizeof(Node)); 
    if(new_node == NULL){
        return -1;
    }

    if(*tree == NULL){//if the root points to nothing, it means the tree is empty.
                    //and so the new node is attached to root. 
        *tree = new_node; 
        new_node->left = NULL;
        new_node->right = NULL;
        return 0; //return 0 in case of success.  
    }

    Node *previous; 
    Node *current;

        
}


int compare_alphabetically(char *name1, char *name2){//to compare two names alphabetically,

    while(*name1 != '\0' && *name1 == *name2){ //get the pointer to the first position of each, and move
        name1++;                            //them together, checking if they are still equal. 
        name2++;                            //the moment one becomes \0 or different from the other, 
    }                                       //the loop breaks. then we subtract the first different     
                                            //characters to check which is greater than the other. 
    return (*name1 - *name2); 
}