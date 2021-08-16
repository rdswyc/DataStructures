#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "LinkedList.h"

#pragma region Properties

int Count(List list)
{
  int count = 0;

  for (Node *n = list.first; n != NULL; n = n->next)
    count++;

  return count;
}

T First(List list)
{
  return list.first == NULL ? NULL : list.first->value;
}

T Last(List list)
{
  return list.last == NULL ? NULL : list.last->value;
}

#pragma endregion

#pragma region Methods

Node *AddAfter(List *list, Node *node, T item)
{
  if (node == NULL)
    return NULL;

  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->value = (T)malloc(strlen(item));
  strcpy(newNode->value, item);

  newNode->next = node->next;
  newNode->previous = node;

  if (node->next == NULL)
    list->last = newNode;
  else
    node->next->previous = newNode;

  node->next = newNode;

  return newNode;
}

Node *AddBefore(List *list, Node *node, T item)
{
  if (node == NULL)
    return NULL;

  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->value = (T)malloc(strlen(item));
  strcpy(newNode->value, item);

  newNode->next = node;
  newNode->previous = node->previous;

  if (node->previous == NULL)
    list->first = newNode;
  else
    node->previous->next = newNode;

  node->previous = newNode;

  return newNode;
}

Node *AddFirst(List *list, T item)
{
  Node *node = (Node *)malloc(sizeof(Node));

  node->value = (T)malloc(strlen(item));
  strcpy(node->value, item);

  node->next = list->first;
  node->previous = NULL;

  if (list->first != NULL)
    list->first->previous = node;

  list->first = node;

  if (list->last == NULL)
    list->last = list->first;

  return node;
}

Node *AddLast(List *list, T item)
{
  Node *node = (Node *)malloc(sizeof(Node));

  node->value = (T)malloc(strlen(item));
  strcpy(node->value, item);

  node->next = NULL;
  node->previous = list->last;

  if (list->last != NULL)
    list->last->next = node;

  list->last = node;

  if (list->first == NULL)
    list->first = list->last;

  return node;
}

void Clear(List *list)
{
  Node *node = list->first;

  while (node != NULL)
  {
    Node *clear = node;
    node = node->next;

    free(clear);
  }

  list->first = NULL;
  list->last = NULL;
}

bool Contains(List list, T item)
{
  for (Node *n = list.first; n != NULL; n = n->next)
  {
    if (strcmp(n->value, item) == 0)
      return true;
  }

  return false;
}

Node *Find(List list, T item)
{
  for (Node *n = list.first; n != NULL; n = n->next)
  {
    if (strcmp(n->value, item) == 0)
      return n;
  }

  return NULL;
}

Node *FindLast(List list, T item)
{
  for (Node *n = list.last; n != NULL; n = n->previous)
  {
    if (strcmp(n->value, item) == 0)
      return n;
  }

  return NULL;
}

List Initialize()
{
  List list;
  list.first = NULL;
  list.last = NULL;
  return list;
}

T Initialize_RandString()
{
  int length = 7;
  T text = (T)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

List Initialize(int capacity)
{
  List list = Initialize();

  for (int i = 0; i < capacity; i++)
  {
    Node *node = (Node *)malloc(sizeof(Node));

    T text = Initialize_RandString();
    node->value = (T)malloc(strlen(text));
    strcpy(node->value, text);

    node->next = NULL;
    node->previous = list.last;

    list.last = node;

    if (i == 0)
      list.first = node;
    else
      node->previous->next = node;
  }

  return list;
}

void Print(List list)
{
  printf("Node - previous - next\n");

  for (Node *node = list.first; node != NULL; node = node->next)
    PrintNode(*node);
}

void PrintNode(Node node)
{
  printf("* %s\t%s\t%s\n", node.value,
         node.previous == NULL ? "-" : node.previous->value,
         node.next == NULL ? "-" : node.next->value);
}

void Remove(List *list, Node *node)
{
  if (list->first != NULL && node != NULL)
  {
    if (node->next == NULL)
      list->last = node->previous;
    else
      node->next->previous = node->previous;

    if (node->previous == NULL)
      list->first = node->next;
    else
      node->previous->next = node->next;

    free(node);
  }
}

void RemoveFirst(List *list)
{
  if (list->first != NULL)
  {
    Node *remove = list->first;
    list->first = remove->next;

    if (remove->next == NULL)
      list->last = NULL;
    else
      list->first->previous = NULL;

    free(remove);
  }
}

void RemoveLast(List *list)
{
  if (list->last != NULL)
  {
    Node *remove = list->last;
    list->last = remove->previous;

    if (remove->previous == NULL)
      list->first = NULL;
    else
      list->last->next = NULL;

    free(remove);
  }
}

#pragma endregion