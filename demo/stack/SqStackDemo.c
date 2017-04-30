#include <stdio.h>
#include "../../stack/SqStack/SqStack.h"

int main()
{
    int res;
    SqStack stack;

    res = InitStack(&stack);
    printf("init res = %d\n", res);
    print(&stack);

    res = DestroyStack(&stack);
    printf("destroy res = %d\n", res);
    print(&stack);

    return 0;
}
