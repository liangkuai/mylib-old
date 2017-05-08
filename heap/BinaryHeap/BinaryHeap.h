/**
 * 二叉堆
 *
 * 采用动态分配数组(即顺序结构)表示堆,
 * 数组下标从0开始表示堆元素.
 *
 * @author liangkuai
 * @data 2017.05.06
 */


#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_


// 堆元素
typedef int ElemType;

// 堆
typedef struct _Heap
{
    ElemType *head;
    unsigned int length;
    unsigned int size;
} Heap;


/**
 * 调整堆
 *
 * @heap 堆
 * @start 调整节点起始位置
 * @end 调整节点截止位置
 */
void adjustMaxBinaryHeap(Heap *heap, unsigned int start, unsigned int end);

void adjustMinBinaryHeap(Heap *heap, unsigned int start, unsigned int end);

/**
 * 创建堆
 *
 * @heap 堆
 * @length 堆大小 
 */
int createMaxBinaryHeap(Heap *heap);

int creataMinBinaryHeap(Heap *heap);

/**
 * 判断空堆
 *
 * @heap 堆
 */
int heapEmpty(const Heap heap);

/**
 * 获取堆顶元素
 *
 * @heap 堆
 */
int getMaxElem(const Heap *heap, ElemType *max_elem);

int getMinElem(const Heap *heap, ElemType *max_elem);

#endif  // _BINARY_HEAP_H_
