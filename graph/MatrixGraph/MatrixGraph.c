#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MatrixGraph.h"
#include "../../common.h"


int getVertexIndex(const MatrixGraph graph, Vertex vertex)
{
    int i;
    for (i = 0; i < graph.vertex_num; ++i)
        if (vertex == graph.vertices[i])
            break;
    return i;
}


int createTestUDN(MatrixGraph *graph)
{
    int i, j, k;

    Vertex vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    Vertex edges[][2] = {
       {'A', 'C'},
       {'A', 'D'},
       {'A', 'F'},
       {'B', 'C'},
       {'C', 'D'},
       {'E', 'G'},
       {'F', 'G'}};
    Arc edges_weight[] = {2, 10, 4, 5, 1, 8, 6};

    graph->type = UDG;
    graph->vertex_num = LENGTH(vertices);
    graph->arc_num = LENGTH(edges);

    for (i = 0; i < graph->vertex_num; ++i)
        graph->vertices[i] = vertices[i];

    for (i = 0; i < graph->vertex_num; ++i)
        for (j = 0; j < graph->vertex_num; ++j)
            graph->arcs[i][j] = 0;

    for (k = 0; k < graph->arc_num; ++k)
    {
        i = getVertexIndex(*graph, edges[k][0]);
        j = getVertexIndex(*graph, edges[k][1]);
        graph->arcs[i][j] = graph->arcs[j][i] = edges_weight[k];
    }
    return EXECUTE_SUCCESS;
}


int createUDG(MatrixGraph *graph)
{
    int i, j, k;
    Vertex v1, v2;

    graph->type = UDG;

    // 初始化图
    printf("\n***无向图信息:");
    printf("\n- 顶点数: ");
    scanf("%u", &graph->vertex_num);
    printf("- 边数: ");
    scanf("%u", &graph->arc_num);
    getchar();
    printf("\n***构造无向图(顶点不超过%d)\n", MAX_VERTEX_NUM);

    // 初始化顶点
    for (i = 0; i < graph->vertex_num; ++i)
    {
        printf("- 构造第%d个顶点，输入顶点信息:", i+1);
        scanf("%c", &graph->vertices[i]);
        getchar();
    }

    /*
     * 初始化边
     * 无向图的边，若两顶点相连则边置为１，反之置为０
     */
    for (i = 0; i < graph->vertex_num; ++i)
    {
        for (j = 0; j < graph->vertex_num; ++j)
        {
            graph->arcs[i][j] = 0;
        }
    }

    printf("\n***输入边所连接的两个顶点(共%d条边)\n", graph->arc_num);
    // 建立矩阵
    for (k = 0; k < graph->arc_num; ++k)
    {
        /*
         * 输入两个顶点，
         * 根据顶点值从顶点数组中获取两个顶点的下标i, j
         * 由于无向图的邻接矩阵是对角矩阵，[i][j]和[j][i]对应边都要置为1
         */
        printf("构造第%d条边:", k+1);
        scanf("%c %c", &v1, &v2);
        getchar();
        i = getVertexIndex(*graph, v1);
        j = getVertexIndex(*graph, v2);
        printf("%d, %d\n", i, j);
        graph->arcs[j][i] = graph->arcs[i][j] = 1;
    }

    return EXECUTE_SUCCESS;
}


int firstAdjoinVertexIndex(MatrixGraph graph, int vertex_index)
{
    int i;

    for (i = 0; i < graph.vertex_num; ++i)
        if (graph.arcs[vertex_index][i] > 0)
            break;
    return i;
}

int nextAdjoinVertexIndex(MatrixGraph graph, int vertex_index,int adjoin_vertex_index)
{
    int i;
    for (i = adjoin_vertex_index+1; i < graph.vertex_num; ++i)
        if (graph.arcs[vertex_index][i] > 0)
            break;
    return i;
}


int DFSTraverse(MatrixGraph *graph)
{
    int i;
    
    // 初始化访问数组
    int *visited = (int *)malloc(graph->vertex_num * sizeof(int));
    if (!visited)
    {
        // 内存分配失败
        return EXECUTE_FAILURE;
    }
    memset(visited, FALSE, graph->vertex_num);

    printf("\n***DFS: ");
    for (i = 0; i < graph->vertex_num; ++i)
    {
        if (!visited[i])
            DFS(graph, i, visited);
    }

    return EXECUTE_SUCCESS;
}

void DFS(MatrixGraph *graph, int i, int *visited)
{
    int next;
    
    *(visited + i) = TRUE;

    printf("%c ", graph->vertices[i]);

    next = firstAdjoinVertexIndex(*graph, i);
    for (; next < graph->vertex_num;)
    {
        if (!visited[next])
            DFS(graph, next, visited);
        next = nextAdjoinVertexIndex(*graph, i, next);
    }
}


void BFS(MatrixGraph *graph)
{
    int vertex_indices[MAX_VERTEX_NUM];
    int now_index, rear_index;
    int i, j, next;

    int *visited = (int *)malloc((graph->vertex_num+1) * sizeof(int));
    if (!visited)
    {
        // 内存分配失败
    }
    memset(visited, FALSE, graph->vertex_num);
    
    now_index = rear_index = 0;

    printf("\n***BFS: ");
    for (i = 0; i < graph->vertex_num; ++i)
    {
        if (visited[i])
            break;

        vertex_indices[rear_index++] = i;
        *(visited + i) = TRUE;
        printf("%c ", graph->vertices[i]);
        while (now_index < rear_index)
        {
            j = vertex_indices[now_index++];

            next = firstAdjoinVertexIndex(*graph, j);
            for (; next < graph->vertex_num;)
            {
                if (!visited[next])
                {
                    vertex_indices[rear_index++] = next;
                    *(visited + next) = TRUE;
                    printf("%c ", graph->vertices[next]);
                }
                next = nextAdjoinVertexIndex(*graph, j, next);
            }
        }
    }
}


void printMatrixGraph(const MatrixGraph graph)
{
    int i, j;

    printf("\n***顶点\n");
    for (i = 0; i < graph.vertex_num; ++i)
        printf("- 顶点%d: %c\n", i+1, graph.vertices[i]);

    printf("\n***邻接矩阵\n");
    for (i = 0; i < graph.vertex_num; ++i)
    {
        for (j = 0; j < graph.vertex_num; ++j)
            printf("%3d", graph.arcs[i][j]);
        printf("\n");
    }
}
