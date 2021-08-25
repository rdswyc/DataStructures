#include <stdbool.h>

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#pragma region Structure

#define MAX_LOAD_FACTOR 0.5

typedef char *TKey;
typedef char *TValue;

typedef struct
{
  TKey key;
  TValue value;
} Item;

typedef struct
{
  Item *buckets;
  int numberBuckets;
  int itemsCount;
} HashTable;

#pragma endregion

#pragma region Method headers

int Buckets(HashTable table);
int Count(HashTable table);
float LoadFactor(HashTable table);

void AutoFill(HashTable *table);
void Clear(HashTable *table);
bool ContainsKey(HashTable table, const TKey key);
bool ContainsValue(HashTable table, const TValue value);
Item *FindValue(HashTable table, const TValue value);
Item *Get(HashTable table, const TKey key);
unsigned HashFunction(const TKey key, int bucketSize);
HashTable Initialize(int capacity = 0);
void Print(HashTable table);
void PrintBucket(Item item, int index = -1);
void Rehash(HashTable *table, int size);
void Remove(HashTable *table, TKey key);
void Set(HashTable *table, const TKey key, const TValue value);

#pragma endregion

#endif