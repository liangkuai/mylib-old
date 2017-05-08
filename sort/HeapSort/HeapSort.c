#include <stdio.h>
#include "HeapSort.h"
//#include "../../heap/BinaryHeap/BinaryHeap.h"
#include "../../common.h"

void MaxHeapSort(Heap *heap)
{
    int i;

    for (i = heap->length / 2 - 1; i >= 0; --i)
        adjustMaxBinaryHeap(heap, i, heap->length - 1);

    for (i = heap->length - 1; i > 0; --i)
    {
        swap(*heap->head, *(heap->head + i));
        adjustMaxBinaryHeap(heap, 0, i-1);
    }
}

void MinHeapSort(Heap *heap)
{
    int i;

    for (i = heap->length / 2 - 1; i >= 0; --i)
        adjustMinBinaryHeap(heap, i, heap->length - 1);

    for (i = heap->length - 1; i > 0; --i)
    {
        swap(*heap->head, *(heap->head + i));
        adjustMinBinaryHeap(heap, 0, i-1);
    }
}
