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

// 堆初始大小
#define HEAP_INIT_SIZE 100

// 堆增长大小
#define HEAP_INCREASE_SIZE 50


// 堆元素
typedef int ElemType;

/* 堆
 * head 堆顶
 * length 堆元素个数
 * size 堆总大小
 */
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

void adjustUpMaxBinaryHeap(Heap *heap, unsigned int start);

void adjustUpMinBinaryHeap(Heap *heap, unsigned int start);


/**
 * 创建堆
 *
 * @heap 堆
 * @length 堆大小 
 */
int createMaxBinaryHeap(Heap *heap, ElemType *elem_list);

int createMinBinaryHeap(Heap *heap, ElemType *elem_list);


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
int getTopOfMaxBinaryHeap(const Heap heap, ElemType *max_elem);

int getTopOfMinBinaryHeap(const Heap heap, ElemType *min_elem);


/**
 * 删除堆顶元素
 *
 * @heap 堆
 */
int removeTopOfMaxBinaryHeap(Heap *heap, ElemType *max_elem);

int removeTopOfMinBinaryHeap(Heap *heap, ElemType *min_elem);


/**
 * 扩展堆大小
 *
 * @heap 堆
 */
int addHeapSize(Heap *heap);


/**
 * 添加堆元素
 *
 * @heap 堆
 * @new_elem 新元素
 */
int addElemToMaxBinaryHeap(Heap *heap, ElemType new_elem);

int addElemToMinBinaryHeap(Heap *heap, ElemType new_elem);


// 输出堆
void printMaxBinaryHeap(const Heap heap);

void printMinBinaryHeap(const Heap heap);

#endif  // _BINARY_HEAP_H_
