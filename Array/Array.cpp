#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#include "Array.h"

T Autofill_RandString()
{
  int length = 7;
  T text = (T)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

void Autofill(T array[], int size)
{
  for (int i = 0; i < size; i++)
    array[i] = Autofill_RandString();
}

void Clear(T array[], int size)
{
  for (int i = 0; i < size; i++)
    array[i] = NULL;
}

int CompareItems(T item1, T item2)
{
  if (item1 == NULL && item2 == NULL)
    return 0;
  else
    return strcmp(item1, item2);
}

bool Equals(T item1, T item2)
{
  return item1 != NULL && item2 != NULL && strcmp(item1, item2) == 0;
}

int IndexOf(T array[], int size, T item)
{
  for (int i = 0; i < size; i++)
  {
    if (Equals(array[i], item))
      return i;
  }

  return -1;
}

int LastIndexOf(T array[], int size, T item)
{
  for (int i = size - 1; i >= 0; i--)
  {
    if (Equals(array[i], item))
      return i;
  }

  return -1;
}

void Print(T array[], int size)
{
  if (array != NULL)
  {
    for (int i = 0; i < size; i++)
      PrintItem(array[i]);
  }
}

void PrintItem(T item)
{
  printf("* %s\n", item);
}

void Reverse(T array[], int size)
{
  for (int i = 0; i < size / 2; i++)
    SwapItems(array[i], array[size - i - 1]);
}

void SetValue(T array[], int index, T value)
{
  array[index] = value;
}

void SwapItems(T item1, T item2)
{
  T temp = (T)malloc(strlen(item1));
  strcpy(temp, item1);

  strcpy(item1, item2);
  strcpy(item2, temp);
}