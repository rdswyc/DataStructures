# Binary tree

Binary tree is a data structure where every element has at most two children.
Tree elements are also called nodes and every node has a key, and additional value properties.

Nodes with no child nodes are called leaves.

A tree height is the number of nodes existing from the root to the far-most leaf.

A tree is called binary search tree if the left node key is smaller than the root node key, and the right node key is greater than the root node key. Additionally, every node has a unique key.

A binary tree may also be balanced, when each subtree of every node has a similar, if not equal, height.

## Implementation

The source code for this solution was divided into three files.
* `BinaryTree.h` is the header file, with the structures and the function signatures, to hide internal implementation details.
* `BinaryTree.cpp` imports and implements the header file, with the all the underlying logic.
* `main.cpp` is the entry point of the console program and will call the functions in the header file.

Since there are multiple files, building has to take care of all needed dependencies.
Thus, build it by running the following command. You should see a `.exe` file was created on the same directory.
Click it to run the console app.

```
gcc BinaryTree.cpp main.cpp -o BinaryTree
```

## Remarks

This implementation represents a binary search tree, balanced whenever a new node is added.

The structure is so that every `Node` has a `TKey` key and a `TValue` value.

For simplicity, the value is set as a `char` pointer but could easily be replaced by any other `struct`, like shown below.

```
typedef struct
{
  int property1;
  char *property2;
  float property3;
} TValue;
```

In the main program flow, the `TValue` was also limited to 100 characters, for simplicity.
Notice the implementation structure and functions do not limit any size and will dynamically allocate memory to the input received.

## Properties

### Count

Returns the total number of nodes for a given `Tree`.
This is a `O(n)` operation, since every node is traversed recursively.

```
int Count(Tree tree);
```

#### Parameters

`tree`
The binary tree whose node count is returned.

### CountLeaf

Returns the total number of leaf nodes for a given `Tree`.
This is a `O(n)` operation, since for every node traversed, it's child might also be checked.

```
int CountLeaf(Tree tree);
```

#### Parameters

`tree`
The binary tree whose leaf count is returned.

### CountNonLeaf

Returns the total number of non-leaf nodes for a given `Tree`.
This is a `O(n)` operation, since for every node traversed, it's child might also be checked.

```
int CountNonLeaf(Tree tree);
```

#### Parameters

`tree`
The binary tree whose non-leaf count is returned.

### Height

Returns the height of a given `Tree`.
This is a `O(n)` operation, since every node is traversed recursively.

```
int Height(Tree tree);
```

#### Parameters

`tree`
The binary tree whose height is returned.

## Methods

### Add

Adds a node to a `Tree`, with a key and value. The tree must be a reference to a `Tree` pointer.
This is a `O(log n)` operation, since it first needs to find the matching node to then insert a new one.

```
void Add(Tree *tree, TKey key, const TValue value);
```

#### Parameters

`tree`
The tree pointer to add the node.

`key`
The key of the new node.

`value`
The string value of the new node.

### Clear

Entirely clears out the `Tree`, leaving a null reference to the pointer.
This is a `O(n)` operation, because all nodes are cleared and its memory freed.

```
void Clear(Tree *tree);
```

#### Parameters

`tree`
The binary tree to clear.

### Contains

Checks if a given `TKey` exists within the `Tree` nodes.
This is a `O(log n)` operation, since the tree is balanced and not all nodes need to be searched.

```
bool Contains(Tree tree, TKey key);
```

#### Parameters

`tree`
The binary tree to check for the key.

`key`
The key to check.

#### Returns

`bool` true if an item is found, false otherwise.

### Find

Finds and returns a `Node` pointer, when a `TKey` exists within the `Tree` nodes.
This is a `O(log n)` operation, since the tree is balanced and not all nodes need to be searched.

```
Node *Find(Tree tree, TKey key);
```

#### Parameters

`tree`
The binary tree to find the node.

`key`
The key to search.

#### Returns

`Node` A pointer to the node found, or `NULL` if not found.

### FindValue

Finds and returns a `Node` pointer, based on a `TValue`, which can be a static string or a pointer to a character array.
It uses a `Equals(TValue, TValue)` function to determine if items are equal.
This is a `O(n)` operation, because all nodes need to be searched.

```
Node *FindValue(Tree tree, const TValue value);
```

#### Parameters

`tree`
The binary tree to find the node.

`value`
The value to search.

#### Returns

`Node` A pointer to the node found, or `NULL` if not found.

### Initialize

Initializes a new instance of the `Tree`.
In Object-oriented programming, those would be the constructor methods.
There are two overloads available; the first one will return a null pointer reference, simply initializing an empty tree; the second one will auto fill all the nodes of the tree with an integer key and a random string value.
This later approach can be used for testing purposes.

```
Tree Initialize();
Tree Initialize(int size, TKey root = -1, int height = 0);
```

#### Parameters

`size`
The size of the binary tree to create, meaning the number of nodes from the root to the far most leaf.

`root`
The optional root node value.

`height`
The current height of the node being created.
It starts with 0 and increases as the tree build up continues.

#### Returns

`Tree` An instance of a new tree.

### PrintNode

Simple function to print a single `Node` to the console.
This will be referenced in all other print methods, meaning the output for each node is defined by this function.

```
void PrintNode(Node *node);
```

#### Parameters

`node`
The pointer to an existing tree node.

### PrintTreeInOrder

Prints the entire `Tree` in order: left-root-right.

```
void PrintTreeInOrder(Tree tree);
```

#### Parameters

`tree`
The binary tree to be printed.

### PrintTreePostOrder

Prints the entire `Tree` post order: left-right-root.

```
void PrintTreePostOrder(Tree tree);
```

#### Parameters

`tree`
The binary tree to be printed.

### PrintTreePreOrder

Prints the entire `Tree` pre order: root-left-right.

```
void PrintTreePreOrder(Tree tree);
```

#### Parameters

`tree`
The binary tree to be printed.

### ShowPaths

Utility to print all the root-to-leaf paths for the `Tree`. It uses a Depth First Search.
For a compact display, it will only print the keys.

```
void ShowPaths(Tree tree);
```

#### Parameters

`tree`
The binary tree whose paths will be shown.

### ShowTree

Utility to pretty print the entire `Tree` in a horizontal 2D style.

```
void ShowTree(Tree tree, int height = 0);
```

#### Parameters

`tree`
The binary tree to show.

### Remove

Remove a node from the `Tree`.
This is a `O(log n)` operation.

```
void Remove(Tree *tree, TKey key);
```

#### Parameters

`tree`
The tree pointer to remove the node.

`key`
The key of node to remove.