/**
 * SqList.h
 *
 * 顺序表，动态数组
 * 
 * Create by liangkuai
 *
 * Date: 2017/03/07
 */



#ifndef _SQLIST_H
#define _SQLIST_H


#define LIST_INIT_SIZE 100
#define LIST_INCREASE_SIZE 10


/*
 * Definition of SequenceList
 */

typedef int ElemType;

typedef struct
{
    ElemType *first_elem_addr;
    unsigned int elem_num;
    unsigned int size;
} SqList;


extern int InitList(SqList *list);

int ListEmpty(SqList list);

int ClearList(SqList *list);

int DestoryList(SqList *list);

unsigned int GetElemNum(SqList list);

ElemType GetElem(SqList list, unsigned int i);


#endif // _SQLIST_H
