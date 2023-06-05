#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for stack
typedef struct
{
  int top;
  int items[MAX_SIZE];
} Stack;
/*
this is multiline comment
*/
// Function to initialize stack
void initializeStack(Stack *s)
{
  s->top = -1;
}

// Function to check if stack is full
int isFull(Stack *s)
{
  return s->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(Stack *s)
{
  return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value)
{
  if (isFull(s))
  {
    printf("Stack is full. Cannot push element.\n");
    exit(EXIT_FAILURE);
  }
  s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty. Cannot pop element.\n");
    exit(EXIT_FAILURE);
  }
  return s->items[s->top--];
}

// Function to evaluate the postfix expression
int evaluatePostfixExpression(char *expression)
{
  Stack s;
  initializeStack(&s);

  int i, operand1, operand2;
  char ch;

  for (i = 0; expression[i] != '\0'; i++)
  {
    ch = expression[i];

    if (isdigit(ch))
    {
      push(&s, ch - '0');
    }
    else
    {
      operand2 = pop(&s);
      operand1 = pop(&s);

      switch (ch)
      {
      case '+':
        push(&s, operand1 + operand2);
        break;
      case '-':
        push(&s, operand1 - operand2);
        break;
      case '*':
        push(&s, operand1 * operand2);
        break;
      case '/':
        push(&s, operand1 / operand2);
        break;
      default:
        printf("Invalid operator: %c\n", ch);
        exit(EXIT_FAILURE);
      }
    }
  }

  return pop(&s);
}

int main()
{
  char postfix[MAX_SIZE];

  printf("Enter the postfix expression: ");
  scanf("%s", postfix);

  int result = evaluatePostfixExpression(postfix);

  printf("Result: %d\n", result);

  return 0;
}
