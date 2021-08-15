#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

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
} Stack;

#pragma endregion

#pragma region Method headers

int Count(Stack stack);

void Clear(Stack *stack);
bool Contains(Stack stack, TKey key);
Stack Initialize();
Stack Initialize(int capacity);
Item *Peek(Stack stack);
Item *Pop(Stack *stack);
void Print(Stack stack);
void PrintItem(Item *item);
void Push(Stack *stack, Item *item);

#pragma endregion

#endif