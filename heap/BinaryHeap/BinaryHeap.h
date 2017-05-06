/**
 * 二叉堆
 *
 * 采用动态分配数组(即顺序结构)表示堆,
 * 数组下标从1开始表示堆元素.
 *
 * @author liangkuai
 * @data 2017.5.6
 */


#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_


typedef int ElemType, *Heap;


/**
 * 调整堆
 *
 * @heap 堆
 * @start 调整节点起始位置
 * @end 调整节点截止位置
 */
void adjustMaxBinaryHeap(Heap heap, unsigned int start, unsigned int end);

void adjustMinBinaryHeap(Heap heap, unsigned int start, unsigned int end);

/**
 * 创建堆
 *
 * @heap 堆
 * @length 堆大小 
 */
int createMaxBinaryHeap(Heap heap, unsigned int length);

int creataMinBinaryHeap(Heap heap, unsigned int length);


#endif  // _BINARY_HEAP_H_
