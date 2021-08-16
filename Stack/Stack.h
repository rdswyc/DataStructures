#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

#pragma region Structure

typedef char *T;

typedef struct
{
  int capacity;
  T *Items;
} Stack;

#pragma endregion

#pragma region Method headers

int Count(Stack stack);

void Clear(Stack *stack);
bool Contains(Stack stack, T item);
Stack Initialize();
Stack Initialize(int capacity);
T *Peek(Stack stack);
T *Pop(Stack *stack);
void Print(Stack stack);
void PrintItem(T item);
void Push(Stack *stack, T item);

#pragma endregion

#endif