#include <stdio.h>
#include <stdlib.h>
#include "./structs/pyramid/pyramid.h"

int main(int argc, char *argv[]){
    int selectedAlgorithm=atoi(argv[1]);
    int selectedPyramid=atoi(argv[2]);
    char fileName[100];
    pyramid *_pyramid=NULL;

    if(selectedPyramid==0){
        strcpy(fileName, argv[3]);
        pyramidInitWhithFile((&_pyramid), fileName);
    }else if(selectedPyramid==1){
        pyramidGenereteRandomPyramidInFile(atoi(argv[3]));
    }else if(selectedPyramid==2){
        strcpy(fileName, "randomPyramid.txt");
        pyramidInitWhithFile((&_pyramid), fileName);
    }
    
    if(selectedPyramid==0 || selectedPyramid==2){
        switch (selectedAlgorithm){
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

    return 0;
}