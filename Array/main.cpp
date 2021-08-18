#include <stdio.h>
#include <stdlib.h>

#include "Array.h"

#define INPUT_LENGTH 100

T GetInput(const char *message)
{
  printf(message);
  T input = (T)malloc(INPUT_LENGTH * sizeof(char));
  scanf("%[^\n]s", input);
  return input;
}

int main()
{
  printf("\n****************************\n");
  printf("*********** ARRAY **********\n");
  printf("****************************\n\n");

  int size;
  printf("Enter size of array: ");
  scanf("%i", &size);

  T array[size] = {};

  int option = -1;

  while (option != 0)
  {
    if (option == -1)
    {
      printf("\n**** Choose an option:  ****\n");
      printf("**   1 Set value. 2 Reset value. 3. Clear array\n");
      printf("**   4 Index of. 5 Last index of. 6 Print array.\n");
      printf("**   7 Reverse array. 8 Sort array. 9 Autofill array.\n");
      printf("**   0 Exit.\n");
    }

    printf("**   Enter choice: ", option);
    scanf("%i", &option);
    fflush(stdin);
    printf("\n");

    switch (option)
    {
    case 0:
      break;

    case 1:
    {
      printf("Set item value.\nEnter index: ");
      int index;
      scanf("%i", &index);
      fflush(stdin);

      if (index < size)
      {
        T value = GetInput("Enter item value: ");
        SetValue(array, index, value);
      }
      else
        printf("Index out of range!\n");
    }
    break;

    case 2:
    {
      printf("Reset item value.\nEnter index: ");
      int index;
      scanf("%i", &index);
      fflush(stdin);

      if (index < size)
        SetValue(array, index, NULL);
      else
        printf("Index out of range!\n");
    }
    break;

    case 3:
      printf("Clear array.\n");
      Clear(array, size);
      break;

    case 4:
    {
      T value = GetInput("Index of value\nEnter item value: ");
      int index = IndexOf(array, size, value);
      printf("Index is %i\n", index);
    }
    break;

    case 5:
    {
      T value = GetInput("Last index of value\nEnter item value: ");
      int index = LastIndexOf(array, size, value);
      printf("Last index is %i\n", index);
    }
    break;

    case 6:
      printf("Array items:\n");
      Print(array, size);
      break;

    case 7:
      printf("Reverse array.\n");
      Reverse(array, size);
      break;

    case 8:
      printf("Sort array.\n");
      Sort(array, size);
      break;

    case 9:
      printf("Autofill array.\n");
      Autofill(array, size);
      break;

    default:
      printf("Option not found!");
      option = -1;
      break;
    }

    printf("\n");
  }

  system("pause");
}
