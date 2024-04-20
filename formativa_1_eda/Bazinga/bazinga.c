#include <stdio.h>
#include <string.h>

void analise(char sheldon[], char raj[]){
    if (strcmp(sheldon, raj) == 0) {
        printf("De novo!\n");
        return;
    }
    if ((strcmp(sheldon, "tesoura") == 0 && (strcmp(raj, "papel") == 0 || strcmp(raj, "lagarto") == 0)) ||
        (strcmp(sheldon, "papel") == 0 && (strcmp(raj, "pedra") == 0 || strcmp(raj, "Spock") == 0)) ||
        (strcmp(sheldon, "pedra") == 0 && (strcmp(raj, "lagarto") == 0 || strcmp(raj, "tesoura") == 0)) ||
        (strcmp(sheldon, "lagarto") == 0 && (strcmp(raj, "Spock") == 0 || strcmp(raj, "papel") == 0)) ||
        (strcmp(sheldon, "Spock") == 0 && (strcmp(raj, "tesoura") == 0 || strcmp(raj, "pedra") == 0))) {
        printf("Bazinga!\n"); 
    } else {
        printf("Raj trapaceou!\n"); 
    }
}

int main(){
    char sheldon[10];
    char raj[10];

    scanf("%s %s", sheldon, raj);

    analise(sheldon, raj);

    return 0;
}