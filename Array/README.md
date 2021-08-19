# Array

Array is a collection of similar data items that can be accessed by an index.
The size of an array is defined at declaration, thus it is not dynamic.
Although it is possible to change the size of an array, it requires memory allocation and may be costly.

Elements can be of any type and will each have a sequential index.

## Implementation

The source code for this solution was divided into three files.
* `Array.h` is the header file, with the structures and the function signatures, to hide internal implementation details.
* `Array.cpp` imports and implements the header file, with the all the underlying logic.
* `Sort.cpp` imports the header file and implements the sorting methods.
* `main.cpp` is the entry point of the console program and will call the functions in the header file.

Since there are multiple files, building has to take care of all needed dependencies.
Thus, build it by running the following command. You should see a `.exe` file was created on the same directory.
Click it to run the console app.

```
gcc Array.cpp Sort.cpp main.cpp -o Array
```

## Remarks

This implementation represents a fixed size array of elements. The array is initialized with null items.
To start off, you need to enter the size of the array, for a fixed allocation and to be available for the other functions.
Since it is not possible to determine the size of an array from an external function, the size needs to be passed to every function that will traverse the array.

The structure is so that every item is of type `T`.
Remember that a key is not mandatory for an array, and it may even accept repeated values.

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

## Methods

### Autofill

Auto fill all the items of the array with a random string value.
This approach can be used for testing purposes.

```
void Autofill(T array[], int size);
```

#### Parameters

`array`
The array to auto fill.

`size`
The size of the array.

### BinarySearch

Given a sorted array, check if a given item `T` exists within the `T[]` array and returns the first index of it.
It splits the array in two halves, looking for the closest value.
If the item is not found, it returns `-1`.
This is a `O(log n)` operation, since it is a divide and conquer algorithm.

```
int BinarySearch(T array[], int size, T item);
```

#### Parameters

`array`
The sorted array to check for the item.

`size`
The size of the array.

`item`
The item to get the index.

#### Returns

`int` the first index of the item in the sorted array, or `-1` if not found.

### Clear

Entirely clears out the `T[]` array, leaving a null reference to each item.
This is a `O(n)` operation, since every item is cleared sequentially.

```
void Clear(T array[], int size);
```

#### Parameters

`array`
The array to clear.

`size`
The size of the array.

### CompareItems

Utility to compare two `T` items, and determine if `item1` is lower, greater or equal to `item2`.
This is used by the `BinarySearch()` and `Sort()` functions but can also be used externally.

```
int CompareItems(T item1, T item2);
```

#### Parameters

`item1`
First array item to compare.

`item2`
Second array item to compare.

#### Returns

`int` the result of the comparison where negative means `item1` is lower than `item2`, positive means `item1` is greater than `item2` and zero when they are equal.

### IndexOf

Checks if a given item `T` exists within the `T[]` array and returns the first index of it.
It uses a `Equals(T, T)` function to determine if items are equal.
If the item is not found, it returns `-1`.
This is a `O(n)` operation, since it is a linear search algorithm.

```
int IndexOf(T array[], int size, T item);
```

#### Parameters

`array`
The array to check for the item.

`size`
The size of the array.

`item`
The item to get the index.

#### Returns

`int` the first index of the item in the array, or `-1` if not found.

### LastIndexOf

Checks if a given item `T` exists within the `T[]` array and returns the last index of it.
It uses a `Equals(T, T)` function to determine if items are equal.
If the item is not found, it returns `-1`.
This is a `O(n)` operation, since since it is a linear search algorithm.

```
int LastIndexOf(T array[], int size, T item);
```

#### Parameters

`array`
The array to check for the item.

`size`
The size of the array.

`item`
The item to get the last index.

#### Returns

`int` the last index of the item in the array, or `-1` if not found.

### Print

Prints the entire `T[]` array using the `PrintItem()` function, in the order the items are set.

```
void Print(T array[], int size);
```

#### Parameters

`array`
The array to be printed.

`size`
The size of the array.

### PrintItem

Simple function to print a single `T` item to the console.
This is referenced by the `Print()` method but can also be used externally.

```
void PrintItem(T item);
```

#### Parameters

`item`
An existing array item to print.

### Reverse

Reverses the order of items in the `T[]` array using a `SwapItems(T, T)` function.
This is a `O(n)` operation, even considering that two items are changed together in a single iteration.

```
void Reverse(T array[], int size);
```

#### Parameters

`array`
The array to reverse.

`size`
The size of the array.

### SetValue

Sets a `T` value to a specific array item.
This is a `O(1)` operation, since the array item is set by index.

```
void SetValue(T array[], int index, T value);
```

#### Parameters

`array`
The array whose item is set.

`index`
The index of the item to set.

`value`
The value to set.

### Sort

Method to sort the array using some of the most known algorithms:
buble sort, selection sort, insertion sort, merge sort and quick sort.
It will initially prompt the user to choose the algorithm and proceed with the selected option.
Prior to sorting the array, you need to make sure there are no null items.
Most of the sorting functions are a `O(n^2)` operation in the worst case, but there might be differences if the array is already sorted, partially sorted or in a total reverse order.

```
void Sort(T array[], int size);
```

#### Parameters

`array`
The array to sort.

`size`
The size of the array.

### SwapItems

Utility to swap two `T` items, using a temporary variable allocation.
This is used by the `Reverse()` and `Sort()` functions but can also be used externally.

```
void SwapItems(T item1, T item2);
```

#### Parameters

`item1`
An array item to swap.

`item2`
Another array item to swap.