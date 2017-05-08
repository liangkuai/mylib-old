#include <stdio.h>
#include <stdlib.h>
#include "../../../heap/BinaryHeap/BinaryHeap.h"
#include "../../../sort/HeapSort/HeapSort.h"

#define LENGTH(a) ( (sizeof(a))/(sizeof(a[0])) )

int main()
{	
	int i;
    ElemType a[] = {0,20,30,90,40,70,110,60,10,100,50,80};

    Heap heap;
    heap.head = (ElemType *)malloc(50 * sizeof(ElemType));
    heap.length = 0;

    for (i = 0; i < 12; ++i)
    {
        *(heap.head + i) = a[i];
        ++heap.length;
    }

	//int ilen = LENGTH(heap.head);
    //printf("length: %d\n", ilen);

	printf("before sort:");
	for (i=0; i<heap.length; i++)
		printf("%d ", heap.head[i]);
	printf("\n");

	MaxHeapSort(&heap);			// 升序排列
	//MinHeapSort(&heap);		// 降序排列

	printf("after  sort:");
	for (i=0; i<heap.length; i++)
		printf("%d ", heap.head[i]);
	printf("\n");

    return 0;
}
