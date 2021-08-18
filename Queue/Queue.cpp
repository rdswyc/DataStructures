#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Queue.h"

#pragma region Properties

int Count(Queue queue)
{
  return queue.capacity;
}

#pragma endregion

#pragma region Methods

void Clear(Queue *queue)
{
  queue->capacity = 0;
  free(queue->Items);
  queue->Items = NULL;
}

bool Equals(T item1, T item2)
{
  return strcmp(item1, item2) == 0;
}

bool Contains(Queue queue, T item)
{
  if (queue.Items != NULL)
  {
    for (int i = 0; i < queue.capacity; i++)
    {
      if (Equals(queue.Items[i], item))
        return true;
    }
  }

  return false;
}

T *Dequeue(Queue *queue)
{
  if (queue->capacity == 0)
    return NULL;

  T item = *Peek(*queue);
  T *ptr = &item;

  int newSize = --queue->capacity * sizeof(T);
  memmove(queue->Items, &queue->Items[1], newSize);
  queue->Items = (T *)realloc(queue->Items, newSize);

  return ptr;
}

void Enqueue(Queue *queue, T item)
{
  if (queue->capacity == 0)
  {
    queue->capacity = 1;
    queue->Items = (T *)malloc(sizeof(T));
  }
  else
  {
    queue->capacity++;
    queue->Items = (T *)realloc(queue->Items, queue->capacity * sizeof(T));
  }

  queue->Items[queue->capacity - 1] = (T)malloc(strlen(item));
  strcpy(queue->Items[queue->capacity - 1], item);
}

Queue Initialize()
{
  Queue queue;
  queue.capacity = 0;
  queue.Items = NULL;
  return queue;
}

T Initialize_RandString()
{
  int length = 7;
  T text = (T)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

Queue Initialize(int capacity)
{
  Queue queue;
  queue.capacity = capacity;
  queue.Items = (T *)malloc(capacity * sizeof(T));

  for (int i = 0; i < capacity; i++)
  {
    T randStr = Initialize_RandString();
    queue.Items[i] = (T)malloc(strlen(randStr));
    strcpy(queue.Items[i], randStr);
  }

  return queue;
}

T *Peek(Queue queue)
{
  return &queue.Items[0];
}

void Print(Queue queue)
{
  if (queue.Items != NULL)
  {
    for (int i = 0; i < queue.capacity; i++)
      PrintItem(queue.Items[i]);
  }
}

void PrintItem(T item)
{
  printf("* %s\n", item);
}

#pragma endregion