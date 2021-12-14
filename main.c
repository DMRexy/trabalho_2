#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_Search.h"
#include <time.h>


Data character_generation(char *name, int size);


int main()
{
    srand(time(NULL));
    
    int return_count[4]; 

    for (size_t i = 0; i < 4; i++)
    {
        return_count[i] = 0;
     }
    

    FILE* nlst;
    nlst = fopen("namelist.txt", "r"); 
    Root*  character_list = create_tree();

    char name[NAMESIZE]; 

      int check; 
    while(!feof(nlst)){
        fgets(name, NAMESIZE, nlst); 
        name[strcspn(name, "\n ")] = 0;
        Data newchar = character_generation(name, NAMESIZE);
        addto_tree(character_list,newchar);
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        printf("return %d: %d times\n",i, return_count[i]); 
    }
    Data getcharacter; 
    char chaname[NAMESIZE] = "Daman"; 
    check = search_character(character_list, &getcharacter, chaname);
    printf("check:%d \n %s\n %d | %d | %d \n",check,getcharacter.name, getcharacter.level,getcharacter.mind,getcharacter.body);  
   
   
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