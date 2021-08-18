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

bool Equals(T item1, T item2)
{
  return strcmp(item1, item2) == 0;
}

bool Contains(Stack stack, T item)
{
  if (stack.Items != NULL)
  {
    for (int i = 0; i < stack.capacity; i++)
    {
      if (Equals(stack.Items[i], item))
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

T Initialize_RandString()
{
  int length = 7;
  T text = (T)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

Stack Initialize(int capacity)
{
  Stack stack;
  stack.capacity = capacity;
  stack.Items = (T *)malloc(capacity * sizeof(T));

  for (int i = 0; i < capacity; i++)
  {
    T randStr = Initialize_RandString();
    stack.Items[i] = (T)malloc(strlen(randStr));
    strcpy(stack.Items[i], randStr);
  }

  return stack;
}

T *Peek(Stack stack)
{
  return stack.capacity > 0 ? &stack.Items[stack.capacity - 1] : NULL;
}

T *Pop(Stack *stack)
{
  if (stack->capacity == 0)
    return NULL;

  T item = *Peek(*stack);
  T *ptr = &item;

  stack->capacity--;
  stack->Items = (T *)realloc(stack->Items, stack->capacity * sizeof(T));

  return ptr;
}

void Print(Stack stack)
{
  if (stack.Items != NULL)
  {
    for (int i = 0; i < stack.capacity; i++)
      PrintItem(stack.Items[i]);
  }
}

void PrintItem(T item)
{
  printf("* %s\n", item);
}

void Push(Stack *stack, T item)
{
  if (stack->capacity == 0)
  {
    stack->capacity = 1;
    stack->Items = (T *)malloc(sizeof(T));
  }
  else
  {
    stack->capacity++;
    stack->Items = (T *)realloc(stack->Items, stack->capacity * sizeof(T));
  }

  stack->Items[stack->capacity - 1] = (T)malloc(strlen(item));
  strcpy(stack->Items[stack->capacity - 1], item);
}

#pragma endregion