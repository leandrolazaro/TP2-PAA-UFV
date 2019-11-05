#include "./editionDistance.h"

void edtionDistanceFromBackToFrontSolution(char *wordA, char *wordB){

    int value=0;
    int *vetorPesos=malloc(3*sizeof(int));
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
        for(int j=0; j<x; j++){
            printf("%d", de[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", de[y-1][x-1]);
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
            vetorPesos[0]=de[i-1][j-1]+value;
            vetorPesos[1]=de[i-1][j]+1;
            vetorPesos[2]=de[i][j-1]+1;
            bubbleSort(vetorPesos, 3);
            de[i][j]=vetorPesos[0];
            printf("%c %c\n",wordA[j-1], wordB[i-1]);
            printf("%d\n", vetorPesos[0]);

        }
    }

    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            printf("%d", de[i][j]);
        }
        printf("\n");
    }
    
}

void bubbleSort(int *v, int n){ 
    if (n < 1)return; 
 
    for (int i=0; i<n; i++) 
        if (v[i] > v[i+1]) 
            swap(&v[i], &v[i+1]);  
    bubbleSort(v, n-1); 
} 

void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 