#include "./pyramid.h"

void pyramidInitWhithFile(pyramid **_pyramid, char *fileName){

    (*_pyramid)=malloc(sizeof(pyramid));

    char path[100]="./././inputFiles/";
    FILE *file=NULL;
    char *temp=(char*)malloc(50*sizeof(char));

    strcat(path, fileName);

    file=fopen(path, "r");

    if(file != NULL){
        (*temp)=fgetc(file);
        (*_pyramid)->size= atoi(temp);
    }

    (*_pyramid)->content=malloc((*_pyramid)->size*sizeof(int*));
    for(int i=0; i<(*_pyramid)->size; i++){
        (*_pyramid)->content[i]=malloc((i+1)*sizeof(int));
        for(int j=0; j<=i; j++){
            if(fscanf(file, "%s", temp)){
                (*_pyramid)->content[i][j]=atoi(temp);
            }
        }
    }
}

void pyramidGenericInit(pyramid **_pyramid, int size){
    (*_pyramid)=malloc(sizeof(pyramid));
    (*_pyramid)->size=size;

    (*_pyramid)->content=malloc(size*sizeof(int*));
    for(int i=0; i<size; i++){
        (*_pyramid)->content[i]=malloc((i+1)*sizeof(int));
        for(int j=0; j<=i; j++){
            (*_pyramid)->content[i][j]=0;
        }
    }
}

int pyramidGetItem(pyramid **_pyramid, int i, int j){
    if(i<(*_pyramid)->size && j<=i){
        return (*_pyramid)->content[i][j];
    }else{
        printf("Animal, você não sabe o que é uma pirâmide?\n");
    }

    return -1;
}

void pyramidSetItem(pyramid **_pyramid, int i, int j, int item){
    if(i<(*_pyramid)->size && j<=i){
        (*_pyramid)->content[i][j]=item;
    }else{
        printf("Animal, você não sabe o que é uma pirâmide?\n");
    }
}

void pyramidDeletePyramid(pyramid **_pyramid){
    for(int i=0; i<(*_pyramid)->size; i++){
        free((*_pyramid)->content[i]);
    }
    free((*_pyramid)->content);
    free((*_pyramid));
}

void pyramidResetPyramid(pyramid **_pyramid, int i, int j){
    for(int i=0; i<(*_pyramid)->size; i++){
        for(int j=0; j<=i; j++){
            (*_pyramid)->content[i][j]=0;
        }
    }
}

void pyramidRecursiveSolution(pyramid **_pyramid){
    int bestWay;
    pyramid *weightPyramid=NULL;
    pyramidGenericInit(&weightPyramid, (*_pyramid)->size);
    bestWay=pyramidRecursiveSolutionMax(_pyramid, &weightPyramid, 0, 0);
    pyramidShowBiggerWay(_pyramid, &weightPyramid, 0, 0);
    printf("Maior Soma: %d unidade(s)\n", bestWay);

}

int pyramidRecursiveSolutionMax(pyramid **_pyramid, pyramid **weightPyramid, int i, int j){
    int esquerda, direita;
    if(i+1==(*_pyramid)->size){
        (*weightPyramid)->content[i][j]=(*_pyramid)->content[i][j];
        return (*_pyramid)->content[i][j];
    }
    esquerda=pyramidRecursiveSolutionMax(_pyramid, weightPyramid, i+1, j);
    direita=pyramidRecursiveSolutionMax(_pyramid, weightPyramid, i+1, j+1);
    if(esquerda>direita){
        (*weightPyramid)->content[i][j]=(*_pyramid)->content[i][j]+esquerda;
        return (*_pyramid)->content[i][j]+esquerda;
    }
    (*weightPyramid)->content[i][j]=(*_pyramid)->content[i][j]+direita;
    return (*_pyramid)->content[i][j]+direita;
}

void pyramidMemorizationSolution(pyramid **_pyramid){
    int bestWay;
    pyramid *memorizationPyramid=NULL;
    pyramidGenericInit(&memorizationPyramid, (*_pyramid)->size);
    bestWay=pyramidMemorizationSolutionMax(_pyramid, &memorizationPyramid, 0, 0);
    pyramidShowBiggerWay(_pyramid, &memorizationPyramid, 0, 0);
    printf("Maior Soma: %d unidade(s)\n", bestWay);
}
int pyramidMemorizationSolutionMax(pyramid **_pyramid, pyramid **memorizationPyramid, int i, int j){
    int esquerda, direita;
    if(i+1==(*_pyramid)->size){
        (*memorizationPyramid)->content[i][j]=(*_pyramid)->content[i][j];
        return (*_pyramid)->content[i][j];
    }
    if((*memorizationPyramid)->content[i+1][j]!=0 && (*memorizationPyramid)->content[i+1][j+1]!=0){
        if((*memorizationPyramid)->content[i+1][j]>(*memorizationPyramid)->content[i+1][j+1]){
            return (*memorizationPyramid)->content[i+1][j];
        }
        return (*memorizationPyramid)->content[i+1][j+1];    
    }
    esquerda=pyramidRecursiveSolutionMax(_pyramid, memorizationPyramid, i+1, j);
    direita=pyramidRecursiveSolutionMax(_pyramid, memorizationPyramid, i+1, j+1);
    if(esquerda>direita){
        (*memorizationPyramid)->content[i][j]=(*_pyramid)->content[i][j]+esquerda;
        return (*_pyramid)->content[i][j]+esquerda;
    }
    (*memorizationPyramid)->content[i][j]=(*_pyramid)->content[i][j]+direita;
    return (*_pyramid)->content[i][j]+direita;
}
void pyramidFromBackToFrontSolution(pyramid **_pyramid, pyramid **memorizationPyramid);
int pyramidTheLargestOfTwoNumbers(int number1, int number2);

void pyramidShowPyramid(pyramid **_pyramid){
    for(int i=0; i<(*_pyramid)->size; i++){
        for(int j=0; j<=i; j++){
            printf("%d ",(*_pyramid)->content[i][j]);
        }
        printf("\n");
    }
}

void pyramidShowBiggerWay(pyramid **_pyramid, pyramid **weightPyramid, int i, int j){
    printf("Coordenadas: %d, %d | Conteúdo: %d\n", i, j, (*_pyramid)->content[i][j]);
    if(i<(*weightPyramid)->size-1){
        if((*weightPyramid)->content[i+1][j]>(*weightPyramid)->content[i+1][j+1]){
            pyramidShowBiggerWay(_pyramid, weightPyramid, i+1, j);
        }else{
            pyramidShowBiggerWay(_pyramid, weightPyramid, i+1, j+1);
        }
    }
    return;
}