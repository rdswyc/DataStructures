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

bool Contains(Queue queue, TKey key)
{
  if (queue.Items != NULL)
  {
    for (int i = 0; i < queue.capacity; i++)
    {
      if (queue.Items[i].key == key)
        return true;
    }
  }

  return false;
}

Item *Dequeue(Queue *queue)
{
  if (queue->capacity == 0)
  {
    return NULL;
  }
  else
  {
    Item item = *Peek(*queue);
    Item *ptr = &item;

    int newSize = --queue->capacity * sizeof(Item);
    memmove(queue->Items, &queue->Items[1], newSize);
    queue->Items = (Item *)realloc(queue->Items, newSize);

    return ptr;
  }
}

void Enqueue(Queue *queue, Item *item)
{
  if (queue->capacity == 0)
  {
    queue->capacity = 1;
    queue->Items = (Item *)malloc(sizeof(Item));
  }
  else
  {
    queue->capacity++;
    queue->Items = (Item *)realloc(queue->Items, queue->capacity * sizeof(Item));
  }

  queue->Items[queue->capacity - 1].key = item->key;
  queue->Items[queue->capacity - 1].value = (TValue)malloc(strlen(item->value));
  strcpy(queue->Items[queue->capacity - 1].value, item->value);
}

Queue Initialize()
{
  Queue queue;
  queue.capacity = 0;
  queue.Items = NULL;
  return queue;
}

TValue Initialize_RandString()
{
  int length = 7;
  TValue text = (TValue)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

Queue Initialize(int capacity)
{
  Queue queue;
  queue.capacity = capacity;
  queue.Items = (Item *)malloc(capacity * sizeof(Item));

  for (int i = 0; i < capacity; i++)
  {
    queue.Items[i].key = i + 1;

    TValue randStr = Initialize_RandString();
    queue.Items[i].value = (TValue)malloc(strlen(randStr));
    strcpy(queue.Items[i].value, randStr);
  }

  return queue;
}

Item *Peek(Queue queue)
{
  return &queue.Items[0];
}

void Print(Queue queue)
{
  if (queue.Items != NULL)
  {
    for (int i = 0; i < queue.capacity; i++)
    {
      PrintItem(&queue.Items[i]);
    }
  }
}

void PrintItem(Item *item)
{
  printf("* %ld %s\n", item->key, item->value);
}

#pragma endregion