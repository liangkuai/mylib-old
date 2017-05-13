/**
 * 图, 邻接矩阵
 *
 * @author liangkuai
 * @data 2017.05.11
 */


#ifndef _MATRIX_GRAPH_H_
#define _MATRIX_GRAPH_H_


/***** 邻接矩阵 *****/

// 最大顶点数
#define MAX_VERTEX_NUM 20

// 顶点类型
typedef char Vertex;

// 边(弧)类型
typedef int Arc;

/*
 * 图类型
 * UDG 无向图(Undirected graph)
 * DG  有向图(Directed graph)
 * UDN 无向网(Undirected network)
 * DN  有向网(Directed netword)
 */
typedef enum {UDG, UDN, DG, DN} GraphType;

typedef struct _MatrixGraph
{
    unsigned int vertex_num;
    unsigned int arc_num;
    Vertex vertices[MAX_VERTEX_NUM];
    Arc arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    GraphType type;
} MatrixGraph;



int getVertexIndex(const MatrixGraph graph, Vertex vertex);

int createTestUDN(MatrixGraph *graph);

int createUDG(MatrixGraph *graph);

int createUDN(MatrixGraph *graph);

int createDG(MatrixGraph *graph);

int createDN(MatrixGraph *graph);


int firstAdjoinVertexIndex(MatrixGraph graph, int vertex_index);

int nextAdjoinVertexIndex(MatrixGraph graph, int vertex_index, int adjoin_vertex_index);


int DFSTraverse(MatrixGraph *graph);

void DFS(MatrixGraph *graph, int i, int *visited);

void BFS(MatrixGraph *graph);


void printMatrixGraph(const MatrixGraph graph);


/***** 邻接表 *****/

typedef struct _ArcNode
{
    int conn_vertex;
    struct _ArcNode *next_arc;
} ArcNode;

typedef struct _VertexList
{
    Vertex data;
    ArcNode *first_arc;
} VertexList;

typedef struct _ListGraph
{
    unsigned int vertex_num;
    unsigned int arc_num;
    VertexList vertices;
    GraphType type;
} ListGraph;


#endif  // _MATRIX_GRAPH_H_
