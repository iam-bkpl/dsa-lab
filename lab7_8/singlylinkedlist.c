#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node *next;
};
typedef struct node node;

void insert_at_beginning(node **head, int item)
{
  node *newnode;
  newnode = (node *)malloc(sizeof(node));
  newnode->info = item;
  newnode->next = *head;
  *head = newnode;
}

void insert_at_end(node **head, int item)
{
  node *newnode, *temp;
  newnode = (node *)malloc(sizeof(node));
  newnode->info = item;
  newnode->next = NULL;
  temp = *head;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
}

void insert_at_a_specific_position(node **head, int item, int position)
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
  temp->next = newnode;
}

int deletion_from_beginning(node **head)
{
  int item = -1;
  node *temp;
  if (*head == NULL)
  {
    printf("List is empty");
    return item;
  }
  else
  {
    temp = *head;
    item = temp->info;
    *head = temp->next;
    free(temp);
  }
  return item;
}

int deletion_from_end(node **head)
{
  int item = -1;
  node *temp;

  if (*head == NULL)
  {
    printf("Empty List");
    return item;
  }
  else
  {
    temp = *head;
    while (temp->next->next != NULL)
      temp = temp->next;

    item = temp->next->info;
    free(temp->next);
    temp->next = NULL;
    return item;
  }
}

int deletion_from_specific_position(node **head, int position)
{
  node *temp, *ptemp;
  temp = *head;
  int item = -1;

  for (int i = 1; i < position - 1; i++)
  {
    temp = temp->next;
  }
  ptemp = temp->next;
  item = ptemp->info;
  temp->next = ptemp->next;
  free(ptemp);
  return item;
}

void traverse(node **head)
{
  node *temp;
  temp = *head;
  printf("++++++++++++++ Data in the list is +++++++++++ ");
  while (temp != NULL)
  {
    printf("\n%d\n", temp->info);
    temp = temp->next;
  }
  printf("---------- Data in the list is -----------");
}

int main()
{
  node *head;
  head = NULL;
  int item = -1;
  int position = -1;
  int option = -1;

  while (option != 8)
  {

    printf("Enter any number form 1 - 7\n");
    printf("1. insert_at_beginning \n2. insert_at_a_specific_position \n3. insert_at_end \n");
    printf("4. deletion_from_beginning \n5. deletion_from_end \n6. deletion_from_specific_position \n");
    printf("7. display\n");
    printf("8. Exit\n");

    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Enter a item to insert_at_beginning \n");
      scanf("%d", &item);
      insert_at_beginning(&head, item);
      break;
    case 2:
      printf("Enter a item to insert_at_a_specific_position and position \n");
      scanf("%d", &item);
      scanf("%d", &position);
      insert_at_a_specific_position(&head, item, position);
      break;
    case 3:
      printf("Enter a item to insert_at_end\n");
      scanf("%d", &item);
      insert_at_end(&head, item);
      break;

    case 4:
      item = deletion_from_beginning(&head);
      printf("Deleted item is  %d\n", item);
      break;

    case 5:
      item = deletion_from_end(&head);
      printf("Deleted item is  %d\n", item);
      break;

    case 6:
      printf("Enter any position to delete data\n");
      scanf("%d", &position);
      item = deletion_from_specific_position(&head, position);
      printf("Deleted item is  %d\n", item);
      break;

    case 7:
      traverse(&head);
      break;

    default:
      printf("please enter from 1-6\n");
      break;
    }
  }
}
