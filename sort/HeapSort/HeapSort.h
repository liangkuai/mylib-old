/**
 * 堆排序
 *
 * @author liangkuai
 * @data 2017.05.06
 */


#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

#include "../../heap/BinaryHeap/BinaryHeap.h"

#define swap(a,b) (a^=b,b^=a,a^=b)


void MaxHeapSort(Heap heap, unsigned int length);


void MinHeapSort(Heap heap, unsigned int length);


#endif  //_HEAPSORT_H_
