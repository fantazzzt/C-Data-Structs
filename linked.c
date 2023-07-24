/*Void data so that any data type can be passed in*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
  void *val;
  struct Node *next;
} node_t;

/*Inserts a node at the beginning of the linked list, data type and size
must be known at the beginning*/
struct Node *insertBegin(struct Node **head, void *new_data, size_t size)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->val = malloc(size);
  newNode->next = (*head);
  if (size == 0)
  {
    free(newNode);
    printf("Invalid size. Size should be greater than 0.\n");
    return NULL;
  }

  if (newNode->val == NULL)
  {
    free(newNode);
    printf("Memory allocation failed for newNode->val.\n");
    return NULL;
  }

  int i;
  for (i = 0; i < size; i++)
    *(char *)(newNode->val + i) = *(char *)(new_data + i);
  (*head) = newNode;
  return newNode;
}

void *peek(struct Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }
  return head->val;
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

struct Node *indexAdd(struct Node **head, void *new_data, size_t size, int index)
{
  int listLength = getListLength(*head);
  if (index < 0 || index > listLength)
  {
    printf("Invalid index. Index should be between 0 and %d\n", listLength);
    return NULL;
  }

  if (size == 0)
  {
    printf("Invalid size. Size should be greater than 0.\n");
    return NULL;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->val = malloc(size);
  if (newNode->val == NULL)
  {
    free(newNode);
    printf("Memory allocation failed for newNode->val.\n");
    return NULL;
  }
  memcpy(newNode->val, new_data, size);

  if (index == 0)
  {
    newNode->next = *head;
    *head = newNode;
    return *head;
  }
  else
  {
    struct Node *oldhead = *head;
    struct Node *temp = *head;
    while (index != 1)
    {
      temp = temp->next;
      index--;
    }

    struct Node *following = temp->next;
    temp->next = newNode;
    newNode->next = following;
    return oldhead;
  }
}

struct Node *createNode(void *value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
  {
    // Failed to allocate memory for the new node
    return NULL;
  }

  newNode->val = value;
  newNode->next = NULL;

  return newNode;
}
int main(void)
{
  int j = 1;
  int size = sizeof(j);
  int k = 4;
  int size2 = sizeof(k);
  int i = 6;
  int size3 = sizeof(i);

  struct Node *frst = createNode(&j);
  struct Node *head = insertBegin(&frst, &k, size2);

  indexAdd(&head, &i, size3, 2);

  int data = 0;
  int datasize = sizeof(data);
  struct Node *newHead = indexAdd(&head, &data, datasize, 0);

  int len = getListLength(head);
  printf("Length of this list: %d\n", len);
  int *look = (int *)peek(newHead);
  printf("Top of the list: %d\n", *look);

  free(newHead);

  return 0;
}