#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_Search.h"
#include <time.h>

Data character_generation(char *name, int size);


int main()
{
    char name[15] = "bob"; 
    Data bob = character_generation(name, 15); 
    
    printf("%s | %d | %d | %d",bob.name,bob.mind,bob.body,bob.level); 

    return 0;
}

Data character_generation(char *name, int size){
    srand(time(NULL)); 

    Data new_character; 
    strcpy(new_character.name, name);
    new_character.body = rand()%17 + 1;
    new_character.mind = rand()%17 + 1;
    new_character.level = rand()%99 + 1; 

    return new_character; 
}