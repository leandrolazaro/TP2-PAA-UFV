#include <stdio.h>
#include <stdlib.h>
#include "./pyramidProblem/pyramid/pyramid.h"

int main(){
    pyramid *_pyramid=NULL;
    char fileName[100]="teste.txt";

    pyramidInitWhithFile((&_pyramid), fileName);
    pyramidShowPyramid((&_pyramid));

    return 0;
}