#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Array.h"

// O(n^2)
void BubbleSort(T array[], int size)
{
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - i - 1; j++)
    {
      if (CompareItems(array[j], array[j + 1]) > 0)
        SwapItems(array[j], array[j + 1]);
    }
}

// O(n^2)
void InsertionSort(T array[], int size)
{
  T current;
  int j;

  for (int i = 1; i < size; i++)
  {
    current = (T)malloc(strlen(array[i]));
    strcpy(current, array[i]);

    j = i - 1;

    while (j >= 0 && CompareItems(array[j], current) > 0)
    {
      array[j + 1] = array[j];
      j = j - 1;
    }

    array[j + 1] = current;
  }
}

// Used by MergeSort
void Merge(T array[], int left, int middle, int right)
{
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  T L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = array[left + i];
  for (j = 0; j < n2; j++)
    R[j] = array[middle + 1 + j];

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2)
  {
    if (CompareItems(L[i], R[j]) <= 0)
    {
      array[k] = L[i];
      i++;
    }
    else
    {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    array[k] = R[j];
    j++;
    k++;
  }
}

// O(n log(n))
void MergeSort(T array[], int left, int right)
{
  if (left < right)
  {
    int middle = left + (right - left) / 2;

    MergeSort(array, left, middle);
    MergeSort(array, middle + 1, right);

    Merge(array, left, middle, right);
  }
}

// Used by QuickSort
int Partition(T array[], int low, int high)
{
  T pivot = (T)malloc(strlen(array[high]));
  strcpy(pivot, array[high]);

  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (CompareItems(array[j], pivot) <= 0)
    {
      i++;
      SwapItems(array[i], array[j]);
    }
  }

  SwapItems(array[i + 1], array[high]);

  return i + 1;
}

// O(n^2)
void QuickSort(T array[], int low, int high)
{
  if (low < high)
  {
    int partitionIndex = Partition(array, low, high);

    QuickSort(array, low, partitionIndex - 1);
    QuickSort(array, partitionIndex + 1, high);
  }
}

// O(n^2)
void SelectionSort(T array[], int size)
{
  int minIndex;

  for (int i = 0; i < size - 1; i++)
  {
    minIndex = i;

    for (int j = i + 1; j < size; j++)
    {
      if (CompareItems(array[j], array[minIndex]) < 0)
        minIndex = j;
    }

    SwapItems(array[minIndex], array[i]);
  }
}

void Sort(T array[], int size)
{
  printf("Choose sorting algorithm:\n");
  printf("  1 Buble sort.\n");
  printf("  2 Selection sort.\n");
  printf("  3 Insertion sort.\n");
  printf("  4 Merge sort.\n");
  printf("  5 Quick sort.\n");
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

  case 4:
    MergeSort(array, 0, size - 1);
    break;

  case 5:
    QuickSort(array, 0, size - 1);
    break;

  default:
    printf("Wrong option!\n");
    break;
  }
}