#ifndef __matrixGraphWeighted__H
#define __matrixGraphWeighted__H

typedef struct Graph Graph;

Graph *matrixGraphWCreate(void);

void matrixGraphWNewNode(Graph *g);

void matrixGraphWAddEdge(Graph *g, int node1, int node2, float weight);

void matrixGraphWRemoveEdge(Graph *g, int node1, int node2);

void matrixGraphWPrint(Graph *g);

int martrixGraphWNodeContainEdge(Graph *g, int node);

int matrixGraphWTotalNode(Graph *g);

int matrixGraphWTotalEdge(Graph *g);

void matrixGraphWFree(Graph *g);

#endif
