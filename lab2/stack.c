#include <stdio.h>

const MAX = 5;

struct stack
{
    int items[MAX];
    int top;
};
typedef struct stack Stack;

// creating a empty stack
Stack *createEmptyStack()
{
    Stack s;
    s.top = -1;
    return &s;
}

void push(Stack *stack, int item)
{
    stack->items[stack->top + 1] = item;
}

int pop(Stack *stack)
{
    stack->top + 1;
    int item = stack->items[stack->top + 1];
    return item;
}

int main()
{
    int option;
    printf("Enter any operations : \n 1. push \n 2. pop\n 3. Peek \n 4. Quit\n");
    scanf("%d", &option);

    Stack *stack = createEmptyStack();


    switch (option)
    {
    case 1:
        int item;
        printf("Enter a item :");
        

        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    default:
        printf("Enter from 1 - 4");
        break;
    }

    return 0;
}