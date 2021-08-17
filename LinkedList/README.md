# Linked list

Linked list is a linear data structure opened in both ends, with sequentially linked elements.
List elements are also called nodes, can be of any type and do not need to have a unique identifier.

The list keeps track of the first and last node, and every node will have a value and a reference to the next node.

A doubly linked list is so that each node also has a reference to the previous node, so it can be traversed both ways.

## Implementation

The source code for this solution was divided into three files.
* `LinkedList.h` is the header file, with the structures and the function signatures, to hide internal implementation details.
* `LinkedList.cpp` imports and implements the header file, with the all the underlying logic.
* `main.cpp` is the entry point of the console program and will call the functions in the header file.

Since there are multiple files, building has to take care of all needed dependencies.
Thus, build it by running the following command. You should see a `.exe` file was created on the same directory.
Click it to run the console app.

```
gcc LinkedList.cpp main.cpp -o LinkedList
```

## Remarks

This implementation represents a doubly linked list, updating node references at update.

The structure is so that every node value is of type `T`.
Remember that a key is not mandatory for a list, and it may even accept repeated values.

For simplicity, the node value is set as a `char` pointer but could easily be replaced by any other `struct`, like shown below.

```
typedef struct
{
  int property1;
  char *property2;
  float property3;
} T;
```

In the main program flow, the `T` was also limited to 100 characters, for simplicity.
Notice the implementation structure and functions do not limit any size and will dynamically allocate memory to the input received.

## Properties

### Count

Returns the total number of nodes for a given `LinkedList`.
This is a `O(n)` operation, since every node is traversed sequentially.

```
int Count(LinkedList list);
```

#### Parameters

`list`
The linked list whose node count is returned.

### First

Returns the value of the first node for a given `LinkedList`.
This is a `O(1)` operation, since the list keeps a pointer to the first node.

```
T First(LinkedList list);
```

#### Parameters

`list`
The linked list to get the first node.

### Last

Returns the value of the last node for a given `LinkedList`.
This is a `O(1)` operation, since the list keeps a pointer to the last node.

```
T Last(LinkedList list);
```

#### Parameters

`list`
The linked list to get the last node.

## Methods

### AddAfter

Adds a node to a `LinkedList`, after an existing node. The list must be a reference to a `LinkedList` pointer, and the node must be a reference to and existing `Node` within the list.
This is a `O(1)` operation, considering you already have a pointer to the existing node.

```
Node *AddAfter(LinkedList *list, Node *node, T item);
```

#### Parameters

`list`
The list pointer to add the node.

`node`
A pointer to an existing node within the list.

`item`
The value of the new node.

#### Returns
`Node` A pointer to the node added.

### AddBefore

Adds a node to a `LinkedList`, before an existing node. The list must be a reference to a `LinkedList` pointer, and the node must be a reference to and existing `Node` within the list.
This is a `O(1)` operation, considering you already have a pointer to the existing node.

```
Node *AddBefore(LinkedList *list, Node *node, T item);
```

#### Parameters

`list`
The list pointer to add the node.

`node`
A pointer to an existing node within the list.

`item`
The value of the new node.

#### Returns
`Node` A pointer to the node added.

### AddFirst

Adds a node to the start of a `LinkedList`. The list must be a reference to a `LinkedList` pointer.
This is a `O(1)` operation, since it only takes care of updating the reference pointers of the list.

```
Node *AddFirst(LinkedList *list, T item);
```

#### Parameters

`list`
The list pointer to add the node.

`item`
The value of the new node.

#### Returns
`Node` A pointer to the node added.

### AddLast

Adds a node to the end of a `LinkedList`. The list must be a reference to a `LinkedList` pointer.
This is a `O(1)` operation, since it only takes care of updating the reference pointers of the list.

```
Node *AddLast(LinkedList *list, T item);
```

#### Parameters

`list`
The list pointer to add the node.

`item`
The value of the new node.

#### Returns
`Node` A pointer to the node added.

### Clear

Entirely clears out the `LinkedList`, leaving a null reference to the pointers.
This is a `O(n)` operation, because all nodes are cleared and its memory freed.

```
void Clear(LinkedList *list);
```

#### Parameters

`list`
The linked list to clear.

### Contains

Checks if a given `T` item exists within the `LinkedList` nodes.
It uses a `Compare(T, T)` function to determine if items are equal.
This is a `O(n)` operation, since all nodes need to be searched.

```
bool Contains(LinkedList list, T item);
```

#### Parameters

`list`
The linked list to check for the item.

`item`
The value to check.

#### Returns
`bool` true if an item is found, false otherwise.

### Find

Finds and returns a `Node` pointer for the first `T` item existing within the `LinkedList` nodes.
It searches sequentially from the fist to the last node using a `Compare(T, T)` function to determine if items are equal.
This is a `O(n)` operation, since all nodes need to be searched.

```
Node *Find(LinkedList list, T item);
```

#### Parameters

`list`
The linked list to find the node.

`item`
The value to check.

### FindLast

Finds and returns a `Node` pointer for the last `T` item existing within the `LinkedList` nodes.
It searches sequentially from the last to the first node using a `Compare(T, T)` function to determine if items are equal.
This is a `O(n)` operation, since all nodes need to be searched.

```
Node *FindLast(LinkedList list, T item);
```

#### Parameters

`list`
The linked list to find the node.

`item`
The value to check.

#### Returns
`Node` A pointer to the node found, or `NULL` if not found.

### Initialize

Initializes a new instance of the `LinkedList`.
In Object-oriented programming, those would be the constructor methods.
There are two overloads available; the first one will return a null pointer reference, simply initializing an empty list; the second one will auto fill all the nodes of the list with a random string value.
This later approach can be used for testing purposes.

```
LinkedList Initialize();
LinkedList Initialize(int capacity);
```

#### Parameters

`capacity`
The size of the linked list to create, meaning the number of nodes from the fist to the last nodes.

#### Returns
`LinkedList` An instance of a new list.

### Print

Prints the entire `LinkedList` using the `PrintNode()` function, from the first to the last nodes.

```
void Print(LinkedList list);
```

#### Parameters

`list`
The linked list to be printed.

### PrintNode

Simple function to print a single `Node` to the console.
It will print the node value, the previous node value and the next node value, if existing.
This is referenced by the `Print()` method but can also be used externally.

```
void PrintNode(Node node);
```

#### Parameters

`node`
The pointer to an existing list node.

### Remove

Removes a specific `Node` from the `LinkedList`.
The list must be a reference to a `LinkedList` pointer, and the node must be a reference to and existing `Node` within the list.
This is a `O(1)` operation, considering you already have a pointer to the existing node.

```
void Remove(LinkedList *list, Node *node);
```

#### Parameters

`list`
The list pointer to remove the node.

`node`
A pointer to the node to remove.

### RemoveFirst

Removes the first node from the `LinkedList`.
The list must be a reference to a `LinkedList` pointer.
This is a `O(1)` operation, since it only takes care of updating the reference pointers of the list and freeing memory.

```
void RemoveFirst(LinkedList *list);
```

#### Parameters

`list`
The list pointer to remove the first node.

### RemoveLast

Removes the last node from the `LinkedList`.
The list must be a reference to a `LinkedList` pointer.
This is a `O(1)` operation, since it only takes care of updating the reference pointers of the list and freeing memory.

```
void RemoveLast(LinkedList *list);
```

#### Parameters

`list`
The list pointer to remove the last node.