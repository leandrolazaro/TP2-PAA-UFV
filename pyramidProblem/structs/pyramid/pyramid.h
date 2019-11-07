#ifndef PYRAMID
#define PYRAMID

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <math.h>

typedef struct pyramidItem{
    int content;
    int written;
}pyramidItem;

typedef struct pyramid{
    pyramidItem **_pyramidItem;
    int size;
}pyramid;

void pyramidInitWhithFile(pyramid **_pyramid, char *fileName);
void pyramidGenereteRandomPyramidInFile(int height, char *fileName);
void pyramidGenericInit(pyramid **_pyramid, int size);
int pyramidGetItem(pyramid **_pyramid, int i, int j);
void pyramidSetItem(pyramid **_pyramid, int i, int j, int item);
void pyramidDeletePyramid(pyramid **_pyramid);
void pyramidResetPyramid(pyramid **_pyramid, int i, int j);
void pyramidRecursiveSolution(pyramid **_pyramid);
int pyramidRecursiveSolutionMax(pyramid **_pyramid, pyramid **weightPyramid, int i, int j);
void pyramidMemorizationSolution(pyramid **_pyramid);
int pyramidMemorizationSolutionMax(pyramid **_pyramid, pyramid **memorizationPyramid, int i, int j);
void pyramidFromBackToFrontSolution(pyramid **_pyramid);
int pyramidTheLargestOfTwoNumbers(int number1, int number2);
void pyramidShowPyramid(pyramid **_pyramid);
void pyramidShowBiggerWay(pyramid **_pyramid, pyramid **weightPyramid, int i, int j);

#endif