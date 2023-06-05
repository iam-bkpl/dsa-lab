

#include <stdio.h>
#define MAX 5

struct queue
{
 int arr[MAX];
 int rare;
 int front;
};
typedef struct queue Queue;

void init_queue(Queue *queue)
{
 queue->rare = -1;
 queue->front = -1;
}

int isEmpty(Queue *queue)
{
 if (queue->rare == queue->front)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

int isFull(Queue *queue)
{
 if (queue->rare == MAX - 1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

void enqueue(Queue *queue, int item)
{
 if (!isFull(queue))
 {
  queue->front++;
  queue->rare++;
  queue->arr[queue->rare] = item;
 }
 else
 {
  printf("Queue is full");
 }
}

int dequeue(Queue *queue)
{
 if (!isEmpty(queue))
 {
  int item = queue->arr[queue->front];
  queue->front++;

  return item;
 }
 else
 {
  printf("Queue is empty");
  return 0;
 }
}
int peek(Queue *queue)
{
 int item = queue->arr[queue->front];
 queue->front++;
 return item;
}
int main()
{
 Queue queue;
 init_queue(&queue);

 // int item = dequeue(&queue);
 // printf("Deleted item is %d\n", item);

 int option;

 while (option != 5)
 {
  printf("Enter any options : \n");
  printf("1. Enqueue \n");
  printf("2. Dequeue \n");
  printf("3. peek\n");
  printf("4. display\n");
  printf("5. exit\n");

  scanf("%d", &option);

  int item = -1;
  int r_item = -1;

  switch (option)
  {
  case 1:
   printf("Enter the item to enqueue\n");
   scanf("%d", &item);
   enqueue(&queue, item);
   break;

  case 2:
   r_item = dequeue(&queue);
   printf("Deleted item is %d\n", r_item);
   break;

  case 3:
   r_item = peek(&queue);
   printf("peeked item is %d\n", r_item);
   break;

  case 4:
   printf("Display ");
   break;

  default:
   printf("Enter any correct option\n");
   break;
  }
 }
 return 0;
}
