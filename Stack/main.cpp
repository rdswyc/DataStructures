#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

#define INPUT_LENGTH 100

int main()
{
  printf("\n****************************\n");
  printf("*********** STACK **********\n");
  printf("****************************\n\n");

  Stack stack = Initialize();

  int option = -1;

  while (option != 0)
  {
    if (option == -1)
    {
      printf("**** Choose an option:  ****\n");
      printf("**   1 Push. 2 Pop. 3 Clear stack.\n");
      printf("**   4 Peek item. 5 Contains item. 6 Items count.\n");
      printf("**   7 Print stack. 8 Autofill stack.\n");
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
      printf("Push item.\nEnter item key: ");
      Item item;
      scanf("%ld", &item.key);
      fflush(stdin);

      printf("Enter item value: ");
      item.value = (TValue)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", item.value);

      Push(&stack, &item);
    }
    break;

    case 2:
    {
      printf("Pop item.\n");
      Item *item = Pop(&stack);
      if (item != NULL)
        PrintItem(item);
      else
        printf("Stack empty!\n");
    }
    break;

    case 3:
      printf("Clear stack.\n");
      Clear(&stack);
      break;

    case 4:
    {
      printf("Peek at next item.\n");
      Item *item = Peek(stack);
      if (item != NULL)
        PrintItem(item);
      else
        printf("Stack empty!\n");
    }
    break;

    case 5:
    {
      printf("Contains item.\nEnter key to search: ");
      TKey key;
      scanf("%ld", &key);

      if (Contains(stack, key))
        printf("Item exists!\n");
      else
        printf("Item not found!\n");
    }
    break;

    case 6:
      printf("Stack items count: %i\n", Count(stack));
      break;

    case 7:
      printf("Stack items:\n");
      Print(stack);
      break;

    case 8:
    {
      printf("Autofill stack.\nEnter stack size: ");
      int size;
      scanf("%i", &size);
      fflush(stdin);

      stack = Initialize(size);
    }
    break;

    default:
      printf("Option not found!");
      option = -1;
      break;
    }

    printf("\n");
  }

  free(stack.Items);
  system("pause");
}
