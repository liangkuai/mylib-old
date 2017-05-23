/**
 * 图, 邻接表
 *
 * @author liangkuai
 * @data 2017.05.13
 */


#ifndef _LIST_GRAPH_H_
#define _LIST_GRAPH_H_

typedef char VertexInfoType;
typedef int ArcInfoType;
typedef enum {UDG, UDN, DG, DN} GraphType;

typedef struct _AdjoinVertex
{
    int index_in_vertices;
    ArcInfoType arc_info;
    struct _AdjoinVertex *next;
} AdjoinVertex;

typedef struct _Vertex
{
    VertexInfoType info;
    struct _AdjoinVertex *first_adjoin_vertex;
} Vertex;

typedef struct _ListGraph
{
    unsigned int vertex_num;
    unsigned int arc_num;
    Vertex *vertices;
    GraphType type;
} ListGraph;



int getVertexIndex(ListGraph graph, VertexInfoType vertex_info);

void addAdjoinVertex(ListGraph *graph, int vertex_index, AdjoinVertex *adjoin_vertex);

int createUDG(ListGraph *graph);


void printListGraph(ListGraph graph);

#endif  // _LIST_GRAPH_H_
