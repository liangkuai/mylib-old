#include <stdio.h>
#include "../../../common.h"
#include "../../../heap/BinaryHeap/BinaryHeap.h"

int main()
{
    Heap heap;
    ElemType min;

    ElemType elem_list[9] = {80, 40, 30, 60, 90, 70, 10, 50, 20};
    heap.length = LENGTH(elem_list);

    createMinBinaryHeap(&heap, elem_list);
    printMinBinaryHeap(heap);

    getTopOfMinBinaryHeap(heap, &min);
    printf("\nmin: %d\n", min);

    removeTopOfMinBinaryHeap(&heap, &min);
    printf("\nmin: %d\n", min);
    printMinBinaryHeap(heap);

    removeTopOfMinBinaryHeap(&heap, &min);
    printf("\nmin: %d\n", min);
    printMinBinaryHeap(heap);

    addElemToMinBinaryHeap(&heap, 65);
    printMinBinaryHeap(heap);


    return 0;
}
