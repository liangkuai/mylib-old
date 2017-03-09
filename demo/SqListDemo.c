#include <stdio.h>
#include "../list/SqList/SqList.h"

int main()
{
    int res;
    SqList list;

    res = InitList(&list);

    printf("res = %d", res);

    return 0;
}
