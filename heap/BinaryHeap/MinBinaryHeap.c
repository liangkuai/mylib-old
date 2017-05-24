#include <stdio.h>
#include <stdlib.h>
#include "BinaryHeap.h"
#include "../../common.h"

void adjustMinBinaryHeap(Heap *heap, unsigned int start, unsigned int end)
{
    unsigned int current       = start;
    unsigned int current_child = current * 2 + 1;
    ElemType     start_val     = *(heap->head + current);

    while (current_child <= end)
    {
        if (current_child < end
            && *(heap->head + current_child) > *(heap->head + current_child + 1))
            ++current_child;
        if (start_val < *(heap->head + current_child))
            break;
        else
            *(heap->head + current) = *(heap->head + current_child);

        current = current_child;
        current_child = current * 2 + 1;
    }
    *(heap->head + current) = start_val;
}

void adjustUpMinBinaryHeap(Heap *heap, unsigned int start)
{
    unsigned int current        = start;
    unsigned int current_parent = (current - 1) / 2;
    ElemType     start_val      = *(heap->head + current);

    while (current > 0)
    {
        if (start_val < *(heap->head + current_parent))
        {
            *(heap->head + current) = *(heap->head + current_parent);
            current = current_parent;
            current_parent = (current - 1) / 2;
        }
        else
            break;
    }
    *(heap->head + current) = start_val;
}


int createMinBinaryHeap(Heap *heap, ElemType *elem_list)
{
    int i;

    heap->head = (ElemType *)malloc(HEAP_INIT_SIZE * sizeof(ElemType));
    heap->size = HEAP_INIT_SIZE;

    for (i = 0; i < heap->length; ++i)
    {
        *(heap->head + i) = *(elem_list + i);
    }

    for (i = heap->length / 2 - 1; i >= 0; --i)
        adjustMinBinaryHeap(heap, i, heap->length - 1);

    return 0;
}


int heapEmpty(const Heap heap)
{
    if (heap.length > 0)
        return TRUE;
    else
        return FALSE;
}


int getTopOfMinBinaryHeap(const Heap heap, ElemType *min_elem)
{
    if (heapEmpty(heap))
        return EXECUTE_FAILURE;

    *min_elem = *heap.head;
    return EXECUTE_SUCCESS;
}


int removeTopOfMinBinaryHeap(Heap *heap, ElemType *min_elem)
{
    int i;

    *min_elem = *heap->head;
    *heap->head = *(heap->head + heap->length - 1);
    *(heap->head + heap->length - 1) = 0;
    --heap->length;

    for (i = heap->length/2 - 1; i >= 0; --i)
    {
        adjustMinBinaryHeap(heap, i, heap->length-1);
    }

    return EXECUTE_SUCCESS;
}


int addHeapSize(Heap *heap)
{
    ElemType *new_heap = NULL;

    /*
     * 扩展堆大小
     * 原大小 + 50
     */
    new_heap = (ElemType *)realloc(heap->head,
        (heap->size + HEAP_INCREASE_SIZE) * sizeof(ElemType));
    if (!new_heap)
    {
        // 内存分配失败
        return EXECUTE_FAILURE;
    }
    heap->size = heap->size + HEAP_INCREASE_SIZE;
    heap->head = new_heap;

    return EXECUTE_SUCCESS;
}


int addElemToMinBinaryHeap(Heap *heap, ElemType new_elem)
{
    int i;

    // 堆满
    if (heap->length >= heap->size)
    {
        // 扩展堆大小
        if (!addHeapSize(heap))
        {
            return EXECUTE_FAILURE;
        }
    }

    // 添加堆元素
    *(heap->head + heap->length) = new_elem;
    ++heap->length;
    
    adjustUpMinBinaryHeap(heap, heap->length - 1);

    /*
    for (i = heap->length/2 - 1; i >= 0; --i)
    {
        adjustMinBinaryHeap(heap, i, heap->length - 1);
    }*/

    return EXECUTE_SUCCESS;
}


void printMinBinaryHeap(const Heap heap)
{
    int i;
    for (i = 0; i <heap.length; ++i)
    {
        printf("%d ", *(heap.head + i));
    }
    printf("\n");
}
