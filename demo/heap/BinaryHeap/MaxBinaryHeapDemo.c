#include <stdio.h>
#include "../../../common.h"
#include "../../../heap/BinaryHeap/BinaryHeap.h"

int main()
{
    Heap heap;
    ElemType max;

    ElemType elem_list[9] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    heap.length = LENGTH(elem_list);

    createMaxBinaryHeap(&heap, elem_list);
    printMaxBinaryHeap(heap);

    getTopOfMaxBinaryHeap(heap, &max);
    printf("\nmax: %d\n", max);

    removeTopOfMaxBinaryHeap(&heap, &max);
    printf("\nmax: %d\n", max);
    printMaxBinaryHeap(heap);

    removeTopOfMaxBinaryHeap(&heap, &max);
    printf("\nmax: %d\n", max);
    printMaxBinaryHeap(heap);

    addElemToMaxBinaryHeap(&heap, 65);
    printMaxBinaryHeap(heap);

    return 0;
}
