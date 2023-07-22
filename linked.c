/*Void data so that any data type can be passed in*/

#include <stdlib.h>

struct Node
{
  void *val;
  struct Node *next;
} node_t;

/*Inserts a node at the beginning of the linked list, data type and size
must be known at the beginning*/
void insertBegin(struct Node **head, void *new_data, size_t size)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->val = malloc(size);
  newNode->next = (*head);
  if (size == 0)
  {
    free(newNode);
    printf("Invalid size. Size should be greater than 0.\n");
    return;
  }

  if (newNode->val == NULL)
  {
    free(newNode);
    printf("Memory allocation failed for newNode->val.\n");
    return;
  }

  int i;
  for (i = 0; i < size; i++)
    *(char *)(newNode->val + i) = *(char *)(new_data + i);
  (*head) = newNode;
}

void peek(struct Node *head)
{
  if (head == NULL)
  {
    return -1;
  }
  return *((head)->val);
}

int getListLength(struct Node *head)
{
  int length = 0;
  struct Node *current = head;
  while (current != NULL)
  {
    length++;
    current = current->next;
  }
  return length;
}

void indexAdd(struct Node **head, void *new_data, size_t size, int index)
{
  int listLength = getListLength(*head);
  if (index < 0 || index > listLength)
  {
    printf("Invalid index. Index should be between 0 and %d\n", listLength);
    return;
  }

  if (size == 0)
  {
    printf("Invalid size. Size should be greater than 0.\n");
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->val = malloc(size);
  if (newNode->val == NULL)
  {
    free(newNode);
    printf("Memory allocation failed for newNode->val.\n");
    return;
  }
  memcpy(newNode->val, new_data, size);

  if (index == 0)
  {
    newNode->next = *head;
    *head = newNode;
  }
  else
  {
    struct Node *temp = *head;
    while (index != 1)
    {
      temp = temp->next;
      index--;
    }

    struct Node *following = temp->next;
    temp->next = newNode;
    newNode->next = following;
  }
}

int main(void)
{
  return 0;
}