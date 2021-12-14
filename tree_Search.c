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
{ //utiliza compare_alphabetically para checar se um nome está a direita ou a esquerda e posiciona um nó verificador aux
//adequadamente. 
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
        {//não encontrado
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

void show_all(Root* node)//função recursiva de busca em profundidade. imprime todos os personagens
{
    if(node == NULL){
        return;//ao chegar ao fundo da arvore, começa o retorno. 
    }

    if(*node != NULL)
    {
    show_all(&((*node)->left));//invoca a si mesma apontando para o nó a esquerda. isso se repete até começarem a retornar.
    show_all(&((*node)->right));//as informações não vão ser mostradas até que todos os nós abaixo sejam explorados. 
    printf("\n| %s | \n",(*node)->info.name);
    printf("Level: %d \n",(*node)->info.level);
    printf("Body: %d \n",(*node)->info.body);
    printf("Mind: %d \n",(*node)->info.mind);

    } 
}

void battle_royale(Root* node, Data* survivor) 
{//usa o mesmo sistema de recursão para testar o personagem Survivor contra todos os outros. caso ele perca, o vencedor se torna
//o novo Survivor. 
//recebe o mesmo por endereço, para alterá-lo fora da recursão. 
    if(node == NULL){
        return;
    }

    if(*node != NULL)
    {
    battle_royale(&((*node)->left), survivor);
    battle_royale(&((*node)->right), survivor);
    combat(&(*node)->info, survivor); //eu me embaralhei muito com esses ponteiros!
    } 
}

void combat(Data* challenger, Data* survivor)
{//atribui pontuação baseada nos atributos e uma pequena contribuição aleatória 
    int score_challenger = 0; 
    int score_survivor = 0; 

    score_survivor = survivor->level + survivor->mind + survivor->body + rand()%20;
    score_challenger = challenger->level + challenger->mind + challenger->body + rand()%20;
   
    
   
    if(score_survivor < score_challenger || survivor->level == 0)
    {
        *survivor = *challenger;             
    }

}