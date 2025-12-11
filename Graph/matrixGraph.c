#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"matrixGraph.h"

struct Graph{
    int **matrix;// array of pointers
    int *data;// data in integer
    int totalNode;//total Nodes in graph
    int maxNode;// maximum node that can be allocated in matrix
    int edge;
};

// Initilize graph
Graph *matrixGraphCreate(){
    Graph *g = malloc(sizeof(Graph));
    g->totalNode = 0;
    g->maxNode = 4;
    g->edge = 0;

    g->matrix = malloc((size_t)g->maxNode * sizeof(int *));
    g->data = calloc( (size_t)(g->maxNode *  g->maxNode), sizeof(int));

    for(int index = 0; index <  g->maxNode; index++){
        g->matrix[index] = g->data + index *  g->maxNode;
    }
    return g;
}

// Adds new node in graph
void matrixGraphNewNode(Graph *g){
    if(g->totalNode >= g->maxNode){
        int oldMaxNode = g->maxNode;
        g->maxNode *= 2;
        g->matrix = realloc(g->matrix, (size_t)g->maxNode * sizeof(int *));
        g->data = realloc(g->data , (size_t)(g->maxNode * g->maxNode) * sizeof(int));

        for(int index = 0; index <  g->maxNode; index++){
            g->matrix[index] = g->data + index *  g->maxNode;
        }

        //sets newly allocated memroy to 0
        memset(g->data + oldMaxNode * oldMaxNode, 0, (size_t)((g->maxNode * g->maxNode) - (oldMaxNode * oldMaxNode)) * sizeof(int));
    }
    g->totalNode++;
}

// Adds edge between given nodes
void matrixGraphAddEdge(Graph *g, int node1, int node2){
    if(node1 < 0 || node1 > g->totalNode || node2 < 0 || node2 > g->totalNode){
        printf("Can not access given node.\n");
        exit(1);
    }
    g->matrix[node1][node2] = 1;
    g->matrix[node2][node1] = 1;
    g->edge++;
}

// Removes edge between given nodes
void matrixGraphRemoveEdge(Graph *g, int node1, int node2){
    if(node1 < 0 || node1 > g->totalNode || node2 < 0 || node2 > g->totalNode){
        printf("Can not access given node.\n");
        exit(1);
    }
    g->matrix[node1][node2] = 0;
    g->matrix[node2][node1] = 0;
    g->edge--;
}

// Utility function to see graph matrix
void matrixGraphPrint(Graph *g){
    printf("%8c", ' ');
    for(int i = 0; i < g->totalNode; i++) printf("%6d", i);
    printf("\n");
    
    for(int i = 0; i < (g->totalNode + 1); i++) printf("======");
    printf("==\n");

    for(int i = 0; i < g->totalNode; i++){
        printf("%6d |", i);
        for(int j = 0; j < g->totalNode; j++){
            printf("%6d", g->matrix[i][j]);
        }
        printf("\n");
    }
}

// Returns total nodes in given graph
int matrixGraphTotalNode(Graph *g){
    return g->totalNode;
}

// Returns total edges in given graph
int matrixGraphTotalEdge(Graph *g){
    return g->edge;
}

// Frres memory of graph
void matrixGraphFree(Graph *g){
    free(g->data);
    free(g->matrix);
    free(g);
}