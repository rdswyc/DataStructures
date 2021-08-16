#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <math.h>

#include "BinaryTree.h"

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
    Add(&(*tree)->left, key, value);
  else if (key > (*tree)->key)
    Add(&(*tree)->right, key, value);
  else
    printf("Node already exists!\n");
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
  printf("* %ld %s\n", node->key, node->value);
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
        printf("%ld ", paths[i]);

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

/* TODO: implement remove */

#pragma endregion