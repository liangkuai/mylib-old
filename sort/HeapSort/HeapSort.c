#include <stdio.h>
#include "HeapSort.h"
#include "../../heap/BinaryHeap/BinaryHeap.h"

void MaxHeapSort(Heap heap, unsigned int length)
{
    int i;

    for (i = length / 2; i > 0; --i)
        adjustMaxBinaryHeap(heap, i, length);

    for (i = length; i > 1; --i)
    {
        swap(*heap, *(heap + i));
        adjustMaxBinaryHeap(heap, 1, i-1);
    }
}

void MinHeapSort(Heap heap, unsigned int length)
{
    int i;
    for (i = length / 2; i > 0; --i)
        adjustMinBinaryHeap(heap, i, length);

    for (i = length; i > 1; --i)
    {
        swap(*heap, *(heap + i));
        adjustMinBinaryHeap(heap, 1, i-1);
    }
}
