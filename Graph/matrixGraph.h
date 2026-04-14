#ifndef __MATRIX_GRAPH__H
#define __MATRIX_GRAPH__H

typedef struct Graph Graph;

Graph *matrixGraphCreate(void);

void matrixGraphNewNode(Graph *g);

int matrixGraphAddEdge(Graph *g, int node1, int node2);

int matrixGraphRemoveEdge(Graph *g, int node1, int node2);

void matrixGraphPrint(Graph *g);

int martrixGraphNodeContainEdge(Graph *g, int node);

int matrixGraphTotalNode(Graph *g);

int matrixGraphTotalEdge(Graph *g);

void matrixGraphFree(Graph *g);

#endif
