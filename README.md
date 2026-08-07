# 🧱 Data Structures in C

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Blog](https://img.shields.io/badge/Tech_Blog-Tistory-orange.svg)](https://codetobrain.tistory.com/)

## 📌 Executive Summary
This repository contains the core data structures implemented from scratch in **C**. 
The main focus of this project is to deeply understand **memory allocation (`malloc`/`free`)**, **pointer manipulation**, and the fundamental logic behind ADT (Abstract Data Types) without relying on standard libraries.

## 🚀 Implemented Structures

| Data Structure | Implementation Type | Time Complexity:Worst Case (Search/Insert/Delete) | Note |
| :--- | :--- | :--- | :--- |
| **Queue** | Circular Array | `O(N)` / `O(1)` / `O(1)` | Solved shifting overhead using Modulo arithmetic (FIFO) |
| **Queue** | Linked List | `O(N)` / `O(1)` / `O(1)` | Dynamic memory sizing (FIFO) |
| **Stack** | Linked List | `O(N)` / `O(1)` / `O(1)` | LIFO architecture |
| **Tree** | LCRS (Left-Child Right-Sibling) | `O(N)` | Efficiently handles multi-way trees |

## 🛠️ Key Point & Insights

*   **Circular Queue Array Overflow:** Prevented index out-of-bounds by calculating `(Rear + 1) % Capacity` to seamlessly wrap around the array. Defined 'Full' state as `Front == (Rear + 1) % Capacity` to distinguish it from the 'Empty' state.
*   **Memory Leaks in Linked Structures:** Ensured that every `DestroyTree()` and `DestroyStack()` function traverses all remaining nodes to strictly `free()` allocated memory before destroying the root/head structure.

## 💻 Troubleshooting
