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
       return -1; 
    }

    Node *new_node = malloc(sizeof(Node)); 
     
    if(new_node == NULL){
        return -1;
    }
    new_node->info = data;   
    new_node->left = NULL;      
    new_node->right = NULL; 

    

    Node *previous = *tree; 
    Node *current = *tree;

    while(current != NULL){
     
        if(compare_alphabetically(current->info.name, new_node->info.name) == 0){//mostra que nome jã existe. nome repetido 
                                                                            //é descartado
            free(new_node); 
            return -2;//-2 for name already exists
        }
        
        if(compare_alphabetically(current->info.name, new_node->info.name) > 0){//checamos se o nome em new_node 
            previous = current;                                           //vem antes ou depois do nó atual.
            current = current->left; 
        }else{
            previous = current;
            current = current->right; 
        }

    }

        //if the root points to nothing, it means the tree is empty.
     //and so the new node is attached to root. 
        new_node->left = NULL;
        new_node->right = NULL;
        current = new_node;
        return 0; //return 0 in case of success.  

        
}


int compare_alphabetically(char *name1, char *name2){//para comparar dois numeros alfabeticamente

    while(*name1 != '\0' && *name1 == *name2){ //pegamos o ponteiro para primeira posição de cada, e
        name1++;                             //movemos os dois para direita, passo a passo, comparando.
        name2++;                            //quando um chega em /0 ou é diferente do outro
    }                                       //o ciclo se quebra. subtraimos os caracteres     
                                            //para checar qual é menor que o outro.  
    return (*name1 - *name2);               //se o retorno for < 0 quer dizer que name2 vem antes de name1. 
}                                           