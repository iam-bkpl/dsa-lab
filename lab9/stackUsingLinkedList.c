#include <stdio.h>
#include <stdlib.h>
struct stack
{
  int info;
  struct stack *next;
};
typedef struct stack stack;

void push(stack **top, int item)
{
  stack *newnode;
  newnode = (stack *)malloc(sizeof(stack));
  newnode->info = item;

  if (*top == NULL)
  {
    newnode->next = NULL;
    *top = newnode;
  }
  else
  {
    newnode->next = *top;
    *top = newnode;
  }
}

int pop(stack **top)
{
  int item = -1;
  stack *temp;

  if (*top == NULL)
  {
    printf("Stack is empty\n");
    return 0;
  }
  else
  {
    temp = *top;
    item = temp->info;
    *top = temp->next;
    free(temp);
  }
  return item;
}
void display(stack **top)
{
  stack *temp;
  temp = *top;

  printf("++++++++++++Data in stack++++++++++++\n");
  while (temp != NULL)
  {
    printf("%d\n", temp->info);
    temp = temp->next;
  }
  printf("---------Data in stack------------\n");
}
int main()
{
  stack *top;
  top = NULL;

  int option = -1;
  int item = -1;
  while (option != 5)
  {
    printf("Enter any options\n");
    printf(" 1. Push \n 2. Pop \n 3. Display \n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Enter any item to insert \n");
      scanf("%d", &item);
      push(&top, item);
      break;
    case 2:
      item = pop(&top);
      printf("Deleted item is %d \n", item);
      break;

    case 3:
      display(&top);
      break;
    default:
      break;
    }
  }
  return 0;
}