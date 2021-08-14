#include <stdbool.h>
#include <stdlib.h>

#pragma region Structure

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
void PrintNode(Node *node);
void PrintTreeInOrder(Tree tree);
void PrintTreePostOrder(Tree tree);
void PrintTreePreOrder(Tree tree);
void ShowPaths(Tree tree);
void ShowTree(Tree tree, int height = 0);
void Remove(Tree *tree, TKey key);

#pragma endregion

Tree Initialize()
{
  return NULL;
}

int main()
{
  Tree tree = Initialize();

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