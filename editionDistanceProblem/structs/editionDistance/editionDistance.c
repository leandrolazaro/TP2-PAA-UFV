#include "./editionDistance.h"

void edtionDistanceFromBackToFrontSolution(char *wordA, char *wordB){

    int value=0;
    int x=(strlen(wordA)+1);
    int y=(strlen(wordB)+1);

    int **de=malloc(y*sizeof(int*));
    for(int i=0; i<y; i++){
        de[i]=malloc(x*sizeof(int));
        for(int j=0; j<x; j++){
            de[i][j]=0;
        }
    }

    for(int i=0; i<y; i++){
        de[i][0]=i;
    }

    for(int i=0; i<x; i++){
        de[0][i]=i;
    }
    
    for(int i=1; i<y; i++){
        for(int j=1; j<x; j++){
            if(wordB[i-1]==wordA[j-1]){
                value=0;
            }else{
                value=1;
            }
            de[i][j]=min(min((de[i-1][j]+1), (de[i][j-1]+1)),(de[i-1][j-1]+value));
        }
    }

    // for(int i=0; i<y; i++){
    //     for(int j=0; j<x; j++){
    //         printf("%d", de[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("Distância de edição final: %d\n", de[y-1][x-1]);
    
}

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}