#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
  void *val;
  struct Node *next;
} node_t;

typedef struct table
{
  int length;
  struct Node **buckets;
} table_t;

table_t *initTable(int len)
{
  table_t *table = (table_t *)malloc(sizeof(table_t));
  table->length = len;
  table->buckets = (node_t **)malloc(len * sizeof(node_t));

  for (int i = 0; i < len; i++)
  {
    table->buckets[i] = NULL;
  }

  return table;
}

/* Create Hash function*/

/* TODO: Insert */

/* TODO: Search */

/* TODO: Delete (Please free space)*/