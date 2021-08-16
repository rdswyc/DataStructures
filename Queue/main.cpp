#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define INPUT_LENGTH 100

int main()
{
  printf("\n****************************\n");
  printf("*********** QUEUE **********\n");
  printf("****************************\n\n");

  Queue queue = Initialize();

  int option = -1;

  while (option != 0)
  {
    if (option == -1)
    {
      printf("**** Choose an option:  ****\n");
      printf("**   1 Enqueue item. 2 Dequeue item. 3 Clear queue.\n");
      printf("**   4 Peek item. 5 Contains item. 6 Items count.\n");
      printf("**   7 Print queue. 8 Autofill queue.\n");
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
      printf("Enqueue item.\nEnter item value: ");
      T item = (T)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", item);

      Enqueue(&queue, item);
    }
    break;

    case 2:
    {
      printf("Dequeue item.\n");
      T *item = Dequeue(&queue);
      if (item != NULL)
        PrintItem(*item);
      else
        printf("Queue empty!\n");
    }
    break;

    case 3:
      printf("Clear queue.\n");
      Clear(&queue);
      break;

    case 4:
    {
      printf("Peek at next item.\n");
      T *item = Peek(queue);
      if (item != NULL)
        PrintItem(*item);
      else
        printf("Queue empty!\n");
    }
    break;

    case 5:
    {
      printf("Contains item.\nEnter value to search: ");
      T item = (T)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", item);

      if (Contains(queue, item))
        printf("Item exists!\n");
      else
        printf("Item not found!\n");
    }
    break;

    case 6:
      printf("Queue items count: %i\n", Count(queue));
      break;

    case 7:
      printf("Queue items:\n");
      Print(queue);
      break;

    case 8:
    {
      printf("Autofill queue.\nEnter queue size: ");
      int size;
      scanf("%i", &size);
      fflush(stdin);

      queue = Initialize(size);
    }
    break;

    default:
      printf("Option not found!");
      option = -1;
      break;
    }

    printf("\n");
  }

  free(queue.Items);
  system("pause");
}
