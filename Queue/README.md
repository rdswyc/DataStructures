# Queue

Queue is a data structure where items are collected in a First-In-First-Out (FIFO) fashion.
This means that adding an item to the queue puts it at last and removing gets the oldest one.

Elements can be of any type and do not need to have a unique identifier.

## Implementation

The source code for this solution was divided into three files.
* `Queue.h` is the header file, with the structures and the function signatures, to hide internal implementation details.
* `Queue.cpp` imports and implements the header file, with the all the underlying logic.
* `main.cpp` is the entry point of the console program and will call the functions in the header file.

Since there are multiple files, building has to take care of all needed dependencies.
Thus, build it by running the following command. You should see a `.exe` file was created on the same directory.
Click it to run the console app.

```
gcc Queue.cpp main.cpp -o Queue
```

## Remarks

This implementation represents a non-linked queue of elements with a capacity field.

The structure is so that every `Item` has a `TKey` key and a `TValue` value.
Remember that a key is not mandatory for a queue, and it may even accept repeated values.

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

Returns the total number of items for a given `Queue`.
This is a `O(1)` operation, since the capacity is kept as a field in the queue.

```
int Count(Queue queue);
```

#### Parameters

`queue`
The queue whose item count is returned.

## Methods

### Clear

Entirely clears out the `Queue`, leaving a null reference to the items pointer.
This is a `O(1)` operation.

```
void Clear(Queue *queue);
```

#### Parameters

`queue`
The queue to clear.

### Contains

Checks if a given `TKey` exists within the `Queue` items.
This is a `O(n)` operation, since all items need to be searched.

```
bool Contains(Queue queue, TKey key);
```

#### Parameters

`queue`
The queue to check for the key.

`key`
The key to check.

#### Returns
`bool` true if an item is found, false otherwise.

### Dequeue

Removes the oldest item from the `Queue`, the one that was added first.
Although this is considered a `O(1)` operation, in theory, the function has to move all the memory blocks one step back, item by item and then free the last one.

```
Item *Dequeue(Queue *queue);
```

#### Parameters

`queue`
The queue pointer to remove the item.

#### Returns
`Item` The removed item from the queue.

### Enqueue

Adds an item to a `Queue`, with a key and value. The queue must be a reference to a `Queue` pointer.
This is a `O(1)` operation, since it puts the new item at the end of the queue.

```
void Enqueue(Queue *queue, Item *item);
```

#### Parameters

`queue`
The queue pointer to add the item.

`item`
A pointer to the new item to add.

### Initialize

Initializes a new instance of the `Queue`.
In Object-oriented programming, those would be the constructor methods.
There are two overloads available; the first one will return an empty queue with capacity zero; the second one will auto fill all the items of the queue with an integer key and a random string value.
This later approach can be used for testing purposes.

```
Queue Initialize();
Queue Initialize(int capacity);
```

#### Parameters

`capacity`
The capacity of the queue to create, meaning the number of items it will contain.

#### Returns
`Queue` An instance of a new queue.

### Peek

Function to return the next item to be deleted by calling `Dequeue()`, without removing the element.

```
Item *Peek(Queue queue);
```

#### Parameters

`queue`
The queue to peek the item.

#### Returns
`Item` A pointer to the item within the queue.

### Print

Prints the entire `Queue` using the `PrintItem()` function, in the order the items where added.

```
void Print(Queue queue);
```

#### Parameters

`queue`
The queue to be printed.

### PrintItem

Simple function to print a single `Item` to the console.
This is referenced by the `Print()` method but can also be used externally.

```
void PrintItem(Item *item);
```

#### Parameters

`item`
The pointer to an existing queue item.