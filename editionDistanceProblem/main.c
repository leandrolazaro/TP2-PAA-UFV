#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./structs/editionDistance/editionDistance.h"

int main(){
    char wordA[100]="kitten";
    char wordB[100]="sitting";
    edtionDistanceFromBackToFrontSolution(wordA, wordB);
}