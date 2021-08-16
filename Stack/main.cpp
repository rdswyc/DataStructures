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
      printf("**   1 Push item. 2 Pop item. 3 Clear stack.\n");
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
      printf("Push item.\nEnter item value: ");
      T item = (T)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", item);

      Push(&stack, item);
    }
    break;

    case 2:
    {
      printf("Pop item.\n");
      T *item = Pop(&stack);
      if (item != NULL)
        PrintItem(*item);
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
      T *item = Peek(stack);
      if (item != NULL)
        PrintItem(*item);
      else
        printf("Stack empty!\n");
    }
    break;

    case 5:
    {
      printf("Contains item.\nEnter value to search: ");
      T item = (T)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", item);

      if (Contains(stack, item))
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
