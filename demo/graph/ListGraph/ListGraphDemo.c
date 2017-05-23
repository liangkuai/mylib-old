#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../common.h"
#include "../../../graph/ListGraph/ListGraph.h"

int main()
{
    int res;
    ListGraph graph1;

    res = createUDG(&graph1);
    printListGraph(graph1);

    return 0;
}
