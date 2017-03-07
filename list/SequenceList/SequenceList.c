#include "dynamic_array.h"
#include "stdio.h"
#include "stdlib.h"

int InitSequencdeList (SequenceList &list)
{
    list.first_elem_addr = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (list.first_elem_addr == NULL)
    {
        // 内存分配失败
        return EXCUTE_FAILURE;
    }

    list.elem_num = 0;
    list.size = LIST_INIT_SIZE;

    return EXCUTE_SUCCESS;
}

bool ListEmpty (SequenceList list)
{
    if (list.elem_num == 0)
        return true;
    else
        return false;
}

bool ClearList (SequenceList list)
{
    if (list.elem_num != 0)
    {
        free(list.first_elem_addr);
        first_elem_addr = NULL;

        list.first_elem_addr = (ElemType *)malloc(list.size * sizeof(ElemType));
        if (list.first_elem_addr == NULL)
        {
            // 内存分配失败
            return EXCUTE_FAILURE;
        }
    }
    return EXCUTE_SUCCESS;
}
