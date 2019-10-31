#ifndef PYRAMID
#define PYRAMID

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include "../way/way.h"

typedef struct pyramid{
    int **representation;
    int size;
}pyramid;

void pyramidInitWhithFile(pyramid **_pyramid, char *fileName);
void pyramidGenericInit(pyramid **_pyramid, int size);
void pyramidGetItem(pyramid **_pyramid, int i, int j);
void pyramidSetItem(pyramid **_pyramid, int i, int j);
void pyramidDeletePyramid(pyramid **_pyramid);
void pyramidResetPyramid(pyramid **_pyramid, int i, int j);
void pyramidRecursiveSolution(pyramid **_pyramid);
int pyramidRecursiveSolutionMax(pyramid **_pyramid, way **_way, int i, int j);
void pyramidMemorizationSolution(pyramid **_pyramid);
int pyramidMemorizationSolutionMax(pyramid **_pyramid, pyramid **memorizationPyramid, way **_way, int i, int j);
void pyramidFromBackToFrontSolution(pyramid **_pyramid, pyramid **memorizationPyramid);
int pyramidTheLargestOfTwoNumbers(int number1, int number2);
void pyramidShowPyramid(pyramid **_pyramid);

#endif