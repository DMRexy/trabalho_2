#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_Search.h"
#include <time.h>

void play(Root* character_list);
int populate(Root* character_list);
void find(Root* character_list);
Data character_generation(char *name, int size);

int main()
{
    srand(time(NULL));
    Root*  character_list = create_tree();
   
    printf("Welcome to Rex's character populator!\n");
    
    
    int choice=5; 
    
    do{
        printf("Please choose an option: \n 1 - populate tree \n 2 - show all characters \n 3 - search for character \n 4 - play tournament \n 0 - exit\n");
        scanf("%d",&choice); 

        switch (choice)
        {
        case 1:
            populate(character_list);
            break;
        case 2:
            show_all(character_list);
            break; 
        case 3: 
            find(character_list);
            break;
        case 4:
            play(character_list);
            break;
        case 0:
            printf("\nFarewell!\n");
            break;  
        default:
            printf("\nSorry friend, I do not understand\n"); 
            break;
        }
    }while(choice != 0);
    

    destroy_tree(character_list);
    return 0;
}

void find(Root* character_list)
{
    printf("Please type the name you want to find\n");
    char name[NAMESIZE];
    getchar();
    fgets(name, NAMESIZE, stdin); 
    name[strcspn(name, "\n")] = 0;
    if(name[0] >= 'a' && name[0] <= 'z'){
        name[0] = name[0]-32;//normalizando a capitalizacão 
    }
    printf("searching for |%s|\n", name);
    Data found;
    search_character(character_list, &found,name);
    printf("\n| %s |\n Level: %d\n Body: %d \n Mind: %d\n", found.name,found.level,found.body,found.mind);
    return;
}

void play(Root* character_list)
{
    Data survivor; 
    survivor.level = 0;
    tournament(character_list, &survivor); 

    printf("\nSurvivor is:\n | %s |\n Level: %d\n Body: %d \n Mind: %d\n", survivor.name,survivor.level,survivor.body,survivor.mind);
    return;
}
int populate(Root* character_list)
{//popula a arvore com o numero indicado de personagens.    
    FILE* nlst;
    
    
    nlst = fopen("namelist.txt", "r"); //arquivo contem nomes de entrada
    char name[NAMESIZE]; 
    printf("choose the number of characters (will create the maximum available if number is too high)\n");
    int quant;
    scanf("%d",&quant);
    int chacount = 0;
    while(1){//busca cada nome no arquivo e cria
        
        fgets(name, NAMESIZE, nlst); //um personagem. em seguida
        name[strcspn(name, "\n ")] = 0;
        
        Data newchar = character_generation(name, NAMESIZE);
        addto_tree(character_list,newchar);//adiciona a arvore.
        
        chacount++; 
        
        if(feof(nlst)){
            printf("all names used! starting with %d characters\n", chacount);
            break; 
        }
        if(chacount == quant){
            printf("populated with %d characters!\n", quant);
            break;
        }
    }
    fclose(nlst);
    return 1;
}

Data character_generation(char *name, int size){
//cria um personagem a partir do nome     

    Data new_character; 
    strcpy(new_character.name, name);
    new_character.body = rand()%17 + 1;
    new_character.mind = rand()%17 + 1;
    new_character.level = rand()%20 + 1; 

    return new_character; 
}