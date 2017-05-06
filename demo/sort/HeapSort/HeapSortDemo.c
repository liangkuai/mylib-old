#include <stdio.h>
#include "../../../heap/BinaryHeap/BinaryHeap.h"
#include "../../../sort/HeapSort/HeapSort.h"

#define LENGTH(a) ( (sizeof(a))/(sizeof(a[0])) )

int main()
{	
	int i;
	ElemType a[] = {0,20,30,90,40,70,110,60,10,100,50,80};
	int ilen = LENGTH(a);

	printf("before sort:");
	for (i=1; i<ilen; i++)
		printf("%d ", a[i]);
	printf("\n");

	MaxHeapSort(a, ilen);			// 升序排列
	//MinHeapSort(a, ilen);		// 降序排列

	printf("after  sort:");
	for (i=1; i<ilen; i++)
		printf("%d ", a[i]);
	printf("\n");
}
