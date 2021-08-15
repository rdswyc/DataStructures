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
      printf("**   1 Enqueue. 2 Dequeue. 3 Clear queue.\n");
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
      printf("Enqueue item.\nEnter item key: ");
      Item item;
      scanf("%ld", &item.key);
      fflush(stdin);

      printf("Enter item value: ");
      item.value = (TValue)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", item.value);

      Enqueue(&queue, &item);
    }
    break;

    case 2:
    {
      printf("Dequeue item.\n");
      Item *item = Dequeue(&queue);
      if (item != NULL)
        PrintItem(item);
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
      Item *item = Peek(queue);
      if (item != NULL)
        PrintItem(item);
      else
        printf("Queue empty!\n");
    }
    break;

    case 5:
    {
      printf("Contains item.\nEnter key to search: ");
      TKey key;
      scanf("%ld", &key);

      if (Contains(queue, key))
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
