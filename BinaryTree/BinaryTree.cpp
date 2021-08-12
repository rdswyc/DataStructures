#include <stdbool.h>

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
