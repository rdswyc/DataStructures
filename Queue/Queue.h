#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

#pragma region Structure

typedef long TKey;
typedef char *TValue;

typedef struct item
{
  TKey key;
  TValue value;
} Item;

typedef struct
{
  int capacity;
  Item *Items;
} Queue;

#pragma endregion

#pragma region Method headers

int Count(Queue queue);

void Clear(Queue *queue);
bool Contains(Queue queue, TKey key);
Item *Dequeue(Queue *queue);
void Enqueue(Queue *queue, Item *item);
Queue Initialize();
Queue Initialize(int capacity);
Item *Peek(Queue queue);
void Print(Queue queue);
void PrintItem(Item *item);

#pragma endregion

#endif