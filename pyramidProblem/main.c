#include <stdio.h>
#include <stdlib.h>
#include "./structs/pyramid/pyramid.h"

int main(int argc, char *argv[]){
    int argument=atoi(argv[1]);
    pyramid *_pyramid=NULL;
    char fileName[100]="teste.txt";

    pyramidInitWhithFile((&_pyramid), fileName);
    //printf("-----\n");
    // pyramidShowPyramid((&_pyramid));
    // printf("-----\n");

    switch (argument){
    case 0:
        printf("----- Solução Recursiva -----\n\n");
        pyramidRecursiveSolution(&_pyramid);
        break;
    case 1:
        printf("----- Solução com Memorization -----\n\n");
        pyramidMemorizationSolution(&_pyramid);
        break;
    case 2:
        printf("----- Solução De Trás Pra Frente -----\n\n");
        pyramidFromBackToFrontSolution(&_pyramid);
        break;
    default:
        break;
    }

    return 0;
}