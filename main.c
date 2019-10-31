#include <stdio.h>
#include <stdlib.h>
#include "./pyramidProblem/structs/pyramid/pyramid.h"

int main(){
    pyramid *_pyramid=NULL;
    char fileName[100]="teste.txt";

    pyramidInitWhithFile((&_pyramid), fileName);
    pyramidShowPyramid((&_pyramid));
    pyramidMemorizationSolution(&_pyramid);

    return 0;
}