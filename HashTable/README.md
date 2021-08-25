# Hash table

Hash table is an associative array that maps keys to values for fast operations.
Each element will have a key unique and an associated position in the table.

The position, also called hash code, will be determined by the hash function, which will map keys to positions.
Each unique position in the array is called a bucket and may contain one or more items.
That happens when the hash function returns an equal code for different keys, causing a collision.

There are two collision handling techniques
- Separate chaining: each bucket will have many items linked to each other
- Open addressing: the collision item is stored in the same table at the next available position.

A parameter called load factor is set as the number of items in the hash table divided by the number of buckets it contains.
To prevent collision, the load factor should be limited by a threshold. If this value is reached, the table is resized, and all the items are rehashed to the new capacity.

The literature shows that to produce a maximum spread of the items within the hash table and reduce collision, the bucket size must be a prime number.

## Implementation

The source code for this solution was divided into three files.
* `HashTable.h` is the header file, with the structures and the function signatures, to hide internal implementation details.
* `HashTable.cpp` imports and implements the header file, with the all the underlying logic.
* `main.cpp` is the entry point of the console program and will call the functions in the header file.

Since there are multiple files, building has to take care of all needed dependencies.
Thus, build it by running the following command. You should see a `.exe` file was created on the same directory.
Click it to run the console app.

```
gcc HashTable.cpp main.cpp -o HashTable
```

## Remarks

This implementation represents a hash table with open addressing as the collision mechanism.
The hash table will initialize with a small bucket size and increase as items get added.
The load factor is kept at 1/8 to 1/2 of the hash table at set and remove operations.
For the bucket sizes, a couple of prime numbers were provided to serve as the sizing options for the hash table.

Every `Item` has a `TKey` key and a `TValue` value, both being a `char` pointer but could easily be replaced by any other `struct`, like shown below.

```
typedef unsigned long TKey;

typedef struct
{
  int property1;
  char *property2;
  float property3;
} TValue;
```

In the main program flow, the input for each property was also limited to 100 characters, for simplicity.
Notice the implementation structure and functions do not limit any size and will dynamically allocate memory to the input received.

## Properties

### Buckets

Returns the total number of buckets in a `HashTable`.
This is a `O(1)` operation, since the value is stored in the table structure.

```
int Buckets(HashTable table);
```

#### Parameters

`table`
The hash table to return the number of buckets.

### Count

Returns the total number of items in the `HashTable`.
This is a `O(1)` operation, since the value is stored in the table structure.

```
int Count(HashTable table);
```

#### Parameters

`table`
The hash table to return the count of items.

### LoadFactor

Returns the load factor of the `HashTable`, the relation of the number of items by the number of buckets.

```
float LoadFactor(HashTable table);
```

#### Parameters

`table`
The hash table to return the load factor.

## Methods

### Autofill

Auto fill the buckets of the hash table with a random string key and value, considering the max load factor threshold.
This approach can be used for testing purposes.

```
void AutoFill(HashTable *table);
```

#### Parameters

`table`
A pointer for the hash table to auto fill.

### Clear

Entirely clears out the `HashTable`, leaving a small number of empty buckets.
This is a `O(1)` operation, because it creates a new empty hash table replacing the original one.

```
void Clear(HashTable *table);
```

#### Parameters

`table`
A pointer for the hash table to clear.

### ContainsKey

Checks if a given item with a `TKey` exists within the `HashTable` buckets.
It uses the `Equals(TKey, TKey)` function to determine if items are equal.
This is a `O(1)` operation, considering a half full hash table with small collisions.

```
bool ContainsKey(HashTable table, const TKey key);
```

#### Parameters

`table`
The hash table to check for the key.

`key`
The key to check.

#### Returns

`bool`
True if an item with that key is found, false otherwise.

### ContainsValue

Checks if a given item with a `TValue` exists within the `HashTable` buckets, checking value by value.
This is a `O(n)` operation, since all items need to be searched.

```
bool ContainsValue(HashTable table, const TValue value);
```

#### Parameters

`table`
The hash table to check for the value.

`value`
The value to check.

#### Returns

`bool`
True if an item with that value is found, false otherwise.

### FindValue

Finds and returns an `Item` pointer for the first item within the `HashTable` buckets with the specified value.
It searches sequentially from the fist to the last item.
This is a `O(n)` operation, since all items need to be searched.

```
Item *FindValue(HashTable table, const TValue value);
```

#### Parameters

`table`
The hash table to find the item.

`value`
The value to check.

#### Returns

`Item`
A pointer to the item found.

### Get

Get a pointer for the `Item` within the `HashTable` matching the key specified.
It uses the `Equals(TKey, TKey)` function to determine if keys are equal.
This is a `O(1)` operation, considering a half full hash table with small collisions.

```
Item *Get(HashTable table, const TKey key);
```

#### Parameters

`table`
The hash table to check for the key.

`key`
The key of the item to get.

#### Returns

`Item`
A pointer to the item.

### HashFunction

The function to map keys to buckets in the `HashTable`.
Considering the key is a char pointer, this function converts each char to an integer with base 31 and sums up the rest of the division by the number of buckets.
By doing so, it spreads char values to the available bucket size.


```
unsigned HashFunction(const TKey key, int buckets);
```

#### Parameters

`key`
The key to hash.

`buckets`
The number of buckets in the hash table.

#### Returns

`unsigned`
The unsigned integer hash code of the key.

### Initialize

Initializes a new instance of the `HashTable`.
In Object-oriented programming, this would be the constructor method.
If the capacity is specified, it will initialize an empty hash table with the next available bucket size.
Otherwise, it will initialize an empty hash table with the smallest bucket size available.

```
HashTable Initialize(int capacity = 0);
```

#### Parameters

`capacity`
The optional size of the hash table to create, meaning the number of buckets it will contain.

#### Returns

`HashTable`
An instance of a new hash table.

### Print

Prints the entire `HashTable` using the `PrintBucket()` function, considering the non-empty buckets.

```
void Print(HashTable table);
```

#### Parameters

`table`
The hash table to be printed.

### PrintBucket

Simple function to print a single `Item` bucket to the console.
If an index is provided, it will also print it, along with the key and value.
This is referenced by the `Print()` method but can also be used externally.

```
void PrintBucket(Item item, int index = -1);
```

#### Parameters

`item`
The item to print.

`index`
The optional index of the bucket in the hash table.

### Rehash

Resizes the `HashTable` and rehashes all its items to the new bucket size.
It is used to increase or decrease the number of items and allow the load factor to figure within the thresholds defined.
This is a `O(n)` operation, since it will create a copy of the table and rehash each item to a new table.

```
void Rehash(HashTable *table, int size);
```

#### Parameters

`table`
A pointer for the hash table to resize and rehash.

`size`
The new size of the hash table.

### Remove

Removes a specific `Item` from the `HashTable` using the `TKey` key.
The table must be a reference to a `HashTable` pointer, and the key must be present within the table.
After removing it will also check the load factor and resize the table if it falls below 1/8.
This is a `O(1)` operation, considering there is no collision, or the load factor is small.

```
void Remove(HashTable *table, TKey key);
```

#### Parameters

`table`
A pointer for the hash table to remove the item.

`key`
The key of the item to remove.

### Set

Adds an item to the `HashTable`, at the position specified by the hash function. If the hash code collides with an existing item, it takes the next available bucket.
If the `key` is already present in the buckets, it will update the value.
The table must be a reference to a `HashTable` pointer.
After adding, it will also check the load factor, and resize the table if it is above 1/2.
This is a `O(1)` operation, considering there is no collision, or the load factor is small.

```
void Set(HashTable *table, const TKey key, const TValue value);
```

#### Parameters

`table`
A pointer for the hash table to add the item.

`key`
The key of the new item.

`value`
The value of the new item.