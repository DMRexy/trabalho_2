#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_Search.h"
#include <time.h>


Data character_generation(char *name, int size);


int main()
{
    srand(time(NULL));
    int count = 0;
    FILE* nlst;
    nlst = fopen("namelist.txt", "r"); 
    Root*  character_list = create_tree();

    char name[NAMESIZE]; 

    addto_tree(character_list, character_generation("bob", NAMESIZE)); 
    int check = addto_tree(character_list, character_generation("tob", NAMESIZE));
     printf("%d", check);       
   /* while(!feof(nlst)){
        fgets(name, NAMESIZE, nlst); 
        name[strcspn(name, "\n ")] = 0;
        Data newchar = character_generation(name, NAMESIZE);
       printf("code:||%d||",addto_tree(character_list,newchar));    
    }
    
    printf("numero de nomes: %d ", count);
    */
   
   
   
    fclose(nlst);     
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    free(character_list);//REMOVA ISSO O MAIS RAPIDO POSSIVEL!! NÃO SE LIBERA ARVORE ASSIM! APENAS PARA TESTE!!!!!!
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}

Data character_generation(char *name, int size){
     

    Data new_character; 
    strcpy(new_character.name, name);
    new_character.body = rand()%17 + 1;
    new_character.mind = rand()%17 + 1;
    new_character.level = rand()%99 + 1; 

    return new_character; 
}