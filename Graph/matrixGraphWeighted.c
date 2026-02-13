#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"matrixGraphWeighted.h"

struct Graph{
    float **matrix;// array of pointers
    float *data;// data in integer
    int totalNode;//total Nodes in graph
    int maxNode;// maximum node that can be allocated in matrix
    int edge;
};

// Initilize graph
Graph *matrixGraphWCreate(void){
    Graph *g = malloc(sizeof(Graph));
    g->totalNode = 0;
    g->maxNode = 4;
    g->edge = 0;

    g->matrix = malloc((size_t)g->maxNode * sizeof(float *));
    g->data = calloc( (size_t)(g->maxNode *  g->maxNode), sizeof(float));

    for(int index = 0; index <  g->maxNode; index++){
        g->matrix[index] = g->data + index *  g->maxNode;
    }
    return g;
}

// Adds new node in graph
void matrixGraphWNewNode(Graph *g){
    if(g->totalNode >= g->maxNode){
        int oldMaxNode = g->maxNode;
        g->maxNode *= 2;
        g->matrix = realloc(g->matrix, (size_t)g->maxNode * sizeof(float *));
        g->data = realloc(g->data , (size_t)(g->maxNode * g->maxNode) * sizeof(float));

        for(int index = 0; index <  g->maxNode; index++){
            g->matrix[index] = g->data + index *  g->maxNode;
        }

        //sets newly allocated memroy to 0
        memset(g->data + oldMaxNode * oldMaxNode, 0, (size_t)((g->maxNode * g->maxNode) - (oldMaxNode * oldMaxNode)) * sizeof(float));
    }
    g->totalNode++;
}

// Adds edge between given nodes
void matrixGraphWAddEdge(Graph *g, int node1, int node2, float weight){
    if(node1 < 0 || node1 > g->totalNode || node2 < 0 || node2 > g->totalNode){
        printf("Can not access given node.\n");
        exit(1);
    }
    g->matrix[node1][node2] = weight;
    g->matrix[node2][node1] = weight;
    g->edge++;
}

// Removes edge between given nodes
void matrixGraphWRemoveEdge(Graph *g, int node1, int node2){
    if(node1 < 0 || node1 > g->totalNode || node2 < 0 || node2 > g->totalNode){
        printf("Can not access given node.\n");
        exit(1);
    }
    g->matrix[node1][node2] = 0;
    g->matrix[node2][node1] = 0;
    g->edge--;
}

// Utility function to see graph matrix
void matrixGraphWPrint(Graph *g){
    printf("%10c", ' ');
    for(int i = 0; i < g->totalNode; i++) printf("%8d", i);
    printf("\n");
    
    for(int i = 0; i < (g->totalNode + 1); i++) printf("========");
    printf("==\n");

    for(int i = 0; i < g->totalNode; i++){
        printf("%8d |", i);
        for(int j = 0; j < g->totalNode; j++){
            printf("%8.3f", g->matrix[i][j]);
        }
        printf("\n");
    }
}

// Returns true if given node contain edge
int martrixGraphWNodeContainEdge(Graph *g, int node){
    for(int i = 0; i<g->totalNode; i++) if(g->matrix[node][i] != 0) return 1;
    return 0;
}

// Returns total nodes in given graph
int matrixGraphWTotalNode(Graph *g){
    return g->totalNode;
}

// Returns total edges in given graph
int matrixGraphWTotalEdge(Graph *g){
    return g->edge;
}

// Frees memory of graph
void matrixGraphWFree(Graph *g){
    free(g->data);
    free(g->matrix);
    free(g);
}
