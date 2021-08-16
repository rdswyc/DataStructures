#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma region Structure

typedef char *T;

typedef struct node
{
  T value;
  struct node *next, *previous;
} Node;

typedef struct
{
  Node *first, *last;
} List;

#pragma endregion

#pragma region Method headers

int Count(List list);
T First(List list);
T Last(List list);

Node *AddAfter(List *list, Node *node, T item);
Node *AddBefore(List *list, Node *node, T item);
Node *AddFirst(List *list, T item);
Node *AddLast(List *list, T item);
void Clear(List *list);
bool Contains(List list, T item);
Node *Find(List list, T item);
Node *FindLast(List list, T item);
List Initialize();
List Initialize(int capacity);
void PrintNode(Node node);
void Print(List list);
void Remove(List *list, Node *node);
void RemoveFirst(List *list);
void RemoveLast(List *list);

#pragma endregion

#endif