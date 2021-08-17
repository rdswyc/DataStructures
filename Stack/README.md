# Stack

Stack is a data structure where items are collected in a Last-In-First-Out (LIFO) fashion.
This means that adding an item to the stack puts it at last and removing gets the newest one.

Elements can be of any type and do not need to have a unique identifier.

## Implementation

The source code for this solution was divided into three files.
* `Stack.h` is the header file, with the structures and the function signatures, to hide internal implementation details.
* `Stack.cpp` imports and implements the header file, with the all the underlying logic.
* `main.cpp` is the entry point of the console program and will call the functions in the header file.

Since there are multiple files, building has to take care of all needed dependencies.
Thus, build it by running the following command. You should see a `.exe` file was created on the same directory.
Click it to run the console app.

```
gcc Stack.cpp main.cpp -o Stack
```

## Remarks

This implementation represents a non-linked stack of elements with a capacity field.

The structure is so that every item is of type `T`.
Remember that a key is not mandatory for a stack, and it may even accept repeated values.

For simplicity, the item is set as a `char` pointer but could easily be replaced by any other `struct`, like shown below.

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

Returns the total number of items for a given `Stack`.
This is a `O(1)` operation, since the capacity is kept as a field in the stack.

```
int Count(Stack stack);
```

#### Parameters

`stack`
The stack whose item count is returned.

## Methods

### Clear

Entirely clears out the `Stack`, leaving a null reference to the items pointer.
This is a `O(1)` operation.

```
void Clear(Stack *stack);
```

#### Parameters

`stack`
The stack to clear.

### Contains

Checks if a given item `T` exists within the `Stack` items.
It uses a `Compare(T, T)` function to determine if items are equal.
This is a `O(n)` operation, since all items need to be searched.

```
bool Contains(Stack stack, T item);
```

#### Parameters

`stack`
The stack to check for the item.

`item`
The item to check.

#### Returns
`bool` true if an item is found, false otherwise.

### Initialize

Initializes a new instance of the `Stack`.
In Object-oriented programming, those would be the constructor methods.
There are two overloads available; the first one will return an empty stack with capacity zero; the second one will auto fill all the items of the stack with a random string value.
This later approach can be used for testing purposes.

```
Stack Initialize();
Stack Initialize(int capacity);
```

#### Parameters

`capacity`
The capacity of the stack to create, meaning the number of items it will contain.

#### Returns
`Stack` An instance of a new stack.

### Peek

Function to return the next item to be deleted by calling `Pop()`, without removing the element.

```
T *Peek(Stack stack);
```

#### Parameters

`stack`
The stack to peek the item.

#### Returns
`T` A pointer to the item within the stack.

### Pop

Removes the newest item from the `Stack`, the one that was added last.
This is a `O(1)` operation, since the function will resize the items memory and then free the last one.

```
T *Pop(Stack *stack);
```

#### Parameters

`stack`
The stack pointer to remove the item.

#### Returns
`T` The removed item from the stack.

### Print

Prints the entire `Stack` using the `PrintItem()` function, in the order the items where added.

```
void Print(Stack stack);
```

#### Parameters

`stack`
The stack to be printed.

### PrintItem

Simple function to print a single `T` item to the console.
This is referenced by the `Print()` method but can also be used externally.

```
void PrintItem(T item);
```

#### Parameters

`item`
An existing stack item to print.

### Push

Adds an item to the end of the `Stack`. The stack must be a reference to a `Stack` pointer.
This is a `O(1)` operation, since it puts the new item at the end of the stack.

```
void Push(Stack *stack, T item);
```

#### Parameters

`stack`
The stack pointer to add the item.

`item`
The new item to add.