#include <stdio.h>
#include <stdlib.h>
#include "./pyramidProblem/structs/pyramid/pyramid.h"

int main(){
    pyramid *_pyramid=NULL;
    char fileName[100]="teste.txt";

    pyramidInitWhithFile((&_pyramid), fileName);
    printf("-----\n");
    pyramidShowPyramid((&_pyramid));
    printf("-----\n");
    pyramidRecursiveSolution(&_pyramid);
    printf("-----\n");
    pyramidMemorizationSolution(&_pyramid);
    printf("-----\n");
    pyramidFromBackToFrontSolution(&_pyramid);

    return 0;
}