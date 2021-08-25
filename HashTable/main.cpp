#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

#define INPUT_LENGTH 100

char *GetInput(const char *message)
{
  printf(message);
  char *input = (char *)malloc(INPUT_LENGTH * sizeof(char));
  scanf("%[^\n]s", input);
  return input;
}

int main()
{
  printf("\n****************************\n");
  printf("******** Hash table ********\n");
  printf("****************************\n\n");

  HashTable table = Initialize();

  int option = -1;

  while (option != 0)
  {
    if (option == -1)
    {
      printf("**** Choose an option:  ****\n");
      printf("**   1 Set item. 2 Remove item. 3 Clear table.\n");
      printf("**   4 Get item. 5 Find value. 6 Hash table properties.\n");
      printf("**   7 Print buckets. 8 Resize and rehash. 9 Autofill buckets.\n");
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
      printf("Set table item.\n");
      TKey key = GetInput("Enter key: ");
      fflush(stdin);
      TValue value = GetInput("Enter value: ");

      Set(&table, key, value);
    }
    break;

    case 2:
    {
      TKey key = GetInput("Remove table item.\nEnter key: ");

      Item *item = Get(table, key);
      if (item == NULL)
        printf("Item not found!\n");
      else
        Remove(&table, key);
    }
    break;

    case 3:
      printf("Clear hash table.\n");
      Clear(&table);
      break;

    case 4:
    {
      TKey key = GetInput("Get item by key.\nEnter key: ");

      Item *item = Get(table, key);
      if (item == NULL)
        printf("Item not found!\n");
      else
        PrintBucket(*item);
    }
    break;

    case 5:
    {
      TValue value = GetInput("Find item by value.\nEnter value: ");

      Item *item = FindValue(table, value);
      if (item == NULL)
        printf("Item not found!\n");
      else
        PrintBucket(*item);
    }
    break;

    case 6:
      printf("Hash table properties:\n");
      printf("Buckets: %i\n", Buckets(table));
      printf("Count: %i\n", Count(table));
      printf("Load factor: %.2f\n", LoadFactor(table));
      break;

    case 7:
      printf("Hash buckets:\n");
      Print(table);
      break;

    case 8:
    {
      printf("Resize and rehash.\nEnter new size: ");
      int size;
      scanf("%i", &size);

      Rehash(&table, size);
    }
    break;

    case 9:
    {
      printf("Autofill hash table.\n");
      table = Initialize(table.numberBuckets);
      AutoFill(&table);
    }
    break;

    default:
      printf("Option not found!");
      option = -1;
      break;
    }

    printf("\n");
  }

  free(table.buckets);
  system("pause");
}
