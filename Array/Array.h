#include <stdbool.h>

#ifndef ARRAY_H
#define ARRAY_H

#pragma region Structure

typedef char *T;

#pragma endregion

#pragma region Method headers

void Autofill(T array[], int size);
void Clear(T array[], int size);
int IndexOf(T array[], int size, T item);
int LastIndexOf(T array[], int size, T item);
void Print(T array[], int size);
void PrintItem(T item);
void Reverse(T array[], int size);
void SetValue(T array[], int index, T value);
void Sort(T array[], int size);
void SwapItems(T item1, T item2);

#pragma endregion

#endif