#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

#define INPUT_LENGTH 100

int main()
{
  printf("\n****************************\n");
  printf("**** Binary search tree ****\n");
  printf("****************************\n\n");

  Tree tree = Initialize();

  int option = -1;

  while (option != 0)
  {
    if (option == -1)
    {
      printf("**** Choose an option:  ****\n");
      printf("**   1 Add node. 2 Remove node. 3 Clear tree.\n");
      printf("**   4 Find key. 5 Find value. 6 Tree Properties.\n");
      printf("**   7 Print in-order. 8 Print pre-order. 9 Print post-order.\n");
      printf("**   10 Show paths. 11 Show tree. 12 Autofill tree.\n");
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
      printf("Add tree node.\nEnter node key: ");
      TKey key;
      scanf("%i", &key);
      fflush(stdin);

      printf("Enter node value: ");
      TValue value = (TValue)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", value);

      Add(&tree, key, value);
    }
    break;

    case 2:
      break;

    case 3:
      printf("Clear tree.\n");
      Clear(&tree);
      break;

    case 4:
    {
      printf("Find node by key.\nEnter key: ");
      TKey key;
      scanf("%i", &key);

      Node *node = Find(tree, key);
      if (node != NULL)
        PrintNode(node);
      else
        printf("Node not found!\n");
    }
    break;

    case 5:
    {
      printf("Find node by value.\nEnter value: ");
      TValue value = (TValue)malloc(INPUT_LENGTH * sizeof(char));
      scanf("%[^\n]s", value);

      Node *node = FindValue(tree, value);
      if (node != NULL)
        PrintNode(node);
      else
        printf("Node not found!\n");
    }
    break;

    case 6:
      printf("Tree properties:\n");
      printf("Count: %i\n", Count(tree));
      printf("CountLeaf: %i\n", CountLeaf(tree));
      printf("CountNonLeaf: %i\n", CountNonLeaf(tree));
      printf("Height: %i\n", Height(tree));
      break;

    case 7:
      printf("Tree nodes in order:\n");
      PrintTreeInOrder(tree);
      break;

    case 8:
      printf("Tree nodes pre order:\n");
      PrintTreePreOrder(tree);
      break;

    case 9:
      printf("Tree nodes post order:\n");
      PrintTreePostOrder(tree);
      break;

    case 10:
      printf("Tree paths:\n");
      ShowPaths(tree);
      break;

    case 11:
      printf("Tree horizontal 2D:\n");
      ShowTree(tree, 0);
      break;

    case 12:
    {
      printf("Autofill tree.\nEnter tree size: ");
      int size;
      scanf("%i", &size);
      fflush(stdin);

      tree = Initialize(size);
    }
    break;

    default:
      printf("Option not found!");
      option = -1;
      break;
    }

    printf("\n");
  }

  free(tree);
  system("pause");
}
