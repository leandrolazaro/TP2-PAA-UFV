#include <stdio.h>
#include <stdlib.h>
#include "./structs/pyramid/pyramid.h"

int main(int argc, char *argv[]){
    char fileName[100];
    pyramid *_pyramid=NULL;

    strcpy(fileName, argv[2]);

    switch (atoi(argv[1])){
        case 0:
            if(*argv[3] == '1') printf("----- Solução Recursiva -----\n\n");
            pyramidInitWhithFile((&_pyramid), fileName);
            pyramidRecursiveSolution(&_pyramid);

            break;
        case 1:
            if(*argv[3] == '1') printf("----- Solução com Memorization -----\n\n");
            pyramidInitWhithFile((&_pyramid), fileName);
            pyramidMemorizationSolution(&_pyramid);
            
            break;
        case 2:
            if(*argv[3] == '1') printf("----- Solução De Trás Pra Frente -----\n\n");
            pyramidInitWhithFile((&_pyramid), fileName);
            pyramidFromBackToFrontSolution(&_pyramid);

            break;
        case 3:
            if(*argv[4] == '1') printf("----- Criando arquivo aleatorio -----\n");
            pyramidGenereteRandomPyramidInFile(atoi(argv[3]),fileName);
            break;

        default:
            break;
        }
    
    return 0;
}