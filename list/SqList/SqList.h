/**
 * SqList.h
 *
 * 顺序表，动态数组
 * 
 * Created by liangkuai
 *
 * Date: 2017/03/07
 */



#ifndef _SQLIST_H
#define _SQLIST_H


#define LIST_INIT_SIZE 100
#define LIST_INCREASE_SIZE 10


/*
 * 顺序表定义
 */

typedef int ElemType;

typedef struct
{
    ElemType *first_elem;
    unsigned int elem_num;
    unsigned int size;
} SqList;


/*
 * 初始化顺序表
 *
 * 参数
 *  @ list 顺序表结构体地址
 *
 * 返回值
 *  @  0 执行成功
 *  @ -1 执行失败
 */
int InitList(SqList *list);


/*
 * 销毁顺序表。
 * 仅回收所有元素内存空间
 *
 * 参数
 *  @ list 顺序表结构体地址
 *
 * 返回值
 *  @  0 执行成功
 *  @ -1 执行失败
 */
int DestroyList(SqList *list);


/*
 * 为顺序表增加存储空间
 *
 * 参数
 *  @ list 顺序表首地址
 *  @ int  增加空间大小;如果为NULL，增加内存空间为原长度1/2
 *
 * 返回值
 *  @  0 执行成功
 *  @ -1 执行失败
 */  
int AddListSize(SqList *list, unsigned int increase_size);


/*
 * 判断顺序表是否为空
 *
 * 参数
 *  @ list(const) 顺序表
 *
 * 返回值
 *  @ 1 true
 *  @ 0 false
 */
int ListEmpty(const SqList list);

/*
 * 清空顺序表
 *
 * 参数
 *  @ list 顺序表首地址
 *
 * 返回值
 *  @  0 执行成功
 *  @ -1 执行失败
 */
int ClearList(SqList *list);


/*
 * 获取顺序表元素个数
 *
 * 参数
 *  @ list(const) 顺序表
 *
 * 返回值
 *  @ 元素个数
 */
unsigned int GetElemNum(const SqList list);

/*
 * 获取第i个元素
 *******************************
 * 此处返回的是元素，而不是指针
 *******************************
 *
 * 参数
 *  @ list 顺序表
 *  @ i    第i个元素
 *
 * 返回值
 *  @ 第i个元素，NULL表示无第i个元素
 */
void GetElem(SqList list, unsigned int i, ElemType *elem);

/*
 * 向顺序表尾部添加元素
 *********************************
 * 此处传入的参数是指向元素的指针
 *********************************
 *
 * 参数
 *  @ list 顺序表结构体地址
 *  @ elem 所添加元素
 *
 * 返回值
 *  @  0 执行成功
 *  @ -1 执行失败
 */
int AddElem(SqList *list, ElemType *elem);

/*
 * 将元素添加到指定位置
 *************************
 * 实际是移动了指针的指向
 *************************
 *
 * 参数
 *  @ list 顺序表结构体地址
 *  @ i    指定位置
 *  @ elem 所添加元素
 *
 * 返回值
 *  @  0 执行成功
 *  @ -1 执行失败
 */
int AddElemByIndex(SqList *list, unsigned int i, ElemType *elem);

int DeleteElemByIndex(SqList *list, ElemType *elem);

void print(const SqList *list);

#endif // _SQLIST_H
