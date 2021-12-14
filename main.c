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
    nlst = fopen("namelist.txt", "r"); //arquivo contem nomes de entrada
    Root*  character_list = create_tree();

    char name[NAMESIZE]; 

      int check; 
    while(!feof(nlst)){//busca cada nome no arquivo e cria
        fgets(name, NAMESIZE, nlst); //um personagem. em seguida
        name[strcspn(name, "\n ")] = 0;
        Data newchar = character_generation(name, NAMESIZE);
        addto_tree(character_list,newchar);//adiciona a arvore. 
    }


    Data survivor; 
    survivor.level = 0; 
    show_all(character_list); 
    battle_royale(character_list, &survivor); 

    printf("\nSurvivor is:\n | %s |\n Level: %d\n Body: %d \n Mind: %d\n", survivor.name,survivor.level,survivor.body,survivor.mind);
    fclose(nlst);     
    destroy_tree(character_list);

    return 0;
}
 

Data character_generation(char *name, int size){
//cria um personagem a partir do nome     

    Data new_character; 
    strcpy(new_character.name, name);
    new_character.body = rand()%17 + 1;
    new_character.mind = rand()%17 + 1;
    new_character.level = rand()%99 + 1; 

    return new_character; 
}