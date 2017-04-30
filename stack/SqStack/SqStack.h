/**
 * SqStack.h
 *
 * 顺序栈，动态数组
 *
 * Created by liangkuai
 *
 * Data: 2017/04/30
 */

 

#ifndef _SQSTACK_H
#define _SQSTACK_H


#define STACK_INIT_SIZE 100
#define STACK_INCREASE_SIZE 10


/*
 * 顺序栈定义
 */

typedef int ElemType;

typedef struct
{
    ElemType *top;
    ElemType *base;
    unsigned int elem_num;
    unsigned int size;
}SqStack;


int InitStack(SqStack *stack);


int DestroyStack(SqStack *stack);


int StackEmpty(SqStack stack);


int ClearStack(SqStack *stack);


int AddStackSize(SqStack *stack, unsigned int add_size);


int Push(SqStack *stack, ElemType e);


int Pop(SqStack *stack, ElemType *e);


int GetTop(SqStack *stack, ElemType *e);


void print(SqStack *stack);


#endif // _SQSTACK_H
