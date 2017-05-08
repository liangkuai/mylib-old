#include <stdio.h>
#include "BinaryHeap.h"
#include "../../common.h"

void adjustMaxBinaryHeap(Heap *heap, unsigned int start, unsigned int end)
{
    unsigned int current       = start;
    unsigned int current_child = start * 2 + 1;
    ElemType     start_val     = *(heap->head + current);

    for (; current_child <= end;)
    {
        if (current_child < end
            && *(heap->head + current_child) < *(heap->head + current_child + 1))
            ++current_child;
        if (start_val > *(heap->head + current_child))
            break;
        else
            *(heap->head + current) = *(heap->head + current_child);

        current = current_child;
        current_child = current_child * 2 + 1;
    }
    *(heap->head + current) = start_val;
}


int createMaxBinaryHeap(Heap *heap)
{
    int i;

    // 树的最后一个非叶节点 length/2-1
    for (i = heap->length / 2 - 1; i >= 0; --i)
        adjustMaxBinaryHeap(heap, i, heap->length -1);

    return EXECUTE_SUCCESS;
}


int heapEmpty(const Heap heap)
{
    if (heap.length > 0)
        return TRUE;
    else
        return FALSE;
}


int getMaxElem(const Heap *heap, ElemType *max_elem)
{
    if (heapEmpty(*heap))
        return EXECUTE_FAILURE;

    max_elem = head->head;
    return EXECUTE_SUCCESS;
}
