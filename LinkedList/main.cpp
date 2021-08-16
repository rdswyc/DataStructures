#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

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
  printf("******* Linked List ********\n");
  printf("****************************\n\n");

  List list = Initialize();

  int option = -1;

  while (option != 0)
  {
    if (option == -1)
    {
      printf("**** Choose an option:  ****\n");
      printf("**   1 Add first. 2 Add last. 3 Add after. 4 Add before.\n");
      printf("**   5 Remove node. 6 Remove first. 7 Remove last.\n");
      printf("**   8 Clear list. 9 Find node. 10 Find last.\n");
      printf("**   11 List properties. 12 Print list. 13 Autofill list.\n");
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
      T item = GetInput("Add node first.\nEnter node value: ");
      AddFirst(&list, item);
    }
    break;

    case 2:
    {
      T item = GetInput("Add node last.\nEnter node value: ");
      AddLast(&list, item);
    }
    break;

    case 3:
    {
      T item = GetInput("Add after node.\nEnter existing node value: ");
      fflush(stdin);

      Node *node = Find(list, item);
      if (node == NULL)
        printf("Node not found!\n");
      else
      {
        printf("Enter new node value: ");
        scanf("%[^\n]s", item);

        AddAfter(&list, node, item);
      }
    }
    break;

    case 4:
    {
      T item = GetInput("Add before node.\nEnter existing node value: ");
      fflush(stdin);

      Node *node = Find(list, item);
      if (node == NULL)
        printf("Node not found!\n");
      else
      {
        printf("Enter new node value: ");
        scanf("%[^\n]s", item);

        AddBefore(&list, node, item);
      }
    }
    break;

    case 5:
    {
      T item = GetInput("Remove node.\nEnter value to remove: ");

      Node *node = Find(list, item);
      if (node == NULL)
        printf("Node not found!\n");
      else
        Remove(&list, node);
    }
    break;

    case 6:
      printf("Remove first node.\n");
      RemoveFirst(&list);
      break;

    case 7:
      printf("Remove last node.\n");
      RemoveLast(&list);
      break;

    case 8:
      printf("Clear list.\n");
      Clear(&list);
      break;

    case 9:
    {
      T item = GetInput("Find node.\nEnter value to search: ");

      Node *node = Find(list, item);
      if (node == NULL)
        printf("Node not found!\n");
      else
        PrintNode(*node);
    }
    break;

    case 10:
    {
      T item = GetInput("Find last node.\nEnter value to search: ");

      Node *node = FindLast(list, item);
      if (node == NULL)
        printf("Node not found!\n");
      else
        PrintNode(*node);
    }
    break;

    case 11:
      printf("List properties:\n");
      printf("Count: %i\n", Count(list));
      printf("First node: %s\n", First(list));
      printf("Last node: %s\n", Last(list));
      break;

    case 12:
      printf("List nodes:\n");
      Print(list);
      break;

    case 13:
    {
      printf("Autofill list.\nEnter list size: ");
      int size;
      scanf("%i", &size);
      fflush(stdin);

      list = Initialize(size);
    }
    break;

    default:
      printf("Option not found!");
      option = -1;
      break;
    }

    printf("\n");
  }

  free(list.first);
  system("pause");
}
