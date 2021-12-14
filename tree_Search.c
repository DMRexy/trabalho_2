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

int addto_tree(Root* root, Data data){
    if(root == NULL){
       return 0; 
    }

    Node *new_node = malloc(sizeof(Node)); //cria e aloca novo nó
    if(new_node == NULL){ //verifica se é valido
        return 0;
    }
    
    new_node->info = data;   //atribui os valores do novo nó. note que ele é necessariamente uma folha. 
    new_node->left = NULL;  
    new_node->right = NULL; 

    Node *previous = NULL; //cria dois nós auxiliares para navegar a arvore. 
    Node *current = *root;

    if(*root == NULL){
        *root = new_node;
        return 1;  
    }

    while(current != NULL)
    {
     
        if (compare_alphabetically(new_node->info.name, current->info.name) == 0)
        {//mostra que nome jã existe. nome repetido
        //é descartado
            free(new_node); 
            return 2;// -2 nome descartado
        }
        
        if (compare_alphabetically(new_node->info.name, current->info.name) > 0)
        {//checamos se o nome em new_node 
         //vem antes ou depois do nó atual.   
            previous = current;                                           
            current = current->right; 
            
        }else{
            previous = current;
            current = current->left; 
           
        } 

    }

    if (compare_alphabetically(new_node->info.name, previous->info.name) > 0)
        {
            previous->right = new_node; 
        }else
        {
            previous->left = new_node; 
        }
    
    return 3;
        
}

int search_character(Root* root,Data *character ,char* name)
{ 
    Node *aux = *root;
    while(compare_alphabetically(name, aux->info.name) != 0)
    {
        if(compare_alphabetically(name, aux->info.name) > 0)
        {
            aux = aux->right; 
        }else
        {
            aux = aux->left; 
        }

        if(aux == NULL)
        {
            return 0; 
        }
    }

    *character = aux->info; 
    return 1; 

}

int compare_alphabetically(char *name1, char *name2){//para comparar dois numeros alfabeticamente (n1 fica na posição que < aponta)

    while(*name1 != '\0' && *name1 == *name2)  
    {                                         //pegamos o ponteiro para primeira posição de cada, e
        name1++;                             //movemos os dois para direita, passo a passo, comparando.
        name2++;                            //quando um chega em /0 ou é diferente do outro
    }                                       //o ciclo se quebra. subtraimos os caracteres     
                                            //para checar qual é menor que o outro.  
    return (*name2 - *name1);               //se o retorno for < 0 quer dizer que name1 vem antes de name2. 
}                                           

void free_node(Node* node)
{
    if(node == NULL){
        return;
    }

    free_node(node->left);
    free_node(node->right);
    free(node); 
    node=NULL;
}

void destroy_tree(Root* root)
{
    if(root == NULL){
        return; 
    }

    free_node(*root);
    free(root);
}

void travel_tree(Root* node)
{
    if(node == NULL){
        return;
    }

    if(*node != NULL)
    {
    travel_tree(&((*node)->left));
    travel_tree(&((*node)->right));
    printf("%s \n",(*node)->info.name);
    } 
}