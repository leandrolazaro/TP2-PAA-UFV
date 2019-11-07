#include <stdio.h>
#include <stdlib.h>
#include "./structs/pyramid/pyramid.h"

int main(int argc, char *argv[]){
    char fileName[100];
    pyramid *_pyramid=NULL;
    if(!strcmp("genereteRandomFile", argv[1])){
        //printf("teste\n");
        strcpy(fileName, argv[2]);
        pyramidGenereteRandomPyramidInFile(atoi(argv[argc-1]),fileName);
    }else{
        if(!strcmp("useFile", argv[1])){
            strcpy(fileName, argv[2]);
            pyramidInitWhithFile((&_pyramid), fileName);
        }
        if(_pyramid!=NULL){
            switch (atoi(argv[argc-1])){
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
        }
    }
    

    return 0;
}