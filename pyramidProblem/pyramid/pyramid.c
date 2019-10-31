#include "./pyramid.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

void pyramidInitWhithFile(pyramid **_pyramid, char *fileName){

    (*_pyramid)=malloc(sizeof(pyramid));

    char path[100]="././inputFiles/";
    FILE *file=NULL;
    char *temp=(char*)malloc(sizeof(char));

    strcat(path, fileName);

    file=fopen(path, "r");

    if(file != NULL){
        (*temp)=fgetc(file);
        (*_pyramid)->size= atoi(temp);
    }

    (*_pyramid)->representation=malloc((*_pyramid)->size*sizeof(int*));
    for(int i=0; i<(*_pyramid)->size; i++){
        (*_pyramid)->representation[i]=malloc((i+1)*sizeof(int));
        for(int j=0; j<=i; j++){
            (*temp)=fgetc(file);

            if((*temp)=='\n'){
                (*temp)=fgetc(file);
            }
            (*_pyramid)->representation[i][j]=atoi(temp);
        }
    }
}

void pyramidGenericInit(pyramid **_pyramid, int size){
    (*_pyramid)=malloc(sizeof(pyramid));
    (*_pyramid)->size=size;

    (*_pyramid)->representation=malloc(size*sizeof(int*));
    for(int i=0; i<size; i++){
        (*_pyramid)->representation[i]=malloc((i+1)*sizeof(int));
        for(int j=0; j<=i; j++){
            (*_pyramid)->representation[i][j]=0;
        }
    }
}

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

void pyramidShowPyramid(pyramid **_pyramid){
    for(int i=0; i<(*_pyramid)->size; i++){
        for(int j=0; j<=i; j++){
            printf("%d",(*_pyramid)->representation[i][j]);
        }
        printf("\n");
    }
}