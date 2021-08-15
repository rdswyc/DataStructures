#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#pragma region Structure

#define INPUT_LENGTH 100

typedef long TKey;
typedef char *TValue;

typedef struct node
{
  TKey key;
  TValue value;
  struct node *left, *right;
} Node;

typedef Node *Tree;

#pragma endregion

#pragma region Method headers

int Count(Tree tree);
int CountLeaf(Tree tree);
int CountNonLeaf(Tree tree);
int Height(Tree tree);

void Add(Tree *tree, TKey key, const TValue value);
void Clear(Tree *tree);
bool Contains(Tree tree, TKey key);
Node *Find(Tree tree, TKey key);
Node *FindValue(Tree tree, const TValue value);
Tree Initialize();
Tree Initialize(int size, TKey root = -1, int height = 0);
void PrintNode(Node *node);
void PrintTreeInOrder(Tree tree);
void PrintTreePostOrder(Tree tree);
void PrintTreePreOrder(Tree tree);
void ShowPaths(Tree tree);
void ShowTree(Tree tree, int height = 0);
void Remove(Tree *tree, TKey key);

#pragma endregion

/* TODO: implement remove */
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

#pragma region Properties

int Count(Tree tree)
{
  return tree == NULL ? 0 : 1 + Count(tree->left) + Count(tree->right);
}

int CountLeaf(Tree tree)
{
  if (tree == NULL)
    return 0;

  if (Count(tree->left) + Count(tree->right) == 0)
    return 1;

  return CountLeaf(tree->left) + CountLeaf(tree->right);
}

int CountNonLeaf(Tree tree)
{
  if (tree == NULL || (Count(tree->left) + Count(tree->right)) == 0)
    return 0;

  return 1 + CountNonLeaf(tree->left) + CountNonLeaf(tree->right);
}

int Height(Tree tree)
{
  if (tree == NULL)
    return 0;

  int leftHeight = Height(tree->left);
  int rightHeight = Height(tree->right);

  return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

#pragma endregion

#pragma region Methods

/* TODO: add balanced search tree logic */
void Add(Tree *tree, TKey key, TValue value)
{
  if (*tree == NULL)
  {
    *tree = (Tree)malloc(sizeof(Node));
    (*tree)->value = (TValue)malloc(strlen(value));
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    (*tree)->key = key;
    strcpy((*tree)->value, value);
  }
  else if (key < (*tree)->key)
  {
    Add(&(*tree)->left, key, value);
  }
  else if (key > (*tree)->key)
  {
    Add(&(*tree)->right, key, value);
  }
  else
  {
    printf("Node already exists!\n");
  }
}

void Clear(Tree *tree)
{
  if (*tree == NULL)
    return;

  Clear(&(*tree)->left);
  Clear(&(*tree)->right);

  free(*tree);
  *tree = NULL;
}

bool Contains(Tree tree, TKey key)
{
  if (tree == NULL)
    return false;

  if (tree->key == key)
    return true;

  return key < tree->key
             ? Contains(tree->left, key)
             : Contains(tree->right, key);
}

Node *Find(Tree tree, TKey key)
{
  if (tree == NULL)
    return NULL;

  if (tree->key == key)
    return tree;

  return key < tree->key
             ? Find(tree->left, key)
             : Find(tree->right, key);
}

Node *FindValue(Tree tree, const TValue value)
{
  if (tree == NULL)
    return NULL;

  if (strcmp(value, tree->value) == 0)
    return tree;

  Node *temp = FindValue(tree->left, value);

  if (temp == NULL)
    temp = FindValue(tree->right, value);

  return temp;
}

Tree Initialize()
{
  return NULL;
}

TValue Initialize_RandString()
{
  int length = 7;
  TValue text = (TValue)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

Tree Initialize(int size, TKey root, int height)
{
  Tree tree = Initialize();

  if (root == -1)
    root = pow(2, size - 1);

  Add(&tree, root, Initialize_RandString());

  if (height < size - 1)
  {
    height++;
    TKey diff = pow(2, size - height - 1);

    tree->left = Initialize(size, root - diff, height);
    tree->right = Initialize(size, root + diff, height);
  }

  return tree;
}

void PrintNode(Node *node)
{
  printf("* %i %s\n", node->key, node->value);
}

void PrintTreeInOrder(Tree tree)
{
  if (tree != NULL)
  {
    PrintTreeInOrder(tree->left);
    PrintNode(tree);
    PrintTreeInOrder(tree->right);
  }
}

void PrintTreePostOrder(Tree tree)
{
  if (tree != NULL)
  {
    PrintTreePostOrder(tree->left);
    PrintTreePostOrder(tree->right);
    PrintNode(tree);
  }
}

void PrintTreePreOrder(Tree tree)
{
  if (tree != NULL)
  {
    PrintNode(tree);
    PrintTreePreOrder(tree->left);
    PrintTreePreOrder(tree->right);
  }
}

/* TODO: implement using queue */
void ShowPathsAuxiliar(Tree tree, TKey paths[], int height = 0)
{
  if (tree != NULL)
  {
    paths[height] = tree->key;
    height++;

    if (tree->left == NULL && tree->right == NULL)
    {
      for (int i = 0; i < height; i++)
        printf("%i ", paths[i]);

      printf("\n");
    }
    else
    {
      ShowPathsAuxiliar(tree->left, paths, height);
      ShowPathsAuxiliar(tree->right, paths, height);
    }
  }
}

void ShowPaths(Tree tree)
{
  int size = Height(tree);
  TKey *paths = (TKey *)malloc(size * sizeof(TKey));
  ShowPathsAuxiliar(tree, paths);
}

void ShowTree(Tree tree, int height)
{
  if (tree != NULL)
  {
    ShowTree(tree->left, height + 1);

    for (int i = 0; i < height; i++)
      printf("\t");
    PrintNode(tree);

    ShowTree(tree->right, height + 1);
  }
}

#pragma endregion
