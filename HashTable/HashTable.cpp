#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <math.h>

#include "HashTable.h"

const unsigned primes[] = {5, 53, 97, 193, 389,
                           769, 1543, 3079, 6151, 12289,
                           24593, 49157, 98317, 196613, 393241,
                           786433, 1572869, 3145739, 6291469, 12582917,
                           25165843, 50331653, 100663319, 201326611, 402653189,
                           805306457, 1610612741, 3221225473, 4294967291};

#pragma region Properties

int Buckets(HashTable table)
{
  return table.numberBuckets;
}

int Count(HashTable table)
{
  return table.itemsCount;
}

float Loadfactor(HashTable table)
{
  return (float)table.itemsCount / (float)table.numberBuckets;
}

#pragma endregion

#pragma region Methods

char *AutoFill_RandString()
{
  int length = 7;
  char *text = (char *)malloc(length);

  for (int i = 0; i < length; i++)
    sprintf(text + i, "%x", rand() % 16);

  return text;
}

void AutoFill(HashTable *table)
{
  int size = floor(table->numberBuckets * MAX_LOAD_FACTOR);

  for (int i = 0; i < size; i++)
  {
    TKey key = AutoFill_RandString();
    TValue value = AutoFill_RandString();

    Set(table, key, value);
  }
}

void Clear(HashTable *table)
{
  free(table->buckets);

  HashTable emptyTable = Initialize();
  table->buckets = emptyTable.buckets;
  table->itemsCount = emptyTable.itemsCount;
  table->numberBuckets = emptyTable.numberBuckets;
}

bool Equals(TKey item1, TKey item2)
{
  return strcmp(item1, item2) == 0;
}

bool ContainsKey(HashTable table, const TKey key)
{
  unsigned hashCode = HashFunction(key, table.numberBuckets);

  for (unsigned i = hashCode; table.buckets[i].key != NULL; i = (i + 1) % table.numberBuckets)
  {
    if (Equals(table.buckets[i].key, key))
      return true;
  }

  return false;
}

bool ContainsValue(HashTable table, const TValue value)
{
  for (unsigned i = 0; i < table.numberBuckets; i++)
  {
    if (table.buckets[i].key != NULL && Equals(table.buckets[i].value, value))
      return true;
  }

  return false;
}

Item *FindValue(HashTable table, const TValue value)
{
  for (unsigned i = 0; i < table.numberBuckets; i++)
  {
    if (table.buckets[i].key != NULL && Equals(table.buckets[i].value, value))
      return &table.buckets[i];
  }

  return NULL;
}

Item *Get(HashTable table, const TKey key)
{
  unsigned hashCode = HashFunction(key, table.numberBuckets);

  for (unsigned i = hashCode; table.buckets[i].key != NULL; i = (i + 1) % table.numberBuckets)
  {
    if (Equals(table.buckets[i].key, key))
      return &table.buckets[i];
  }

  return NULL;
}

unsigned GetPrime(int reference)
{
  int left = 0;
  int right = 28;

  while (left <= right)
  {
    int middle = floor((left + right) / 2);

    if (primes[middle] < reference)
      left = middle + 1;
    else if (primes[middle] > reference)
      right = middle - 1;
    else
      return primes[middle];
  }

  return primes[left];
}

unsigned HashFunction(const TKey key, int buckets)
{
  unsigned hash = 0;

  for (int i = 0; i < strlen(key); i++)
    hash = (31 * hash + key[i]) % buckets;

  return hash;
}

HashTable Initialize(int capacity)
{
  int actualCapacity = GetPrime(capacity);

  HashTable table;
  table.buckets = (Item *)malloc(actualCapacity * sizeof(Item));
  table.numberBuckets = actualCapacity;
  table.itemsCount = 0;

  for (int i = 0; i < actualCapacity; i++)
  {
    table.buckets[i].key = NULL;
    table.buckets[i].value = NULL;
  }

  return table;
}

void Print(HashTable table)
{
  if (table.buckets != NULL)
  {
    for (int i = 0; i < table.numberBuckets; i++)
    {
      if (table.buckets[i].key != NULL)
        PrintBucket(table.buckets[i], i);
    }
  }
}

void PrintBucket(Item item, int index)
{
  if (index == -1)
    printf("* %s %s\n", item.key, item.value);
  else
    printf("[%i] -> %s %s\n", index, item.key, item.value);
}

void Rehash(HashTable *table, int size)
{
  HashTable newTable = Initialize(size);

  for (int i = 0; i < table->numberBuckets; i++)
  {
    if (table->buckets[i].key != NULL)
      Set(&newTable, table->buckets[i].key, table->buckets[i].value);
  }

  table->buckets = newTable.buckets;
  table->numberBuckets = newTable.numberBuckets;
}

void Remove(HashTable *table, TKey key)
{
  unsigned hashCode = HashFunction(key, table->numberBuckets);

  for (unsigned i = hashCode; table->buckets[i].key != NULL; i = (i + 1) % table->numberBuckets)
  {
    if (Equals(table->buckets[i].key, key))
    {
      table->itemsCount--;
      table->buckets[i].key = NULL;
      table->buckets[i].value = NULL;
      break;
    }
  }

  if (Loadfactor(*table) < MAX_LOAD_FACTOR / 4)
    Rehash(table, table->itemsCount);
}

void Set(HashTable *table, const TKey key, const TValue value)
{
  unsigned hashCode = HashFunction(key, table->numberBuckets);

  unsigned i;
  for (i = hashCode; table->buckets[i].key != NULL; i = (i + 1) % table->numberBuckets)
  {
    if (Equals(table->buckets[i].key, key))
    {
      strcpy(table->buckets[i].value, value);
      return;
    }
  }

  table->itemsCount++;

  table->buckets[i].key = (TKey)malloc(strlen(key));
  strcpy(table->buckets[i].key, key);

  table->buckets[i].value = (TValue)malloc(strlen(value));
  strcpy(table->buckets[i].value, value);

  if (Loadfactor(*table) > MAX_LOAD_FACTOR)
    Rehash(table, 1 + table->numberBuckets);
}

#pragma endregion