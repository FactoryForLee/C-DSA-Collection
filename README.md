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
### 🛠 Troubleshooting: Refactoring BST `Remove` and `Extract` Operations

**1. Limitations of the Original Approach**
In the textbook implementation, the `Remove` function combined both "extracting" and "deleting" responsibilities into a single function. Furthermore, because the logic heavily relied on continuously referencing the `Parent` node, it was prone to edge-case errors—especially when the target node was the `Root`.

**2. Initial Attempt (Pointer Manipulation)**
To resolve the Root node deletion issue, I initially implemented a logic using double pointers (`**Tree`) and added extensive `if` validations to check for the `Parent` node's existence. Although I managed to make it work, the resulting code became excessively complex, hard to read, and difficult to maintain.

**3. Resolution: Separation of Concerns & Recursive Structure**
To improve code quality, I completely changed the architectural approach:
*   **`Remove` Function Refactoring:** I redesigned the `Remove` function using a recursive structure that continuously updates the tree's pointers as it traverses. This completely eliminated the need for double pointers and parent node checks, making the function significantly safer and cleaner.
*   **`Extract` Function (DRY Principle):** I separated the extraction logic. Considering the sufficient hardware resources of a PC environment, I designed it to allocate and return a new isolated node (`malloc`). By reusing the refactored `Remove` function inside `Extract`, I drastically reduced the code length and maximized readability.
