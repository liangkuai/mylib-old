/**
 * SequenceList.h
 *
 * 顺序表，动态数组
 * 
 * Create by liangkuai
 *
 * Date: 2017/03/07
 */



/*
 * Excute status
 */
#define EXCUTE_SUCCESS 0
#define EXCUTE_FAILURE -1


#define LIST_INIT_SIZE 100
#define LIST_INCREASE_SIZE 10



/*
 * Definition of SequenceList
 */

typedef int ElemType

typedef struct
{
    ElemType *first_elem_addr;
    unsigned int elem_num;
    unsigned int size;
} SequenceList;


int InitSequenceList (SequenceList &list);

bool ListEmpty (SequenceList list);

bool ClearList (SequenceList &list);

bool DestoryLIst (SequenceList &list);
