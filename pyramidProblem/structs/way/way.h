#ifndef WAY
#define WAY

#include <stdio.h>
#include <stdlib.h>

typedef struct path{
    int content;
    int i;
    int j;
    struct path *_path;
}path;

typedef struct way{
    int distance;
    path *path;
}way;

void wayInit(way *_way);
void wayInsertPath(way *_way, int content, int i, int j);
void wayDeleteWay(way *_way);
void wayDeletePaths(path *_path);
void wayShowWay(way *_way);
void wayShowPaths(path *_path);

#endif