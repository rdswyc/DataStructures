#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Stack.h"

#pragma region Properties

int Count(Stack stack)
{
  return stack.capacity;
}

#pragma endregion

#pragma region Methods

void Clear(Stack *stack)
{
  stack->capacity = 0;
  free(stack->Items);
  stack->Items = NULL;
}

bool Contains(Stack stack, TKey key)
{
  if (stack.Items != NULL)
  {
    for (int i = 0; i < stack.capacity; i++)
    {
      if (stack.Items[i].key == key)
        return true;
    }
  }

  return false;
}

Stack Initialize()
{
  Stack stack;
  stack.capacity = 0;
  stack.Items = NULL;
  return stack;
}

TValue Initialize_RandString()
{
  int length = 7;
  TValue text = (TValue)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

Stack Initialize(int capacity)
{
  Stack stack;
  stack.capacity = capacity;
  stack.Items = (Item *)malloc(capacity * sizeof(Item));

  for (int i = 0; i < capacity; i++)
  {
    stack.Items[i].key = i + 1;

    TValue randStr = Initialize_RandString();
    stack.Items[i].value = (TValue)malloc(strlen(randStr));
    strcpy(stack.Items[i].value, randStr);
  }

  return stack;
}

Item *Peek(Stack stack)
{
  return stack.capacity > 0 ? &stack.Items[stack.capacity - 1] : NULL;
}

Item *Pop(Stack *stack)
{
  if (stack->capacity == 0)
  {
    return NULL;
  }
  else
  {
    Item item = *Peek(*stack);
    Item *ptr = &item;

    stack->capacity--;
    stack->Items = (Item *)realloc(stack->Items, stack->capacity * sizeof(Item));

    return ptr;
  }
}

void Print(Stack stack)
{
  if (stack.Items != NULL)
  {
    for (int i = 0; i < stack.capacity; i++)
    {
      PrintItem(&stack.Items[i]);
    }
  }
}

void PrintItem(Item *item)
{
  printf("* %ld %s\n", item->key, item->value);
}

void Push(Stack *stack, Item *item)
{
  if (stack->capacity == 0)
  {
    stack->capacity = 1;
    stack->Items = (Item *)malloc(sizeof(Item));
  }
  else
  {
    stack->capacity++;
    stack->Items = (Item *)realloc(stack->Items, stack->capacity * sizeof(Item));
  }

  stack->Items[stack->capacity - 1].key = item->key;
  stack->Items[stack->capacity - 1].value = (TValue)malloc(strlen(item->value));
  strcpy(stack->Items[stack->capacity - 1].value, item->value);
}

#pragma endregion