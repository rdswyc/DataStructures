# Data Structures in C/C++

Hello there! Here you will find some common data structures and samples. Everything is built up as simple single file, console apps for simplicity. The main focus of this project is to share data structures, pointers, operations and asymptotic behavior of each solution.

## What are the structures included?

* **Array**
A collection of similar data items that can be accessed by index.

* **Queue**
A First-In-First-Out list, where the first item to be added will be the first one removed.
It is implemented using pointers. 

* **Stack**
Last-In-First-Out list, where the last item to be added will be the fist one removed.
It is implemented using pointers.

* **Linked list**
List opened in both ends, allowing insertions and removals at any element, as well as searching.
There are two internal implementations, one with a simple link to the next element, and another one with a double link between the next and the previous elements.

* **Binary tree**
A balanced binary search tree, with node count, leaves and non-leaves count, height and paths information.
It has two search functions, one by key and another one by value.
Additionally, it implements a cool pretty print method.

* **Graph**
Finite graph with two implementations: one using the adjacent matrix and another one using a linked list.

* **Hashtable**
An associative array that maps keys to values for fast look-up.

## Standard operations

For every structure, you will find the standard operations bellow, as well as specific methods depending on the type.

- Initialization
- Count of elements
- Add
- Remove
- Print

## Algorithmic complexity comparison

Comparison table of some common operations in the worst case scenario using the big-O notation.

| Structure | Operation | Complexity |
| ----------- | ----------- | ----------- |
| Array | IndexOf | O(n) |
| Array | LastIndexOf | O(n) |
| Array | SetValue | O(1) |
| Array | Sort | O(n^2) |
| Binary search tree | Add | O(log n) |
| Binary search tree | Count | O(n) |
| Binary search tree | Find | O(log n) |
| Binary search tree | Remove | O(log n) |
| Linked list | Add | O(1) |
| Linked list | Count | O(n) |
| Linked list | Find | O(n) |
| Linked list | Remove | O(1) |
| Queue | Count | O(1) |
| Queue | Contains | O(n) |
| Queue | Dequeue | O(1) |
| Queue | Enqueue | O(1) |
| Stack | Count | O(1) |
| Stack | Contains | O(n) |
| Stack | Pop | O(1) |
| Stack | Push | O(1) |
