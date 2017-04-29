#include "../../common.h"
#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>


int DestoryList(SqList *list)
{
    if (list != NULL)
    {
        if (list->first_elem != NULL)
       {   
           free(list->first_elem);
           list->first_elem = NULL;
       }
       list->elem_num = 0;
       list->size = 0;
    }
    else
    {
        // 顺序表结构体未分配内存空间
        return EXECUTE_FAILURE;
    }

    return EXECUTE_SUCCESS;
}


int InitList(SqList *list)
{
    if (list == NULL)
    {
        // 顺序表结构体未分配内存空间
        return EXECUTE_FAILURE;
    }

    list->first_elem = (ElemType *)calloc(LIST_INIT_SIZE, sizeof(ElemType));
    if (list->first_elem == NULL)
    {
        // 内存分配失败
        return EXECUTE_FAILURE;
    }

    list->elem_num = 0;
    list->size = LIST_INIT_SIZE;

    return EXECUTE_SUCCESS;
}

/*
int checkInit(SqList *list)
{
    if (list
        && list->size >= LIST_INIT_SIZE
        && list->elem_num >= 0)
        return TRUE;
    else
        return FALSE;
}


int AddListSize(SqList *list, unsigned int increase_size)
{
    // 新定义一个指针指向新地址，防止原内存空间泄露
    ElemType *new_list = NULL;

    if (increase_size == 0)
    {
        // 不使用 LIST_INCREASE_SIZE
        new_list = (ElemType *)realloc(
            list->first_elem_addr, (list->size + (list_size >> 2)));

        list->size = list->size + LIST_INCREASE_SIZE;
    }
    else
    {
        new_list = (ElemType *)realloc(
            list->first_elem_addr, (list->size + increase_size));

        list->size = list->size + increase_size;
    }

    if (new_list == NULL)
    {
        // 内存分配失败
        return EXECUTE_FAILURE;
    }

    list-first_elem_addr = new_list;

    return EXECUTE_SUCCESS;
}


int ListEmpty(const SqList list)
{
    if (list.elem_num == 0)
        return TRUE;
    else
        return FALSE;
}


int ClearList(SqList *list)
{
    if (ListEmpty(*list))
    {
        // 顺序表为空
        return EXECUTE_FAILURE;
    }

    if (!ListEmpty(*list))
    {
        free(list->first_elem_addr);
        list->first_elem_addr = NULL;

        list->first_elem_addr = (ElemType *)calloc(
            list->size, sizeof(ElemType));

        if (list->first_elem_addr == NULL)
        {
            // 内存分配失败
            return EXECUTE_FAILURE;
        }
    }
    return EXECUTE_SUCCESS;
}


unsigned int GetElemNum(const SqList list)
{
    return list.elem_num;
}


void GetElem(SqList list, unsigned int i, ElemType *elem)
{
    if (i < 1 || i > list.elem_num)
    {
        // 参数异常，不存在第i个元素
        elem = NULL;
    }
    elem = list.first_elem_addr + i - 1;
}


int AddElem(SqList *list, ElemType *elem)
{
    // 添加元素前都需要判断顺序表空间是否足够
    if (list->elem_num >= list->size)
    {
        if (AddListSize(list, 0))
        {
            // 增加顺序表空间失败
            return EXECUTE_FAILURE;
        }
    }

    (list->first_elem_addr + list->elem_num) = elem;
    ++list->elem_num;

    return EXECUTE_SUCCESS;
}

*
int AddElemByIndex(SqList *list, unsigned int i, ElemType *elem)
{
    int j;
    
    if (i < 1 || i > list->elem_num)
    {
        // 参数异常，不存在第i个元素
        return EXECUTE_FAILURE;
    }

    if (list->elem_num >= list->size)
    {
        if (AddListSize(list, 0))
        {
            // 增加顺序表空间失败
            return EXECUTE_FAILURE;
        }
    }

    for (j = list->size-1; j > i-1; --j)
    {
        (list->elem_num + j) = (list->elem_num + j - 1);
    }
    (list->elem_num + j) = elem;
    ++list->elem_num;

    return EXECUTE_SUCCESS;
}*/


void print(const SqList *list)
{
    int i;

    if (list != NULL)
    {
        printf("********************\n");
        printf("长度: %u\n", list->size);
        printf("内容: %u\n", list->elem_num);
        if (list->first_elem != NULL)
        {
            for (i = 0; i < list->elem_num; ++i)
                printf("%d\n", *(list->first_elem + i));
        }
        printf("********************\n");
    }
}
