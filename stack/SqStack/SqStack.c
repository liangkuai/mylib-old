#include "../../common.h"
#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int InitStack(SqStack *stack)
{
    stack->base = (ElemType *)calloc(STACK_INIT_SIZE, sizeof(ElemType));
    if (stack->base == NULL)
    {
        // 内存分配失败
        return EXECUTE_FAILURE;
    }
    stack->top = stack->base;
    stack->size = STACK_INIT_SIZE;
    stack->elem_num = 0;

    return EXECUTE_SUCCESS;
}


int DestroyStack(SqStack *stack)
{
    free(stack->base);
    stack->top = stack->base = NULL;

    stack->elem_num = 0;
    stack->size = 0;

    return EXECUTE_SUCCESS;
}


int StackEmpty(const SqStack stack)
{
    if (stack.elem_num == 0)
        return TRUE;
    else
        return FALSE;
}


int ClearStack(SqStack *stack)
{
    memset(stack->base, 0, stack->elem_num);
    stack->elem_num = 0;
    return EXECUTE_SUCCESS;
}


int AddStackSize(SqStack *stack, unsigned int add_size)
{
    ElemType *new_stack = NULL;
    
    if (add_size == 0)
    {
        new_stack = (ElemType *)realloc(stack->base,
            (stack->size + (stack->size >> 1)) * sizeof(ElemType));
        if (new_stack == NULL)
        {
            // 内存分配失败
            return EXECUTE_FAILURE;
        }

        stack->size = stack->size + (stack->size >> 1);
    }
    else
    {
        new_stack = (ElemType *)realloc(stack->base,
            (stack->size + add_size) * sizeof(ElemType));
        if (new_stack == NULL)
        {
            // 内存分配失败
            return EXECUTE_FAILURE;
        }

        stack->size = stack->size + add_size;
    }

    stack->base = new_stack;
    stack->top = new_stack + stack->elem_num;

    return EXECUTE_SUCCESS;
}


int Push(SqStack *stack, ElemType e)
{
    if (stack->elem_num >= stack->size - 1)
        if (!AddStackSize(stack, 0))
            return EXECUTE_FAILURE;

    *stack->top++ = e;
    ++stack->elem_num;

    return EXECUTE_SUCCESS;
}


int Pop(SqStack *stack, ElemType *e)
{
    if (StackEmpty(*stack))
    {
        return EXECUTE_FAILURE;
    }

    e = --stack->top;
    --stack->elem_num;

    return EXECUTE_SUCCESS;
}


int GetTop(SqStack *stack, ElemType *e)
{
    if (StackEmpty(*stack))
    {
        return EXECUTE_FAILURE;
    }

    e = stack->top - 1;

    return EXECUTE_SUCCESS;
}


void print(SqStack *stack)
{
    int i;

    printf("*************************\n");
    printf("长度: %u\n", stack->size);
    printf("内容: %u\n", stack->elem_num);
    for (i = 0; i < stack->elem_num; ++i)
        printf("%d\n", *(stack->base + i));
    printf("*************************\n");
}
