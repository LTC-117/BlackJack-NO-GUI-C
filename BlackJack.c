#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int go;
int n = 0;
int **array;
int soma;

void hit();
void stay();

int main(){

    srand(time(NULL));
    printf("Welcome to BlackJack! Here are the rules: \n");
    printf("The dealer will draw cards for you and for himself. The value of each card will be somed up. \n");
    printf("The goal is to reach 21 or get as close as possible without going over. If you exceed 21, you bust!\n\n");
    printf(" 1: Hit \n 2: Stay \n 3: Exit \n");

    do{
        printf("\nYou want to hit or stand?\n");
        scanf("%d", &go);
        switch(go){
            case 1: hit(); break;
            case 2: stay(); break;
            case 3: printf("GOODBYE!"); break;
            default: printf("Error! Try again:\n");
        }
    } while (go != 2 && go != 3);

    for(int i=0; i<n; i++){
        free(array[i]);
    }
    free(array);

    return 0;
}

void hit(){
    n += 1;

    array = (int **)realloc(array, n * sizeof(int *));
    if(array == NULL){
        printf("ERROR!");
        exit (1);
    }

    int *newCard = (int *)malloc(sizeof (int));
    *newCard = (rand() % 11) + 1;
    array[n-1] = newCard;
    printf("card number %d is: %d\n", n, *array[n-1]);

    soma=0;
    for(int i=0; i<n; i++){
        soma += *array[i];
    }

    if(soma > 21){
        printf("%d!!!\nYOU BUSTED!!!", soma);
        exit(1);
    }
    if(soma == 21){
        printf("%d!!!\nYOU WIN!!!", soma);
        exit (2);
    }
}

void stay(){

    soma=0;
    for(int i=0; i<n; i++){
        soma += *array[i];
    }
    printf("\nYou stopped at: %d \n", soma);

    if(soma < 21){
        int dealerSum = (rand() % 11) + 15;
        printf("Dealer's sum is: %d \n", dealerSum);
        if(dealerSum == 21){
            printf("YOU LOSE!!!");
        }
        if(dealerSum < soma){
            printf("YOU WIN!!!");
        }
        if(dealerSum > 21){
            printf("\nDEALER BUSTED!!! \nYOU WIN!!!");
        }
    }
}
