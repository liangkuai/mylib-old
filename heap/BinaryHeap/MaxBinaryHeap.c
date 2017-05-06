#include <stdio.h>
#include "BinaryHeap.h"

void adjustMaxBinaryHeap(Heap heap, unsigned int start, unsigned int end)
{
    unsigned int current       = start;
    unsigned int current_child = start * 2;
    ElemType     current_val   = *(heap + current);

    for (; current_child <= end;)
    {
        if (current_child < end && *(heap + current_child) < *(heap + current_child + 1))
            ++current_child;
        if (current_val > *(heap + current_child))
            break;
        else
        {
            *(heap + current) = *(heap + current_child);
            *(heap + current_child) = current_val;
        }

        current = current_child;
        current_child *= 2;
    }
}

int createMaxBinaryHeap(Heap heap, unsigned int length)
{
    int i;

    for (i = length / 2; i >= 0; --i)
        adjustMaxBinaryHeap(heap, i, length);

    return 0;
}
