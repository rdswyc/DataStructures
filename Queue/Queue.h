#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

#pragma region Structure

typedef char *T;

typedef struct
{
  int capacity;
  T *Items;
} Queue;

#pragma endregion

#pragma region Method headers

int Count(Queue queue);

void Clear(Queue *queue);
bool Contains(Queue queue, T item);
T *Dequeue(Queue *queue);
void Enqueue(Queue *queue, T item);
Queue Initialize();
Queue Initialize(int capacity);
T *Peek(Queue queue);
void Print(Queue queue);
void PrintItem(T item);

#pragma endregion

#endif