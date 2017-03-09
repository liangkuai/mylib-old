#include "../../common.h"
#include "SqList.h"
#include "stdio.h"
#include "stdlib.h"

int InitList(SqList *list)
{
    list->first_elem_addr = (ElemType *)calloc(LIST_INIT_SIZE, sizeof(ElemType));
    if (list->first_elem_addr == NULL)
    {
        // 内存分配失败
        return EXCUTE_FAILURE;
    }

    list->elem_num = 0;
    list->size = LIST_INIT_SIZE;

    return EXCUTE_SUCCESS;
}

int ListEmpty(SqList list)
{
    if (list.elem_num == 0)
        return TRUE;
    else
        return FALSE;
}

int ClearList(SqList *list)
{
    if (!ListEmpty(*list))
    {
        free(list->first_elem_addr);
        list->first_elem_addr = NULL;

        list->first_elem_addr = (ElemType *)calloc(list->size, sizeof(ElemType));
        if (list->first_elem_addr == NULL)
        {
            // 内存分配失败
            return EXCUTE_FAILURE;
        }
    }
    return EXCUTE_SUCCESS;
}

int DestoryList(SqList *list)
{
    if (list->first_elem_addr != NULL)
    {
        free(list->first_elem_addr);
        list->first_elem_addr = NULL;

        list->elem_num = 0;
        list->size = 0;
    }

    return TRUE;
}

unsigned int GetElemNum(SqList list)
{
    return list.elem_num;
}

ElemType GetElem(SqList list, unsigned int i)
{
    return  *(list.first_elem_addr + i);
}
