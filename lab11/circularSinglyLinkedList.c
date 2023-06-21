#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int info;
  struct Node *next;
};
typedef struct Node Node;

void insert_at_beginning(Node **head, int item)
{
  Node *newnode;
  Node *temp;
  newnode = (Node *)malloc(sizeof(Node));
  newnode->info = item;
  temp = *head;

  if (*head == NULL)
  {
    newnode->next = newnode;
    *head = newnode;
  }
  else
  {
    newnode->next = *head;
    while (temp->next != *head)
    {
      temp = temp->next;
    }
    temp->next = newnode;
    *head = newnode;
  }
}

void insert_at_end(Node **head, int item)
{
  Node *newnode;
  Node *temp;
  newnode = (Node *)malloc(sizeof(Node));
  newnode->info = item;
  temp = *head;

  if (*head == NULL)
  {
    newnode->next = newnode;
    *head = newnode;
  }
  else
  {
    while (temp->next != *head)
    {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = *head;
  }
}

void display(Node **head)
{
  Node *temp;
  temp = *head;

  printf("----------------\n");
  while (temp->next != *head)
  {
    printf("%d\n", temp->info);
    temp = temp->next;
  }
  printf("%d\n", temp->info);
  printf("----------------\n");
}

void insert_at_specific_position(Node **head, int item)
{
  Node *newnode;
  Node *temp;
  temp = *head;

  newnode = (Node *)malloc(sizeof(Node));
  newnode->info = item;
}
int main()
{
  Node *head;
  head = NULL;

  int item = -1;
  int option = -1;
  int position = -1;

  while (option != 8)
  {
    printf("Enter any option below \n");
    printf(" 1. Insert At Beginning \n 2. Insert at Specific position \n 3. insert_at_end \n");
    printf(" 4. Delete form beginning \n 5. Delete from end \n 6. Delete from specific position \n");
    printf(" 7. Display \n");
    printf(" 8. Exit \n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Enter a item to insert_at_beginning \n");
      scanf("%d", &item);
      insert_at_beginning(&head, item);
      break;

    // case 2:
    //   printf("Enter a item to insert_at_a_specific_position and position \n");
    //   scanf("%d", &item);
    //   scanf("%d", &position);
    //   insert_at_a_specific_position(&head, item, position);
    //   break;
    case 3:
      printf("Enter a item to insert_at_end\n");
      scanf("%d", &item);
      insert_at_end(&head, item);
      break;

      // case 4:
      //   item = deletion_from_beginning(&head);
      //   printf("Deleted item is  %d\n", item);
      //   break;

      // case 5:
      //   item = deletion_from_end(&head);
      //   printf("Deleted item is  %d\n", item);
      //   break;

      // case 6:
      //   printf("Enter any position to delete data\n");
      //   scanf("%d", &position);
      //   item = deletion_from_specific_position(&head, position);
      //   printf("Deleted item is  %d\n", item);
      //   break;

    case 7:
      display(&head);
      break;
    case 8:
      exit(0);
      break;

    default:
      printf("please enter from 1-6\n");
      break;
    }
  }
}
