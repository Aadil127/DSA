#ifndef __matrixGraph__H
#define __matrixGraph__H

typedef struct Graph Graph;

Graph *matrixGraphCreate();

void matrixGraphNewNode(Graph *g);

void matrixGraphAddEdge(Graph *g, int node1, int node2);

void matrixGraphRemoveEdge(Graph *g, int node1, int node2);

void matrixGraphPrint(Graph *g);

int matrixGraphTotalNode(Graph *g);

int matrixGraphTotalEdge(Graph *g);

void matrixGraphFree(Graph *g);

#endif