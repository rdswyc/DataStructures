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
} LinkedList;

#pragma endregion

#pragma region Method headers

int Count(LinkedList list);
T First(LinkedList list);
T Last(LinkedList list);

Node *AddAfter(LinkedList *list, Node *node, T item);
Node *AddBefore(LinkedList *list, Node *node, T item);
Node *AddFirst(LinkedList *list, T item);
Node *AddLast(LinkedList *list, T item);
void Clear(LinkedList *list);
bool Contains(LinkedList list, T item);
Node *Find(LinkedList list, T item);
Node *FindLast(LinkedList list, T item);
LinkedList Initialize();
LinkedList Initialize(int capacity);
void PrintNode(Node node);
void Print(LinkedList list);
void Remove(LinkedList *list, Node *node);
void RemoveFirst(LinkedList *list);
void RemoveLast(LinkedList *list);

#pragma endregion

#endif