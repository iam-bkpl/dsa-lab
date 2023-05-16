#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
 int arr[MAX_SIZE];
 int front;
 int rear;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue *queue)
{
 queue->front = -1;
 queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
 return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue *queue)
{
 return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to add an element to the queue
void enqueue(Queue *queue, int item)
{
 if (isFull(queue))
 {
  printf("Queue is full. Cannot enqueue element.\n");
  return;
 }
 else if (isEmpty(queue))
 {
  queue->front = queue->rear = 0;
 }
 else
 {
  queue->rear = (queue->rear + 1) % MAX_SIZE;
 }

 queue->arr[queue->rear] = item;
}

// Function to remove an element from the queue
int dequeue(Queue *queue)
{
 int item;

 if (isEmpty(queue))
 {
  printf("Queue is empty. Cannot dequeue element.\n");
  return -1;
 }
 else if (queue->front == queue->rear)
 {
  item = queue->arr[queue->front];
  queue->front = queue->rear = -1;
 }
 else
 {
  item = queue->arr[queue->front];
  queue->front = (queue->front + 1) % MAX_SIZE;
 }

 return item;
}

// Function to get the front element of the queue
int front(Queue *queue)
{
 if (isEmpty(queue))
 {
  printf("Queue is empty. No front element.\n");
  return -1;
 }

 return queue->arr[queue->front];
}

// Function to print the queue
void printQueue(Queue *queue)
{
 if (isEmpty(queue))
 {
  printf("Queue is empty.\n");
  return;
 }

 int i;
 printf("Queue: ");
 for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
 {
  printf("%d ", queue->arr[i]);
 }
 printf("%d\n", queue->arr[i]);
}

int main()
{
 Queue queue;
 initializeQueue(&queue);

 enqueue(&queue, 10);
 enqueue(&queue, 20);
 enqueue(&queue, 30);
 enqueue(&queue, 40);

 printQueue(&queue); // Output: Queue: 10 20 30 40

 printf("Front element: %d\n", front(&queue)); // Output: Front element: 10

 dequeue(&queue);
 dequeue(&queue);

 printQueue(&queue); // Output: Queue: 30 40

 return 0;
}
