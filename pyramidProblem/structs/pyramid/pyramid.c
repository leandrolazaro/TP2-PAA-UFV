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

    (*_pyramid)->_pyramidItem=malloc((*_pyramid)->size*sizeof(pyramidItem*));
    for(int i=0; i<(*_pyramid)->size; i++){
        (*_pyramid)->_pyramidItem[i]=malloc((i+1)*sizeof(pyramidItem));
        for(int j=0; j<=i; j++){
            if(fscanf(file, "%s", temp)){
                (*_pyramid)->_pyramidItem[i][j].content=atoi(temp);
                (*_pyramid)->_pyramidItem[i][j].written=0;
            }
        }
    }
}

void pyramidGenericInit(pyramid **_pyramid, int size){
    (*_pyramid)=malloc(sizeof(pyramid));
    (*_pyramid)->size=size;

    (*_pyramid)->_pyramidItem=malloc(size*sizeof(pyramidItem*));
    for(int i=0; i<size; i++){
        (*_pyramid)->_pyramidItem[i]=malloc((i+1)*sizeof(pyramidItem));
        for(int j=0; j<=i; j++){
            (*_pyramid)->_pyramidItem[i][j].content=0;
            (*_pyramid)->_pyramidItem[i][j].written=0;
        }
    }
}

int pyramidGetItem(pyramid **_pyramid, int i, int j){
    if(i<(*_pyramid)->size && j<=i){
        return (*_pyramid)->_pyramidItem[i][j].content;
    }else{
        printf("Animal, você não sabe o que é uma pirâmide?\n");
    }

    return -1;
}

void pyramidSetItem(pyramid **_pyramid, int i, int j, int item){
    if(i<(*_pyramid)->size && j<=i){
        (*_pyramid)->_pyramidItem[i][j].content=item;
    }else{
        printf("Animal, você não sabe o que é uma pirâmide?\n");
    }
}

void pyramidDeletePyramid(pyramid **_pyramid){
    for(int i=0; i<(*_pyramid)->size; i++){
        free((*_pyramid)->_pyramidItem[i]);
    }
    free((*_pyramid)->_pyramidItem);
    free((*_pyramid));
}

void pyramidResetPyramid(pyramid **_pyramid, int i, int j){
    for(int i=0; i<(*_pyramid)->size; i++){
        for(int j=0; j<=i; j++){
            (*_pyramid)->_pyramidItem[i][j].content=0;
            (*_pyramid)->_pyramidItem[i][j].written=0;
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
    pyramidDeletePyramid(&weightPyramid);
}

int pyramidRecursiveSolutionMax(pyramid **_pyramid, pyramid **weightPyramid, int i, int j){
    int esquerda, direita;
    if(i+1==(*_pyramid)->size){
        (*weightPyramid)->_pyramidItem[i][j].content=(*_pyramid)->_pyramidItem[i][j].content;
        return (*_pyramid)->_pyramidItem[i][j].content;
    }
    esquerda=pyramidRecursiveSolutionMax(_pyramid, weightPyramid, i+1, j);
    direita=pyramidRecursiveSolutionMax(_pyramid, weightPyramid, i+1, j+1);
    if(esquerda>direita){
        (*weightPyramid)->_pyramidItem[i][j].content=(*_pyramid)->_pyramidItem[i][j].content+esquerda;
        return (*_pyramid)->_pyramidItem[i][j].content+esquerda;
    }
    (*weightPyramid)->_pyramidItem[i][j].content=(*_pyramid)->_pyramidItem[i][j].content+direita;
    return (*_pyramid)->_pyramidItem[i][j].content+direita;
}

void pyramidMemorizationSolution(pyramid **_pyramid){
    int bestWay;
    pyramid *memorizationPyramid=NULL;
    pyramidGenericInit(&memorizationPyramid, (*_pyramid)->size);
    bestWay=pyramidMemorizationSolutionMax(_pyramid, &memorizationPyramid, 0, 0);
    pyramidShowBiggerWay(_pyramid, &memorizationPyramid, 0, 0);
    printf("Maior Soma: %d unidade(s)\n", bestWay);
    pyramidDeletePyramid(&memorizationPyramid);
}
int pyramidMemorizationSolutionMax(pyramid **_pyramid, pyramid **memorizationPyramid, int i, int j){
    int esquerda, direita;
    if(i+1==(*_pyramid)->size){
        (*memorizationPyramid)->_pyramidItem[i][j].content=(*_pyramid)->_pyramidItem[i][j].content;
        (*memorizationPyramid)->_pyramidItem[i][j].written=1;
        return (*_pyramid)->_pyramidItem[i][j].content;
    }
    if((*memorizationPyramid)->_pyramidItem[i+1][j].written && (*memorizationPyramid)->_pyramidItem[i+1][j+1].written){
        if((*memorizationPyramid)->_pyramidItem[i+1][j].content>(*memorizationPyramid)->_pyramidItem[i+1][j+1].content){
            return (*memorizationPyramid)->_pyramidItem[i+1][j].content;
        }
        return (*memorizationPyramid)->_pyramidItem[i+1][j+1].content;    
    }
    esquerda=pyramidRecursiveSolutionMax(_pyramid, memorizationPyramid, i+1, j);
    direita=pyramidRecursiveSolutionMax(_pyramid, memorizationPyramid, i+1, j+1);
    if(esquerda>direita){
        (*memorizationPyramid)->_pyramidItem[i][j].content=(*_pyramid)->_pyramidItem[i][j].content+esquerda;
        (*memorizationPyramid)->_pyramidItem[i][j].written=1;
        return (*_pyramid)->_pyramidItem[i][j].content+esquerda;
    }
    (*memorizationPyramid)->_pyramidItem[i][j].content=(*_pyramid)->_pyramidItem[i][j].content+direita;
    (*memorizationPyramid)->_pyramidItem[i][j].written=1;
    return (*_pyramid)->_pyramidItem[i][j].content+direita;
}

void pyramidFromBackToFrontSolution(pyramid **_pyramid){
    pyramid *memorizationPyramid=NULL;
    pyramidGenericInit(&memorizationPyramid, (*_pyramid)->size);
    for(int j=0; j<(*_pyramid)->size; j++){
        (memorizationPyramid)->_pyramidItem[(*_pyramid)->size-1][j].content=(*_pyramid)->_pyramidItem[(*_pyramid)->size-1][j].content;
    }
    for(int i=(*_pyramid)->size-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            if((*_pyramid)->_pyramidItem[i][j].content+(memorizationPyramid)->_pyramidItem[i+1][j].content>(*_pyramid)->_pyramidItem[i][j].content+(memorizationPyramid)->_pyramidItem[i+1][j+1].content){
                (memorizationPyramid)->_pyramidItem[i][j].content=(memorizationPyramid)->_pyramidItem[i+1][j].content+(*_pyramid)->_pyramidItem[i][j].content;
            }else{
                (memorizationPyramid)->_pyramidItem[i][j].content=(memorizationPyramid)->_pyramidItem[i+1][j+1].content+(*_pyramid)->_pyramidItem[i][j].content;
            }
        }
    }
    pyramidShowBiggerWay(_pyramid, &memorizationPyramid,0, 0);
    printf("Maior Soma: %d unidade(s)\n", (memorizationPyramid)->_pyramidItem[0][0].content);
    pyramidDeletePyramid(&memorizationPyramid);
}

int pyramidTheLargestOfTwoNumbers(int number1, int number2);

void pyramidShowPyramid(pyramid **_pyramid){
    for(int i=0; i<(*_pyramid)->size; i++){
        for(int j=0; j<=i; j++){
            printf("%d ",(*_pyramid)->_pyramidItem[i][j].content);
        }
        printf("\n");
    }
}

void pyramidShowBiggerWay(pyramid **_pyramid, pyramid **weightPyramid, int i, int j){
    printf("Coordenadas: %d, %d | Conteúdo: %d\n", i, j, (*_pyramid)->_pyramidItem[i][j].content);
    if(i<(*weightPyramid)->size-1){
        if((*weightPyramid)->_pyramidItem[i+1][j].content>(*weightPyramid)->_pyramidItem[i+1][j+1].content){
            pyramidShowBiggerWay(_pyramid, weightPyramid, i+1, j);
        }else{
            pyramidShowBiggerWay(_pyramid, weightPyramid, i+1, j+1);
        }
    }
    return;
}