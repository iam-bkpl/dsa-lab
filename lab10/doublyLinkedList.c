#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  int info;
  struct node *next;
};
typedef struct node node;

void insert_at_beginning(node **head, node **tail, int item)
{
  node *newnode, *temp;
  newnode = (node *)malloc(sizeof(node));
  newnode->info = item;
  newnode->prev = NULL;
  temp = *head;

  if (*head == NULL)
  {
    newnode->next = NULL;
    newnode->prev = NULL;
    *head = newnode;
    *tail = newnode;
  }
  else
  {
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;
  }
}

void insertion_at_end(node **head, node **tail, int item)
{
  node *newnode;
  newnode = (node *)malloc(sizeof(node));
  newnode->info = item;
  newnode->next = NULL;

  if (*head == NULL)
  {
    newnode->prev = NULL;
    newnode->next = NULL;
    *head = newnode;
    *tail = newnode;
  }
  else
  {
    newnode->prev = (*tail);
    (*tail)->next = newnode;
    *tail = newnode;
  }
}

void insert_at_specific_position(node **head, node **tail, int position, int item)
{
  node *newnode, *temp;
  newnode = (node *)malloc(sizeof(node));
  newnode->info = item;
  temp = *head;

  for (int i = 1; i < position - 1; i++)
  {
    temp = temp->next;
  }
  newnode->next = temp->next;
  newnode->prev = temp;
  temp->next->prev = newnode;
  temp->next = newnode;
}

int deletion_from_beginning(node **head, node **tail)
{
  node *temp;
  temp = *head;
  int item = -1;

  if (*head == NULL)
  {
    printf("List is empty \n");
  }
  else
  {
    *head = (*head)->next;
    (*head)->prev = NULL;
    item = temp->info;
    free(temp);
    return item;
  }
  return item;
}

int deletion_from_end(node **head, node **tail)
{
  node *temp;
  int item = NULL;
  temp = *tail;

  if (*head == NULL)
  {
    printf("List is empty \n");
  }
  else if (*head == *tail)
  {
    item = temp->info;
    *head = NULL;
    *tail = NULL;
    free(temp);
  }
  else
  {
    item = (*tail)->info;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    free(temp);
  }
  return item;
}

int delete_from_specific_position(node **head, node **tail, int position)
{
  node *temp;
  temp = *head;
  int item = -1;

  for (int i = 1; i < position; i++)
  {
    temp = temp->next;
  }

  temp->next->prev = temp->prev;
  temp->prev->next = temp->next;
  item = temp->info;

  free(temp);
  return item;
}

void display(node **head, node **tail)
{
  node *temp;
  temp = *head;

  printf("++++++++++++++++ Display ++++++++++++\n");
  while (temp != NULL)
  {
    printf("%d\n", temp->info);
    temp = temp->next;
  }
  printf("++++++++++++++++ Display ++++++++++++\n");
}

int main()
{
  node *head;
  node *tail;

  head = NULL;
  tail = NULL;

  int item = -1;
  int option = -1;
  int position = -1;

  while (option != 8)
  {
    printf("Enter any option below \n");
    printf(" 1. Insert At Beginning \n 2. Insert at End \n 3. Insert at Specific position \n");
    printf(" 4. Delete form beginning \n 5. Delete from end \n 6. Delete from specific position \n");
    printf(" 7. Display \n");
    printf(" 8. Exit \n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Enter any item to insert \n");
      scanf("%d", &item);
      insert_at_beginning(&head, &tail, item);
      break;

    case 2:
      printf("Enter any item to insert \n");
      scanf("%d", &item);
      insertion_at_end(&head, &tail, item);
      break;

    case 3:
      printf("Enter any item to insert \n");
      scanf("%d", &item);
      printf("Enter any item position\n");
      scanf("%d", &position);
      insert_at_specific_position(&head, &tail, position, item);
      break;

    case 4:
      item = deletion_from_beginning(&head, &tail);

      if (item)
      {
        printf("Deleted item is %d \n", item);
      }
      else
      {
        printf("List is empty \n");
      }
      break;

    case 5:
      item = deletion_from_end(&head, &tail);
      if (item)
      {
        printf("Deleted item is %d \n", item);
      }
      else
      {
        printf("List is empty\n");
      }
      break;

    case 6:
      printf("Enter any item position\n");
      scanf("%d", &position);
      item = delete_from_specific_position(&head, &tail, position);

      if (item)
      {
        printf("Deleted item is %d \n", item);
      }
      else
      {
        printf("List is empty \n");
      }

      break;
    case 7:
      display(&head, &tail);
      break;
    default:
      break;
    }
  }
  return 0;
}