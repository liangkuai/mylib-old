#include <stdio.h>
#include "../list/SqList/SqList.h"

void output(SqList *list)
{
    int i;

    printf("list size: %u\n", list->size);
    printf("list elem_num: %u\n", list->elem_num);

    if (list->first_elem == NULL)
    {
        printf("list is NULL");
    }
    else
    {
        for (i = 0; i < list->elem_num; ++i)
        {
            printf("list %d elem: %d\n", i, *(list->first_elem + i));
        }
    }
}

int main()
{
    int res;
    SqList list;

    res = InitList(&list);
    printf("init res = %d\n", res);
    print(&list);
    //output(&list);

    res = DestoryList(&list);
    printf("destory list: %d\n", res);
    print(&list);
    //output(&list);

    return 0;

}
