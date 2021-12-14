#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_Search.h"
#include <time.h>


Data character_generation(char *name, int size);


int main()
{
    srand(time(NULL));

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
      
   
   
    fclose(nlst);     
    destroy_tree(character_list);
    
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