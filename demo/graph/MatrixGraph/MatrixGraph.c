#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../common.h"
#include "../../../graph/MatrixGraph/MatrixGraph.h"

int main()
{
    int res;
    MatrixGraph graph1;
    MatrixGraph graph2;

    res = createTestUDN(&graph1);
    printMatrixGraph(graph1);
    DFSTraverse(&graph1);

    //res = createUDG(&graph2);
    //printMatrixGraph(graph2);

    return 0;
}
