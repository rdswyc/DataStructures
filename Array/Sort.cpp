#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Array.h"

int Compare(T item1, T item2)
{
  if (item1 == NULL && item2 == NULL)
    return 0;
  else
    return strcmp(item1, item2);
}

void BubbleSort(T array[], int size)
{
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - i - 1; j++)
    {
      if (Compare(array[j], array[j + 1]) > 0)
        SwapItems(array[j], array[j + 1]);
    }
}

void InsertionSort(T array[], int size)
{
  T current;
  int j;

  for (int i = 1; i < size; i++)
  {
    current = (T)malloc(strlen(array[i]));
    strcpy(current, array[i]);

    j = i - 1;

    while (j >= 0 && Compare(array[j], current) > 0)
    {
      array[j + 1] = array[j];
      j = j - 1;
    }

    array[j + 1] = current;
  }
}

void SelectionSort(T array[], int size)
{
  int minIndex;

  for (int i = 0; i < size - 1; i++)
  {
    minIndex = i;
    for (int j = i + 1; j < size; j++)
      if (Compare(array[j], array[minIndex]) < 0)
        minIndex = j;

    SwapItems(array[minIndex], array[i]);
  }
}

void Sort(T array[], int size)
{
  printf("Choose sorting algorithm:\n");
  printf("  1 Buble sort.\n");
  printf("  2 Selection sort.\n");
  printf("  3 Insertion sort.\n");
  printf("  Enter option: ");

  int option;
  scanf("%i", &option);

  switch (option)
  {
  case 1:
    BubbleSort(array, size);
    break;

  case 2:
    SelectionSort(array, size);
    break;

  case 3:
    InsertionSort(array, size);
    break;

  default:
    printf("Wrong option!\n");
    break;
  }
}