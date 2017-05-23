#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListGraph.h"
#include "../../common.h"


int getVertexIndex(ListGraph graph, VertexInfoType vertex_info)
{
    int i;
    for (i = 0; i < graph.vertex_num; ++i)
        if (vertex_info == (graph.vertices + i)->info)
            break;
    return i;
}


void addAdjoinVertex(ListGraph *graph, int vertex_index, AdjoinVertex *adjoin_vertex)
{
    AdjoinVertex *p = (graph->vertices + vertex_index)->first_adjoin_vertex;

    if (!p)
    {
        //(graph->vertices + vertex_index)->first_adjoin_vertex = adjoin_vertex;
        p = adjoin_vertex;
        printf("...%c", (graph->vertices[p->index_in_vertices]).info);
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
            printf("...%c", (graph->vertices[p->index_in_vertices]).info);
        }
        p->next = adjoin_vertex;

        printf("...%c", (graph->vertices[p->next->index_in_vertices]).info);
    }
}


int createUDG(ListGraph *graph)
{
    int i, j, k;
    VertexInfoType v1, v2;
    AdjoinVertex *adv_i, *adv_j;

    // 初始化图
    printf("\n***无向图信息:");
    printf("\n- 顶点数: ");
    scanf("%u", &graph->vertex_num);
    printf("- 边数: ");
    scanf("%u", &graph->arc_num);
    getchar();
    printf("\n***构造无向图\n");

    graph->type = UDG;

    // 初始化顶点
    graph->vertices = (Vertex *)malloc(graph->vertex_num * sizeof(Vertex));
    for (i = 0; i < graph->vertex_num; ++i)
    {
        printf("- 构造第%d个顶点, 输入顶点信息:", i+1);
        scanf("%c", &(graph->vertices + i)->info);
        getchar();

        (graph->vertices + i)->first_adjoin_vertex = NULL;
    }

    /*
     * 初始化边
     */
    printf("\n***输入边所连接的两个顶点(共%d条边)\n", graph->arc_num);
    for (k = 0; k < graph->arc_num; ++k)
    {
        printf("- 构造第%d条边:", k+1);
        scanf("%c %c", &v1, &v2);
        getchar();

        i = getVertexIndex(*graph, v1);
        j = getVertexIndex(*graph, v2);
        
        adv_i = (AdjoinVertex *)malloc(sizeof(AdjoinVertex));
        adv_i->index_in_vertices = j;
        adv_i->arc_info = 1;
        adv_i->next = NULL;
        adv_j = (AdjoinVertex *)malloc(sizeof(AdjoinVertex));
        adv_j->index_in_vertices = i;
        adv_j->arc_info = 1;
        adv_j->next = NULL;
        addAdjoinVertex(graph, i, adv_i);
        addAdjoinVertex(graph, j, adv_j);
        adv_i = adv_j = NULL;
    }

    return EXECUTE_SUCCESS;
}


void printListGraph(ListGraph graph)
{
    int i;
    AdjoinVertex *adjoin_vertex_list;

    printf("\n邻接表: \n");
    for (i = 0; i < graph.vertex_num; ++i)
    {
        printf("%c: ", (graph.vertices + i)->info);
        
        adjoin_vertex_list = (graph.vertices + i)->first_adjoin_vertex;
        while (!adjoin_vertex_list)
        {
            printf("%c ", (graph.vertices + adjoin_vertex_list->index_in_vertices)->info);
            adjoin_vertex_list = adjoin_vertex_list->next;
        }
        printf("\n");
    }
}
