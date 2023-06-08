#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int info;
  struct queue *next;
};
typedef struct queue queue;

void enqueue(queue **front, queue **rear, int item)
{
  queue *newnode;

  newnode = (queue *)malloc(sizeof(queue));
  newnode->info = item;

  if (*front == NULL)
  {
    *front = newnode;
    *rear = newnode;
    newnode->next = NULL;
  }
  else
  {
    newnode->next = NULL;
    (*rear)->next = newnode;
    *rear = newnode;
  }
}

int dequeue(queue **front, queue **rear)
{
  queue *temp;
  int item = -1;
  if (*front == NULL)
  {
    printf("List is empty");
    return item;
  }
  else
  {
    temp = *front;
    *front = temp->next;
    item = temp->info;
    free(temp);
    return item;
  }
}

void display(queue **front)
{
  queue *temp;
  temp = *front;
  printf("++++++++++++Data in Queue++++++++++++\n");

  while (temp != NULL)
  {
    printf("%d\n", temp->info);
    temp = temp->next;
  }
  printf("---------Data in queue------------\n");
}
int main()
{
  queue *front;
  queue *rear;

  front = NULL;
  rear = NULL;

  int option = -1;
  int item = -1;

  while (option != 5)
  {

    printf("Enter any option \n");
    printf(" 1. Enqueue \n 2. Dequeue \n 3. Display \n");
    printf(" 5. Exit \n");

    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Enter any item to insert \n");
      scanf("%d", &item);
      enqueue(&front, &rear, item);
      break;
    case 2:
      item = dequeue(&front, &rear);
      printf("Deleted item is %d \n", item);
      break;
    case 3:
      display(&front);
      break;
    default:
      break;
    }
  }
  return 0;
}