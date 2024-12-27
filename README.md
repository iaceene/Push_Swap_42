# Push Swap

## Project Overview

The **Push Swap** project is a data structure and algorithm exercise designed to help students learn about sorting algorithms, stacks, and how to efficiently manage data with limited operations. The main goal is to implement a program that sorts a list of integers using two stacks and a limited set of operations. The challenge lies in sorting the numbers with the fewest operations possible.

The project emphasizes understanding sorting algorithms, complexity analysis, and optimizing code for both performance and memory usage.

---

## Requirements

- **Operating System**: Linux or macOS (The project was designed for Unix-like environments)
- **Compiler**: GCC or Clang with the following flags:
  - `-Wall` (to show all warnings)
  - `-Wextra` (for extra warnings)
  - `-Werror` (to treat warnings as errors)
- **Libraries**: Standard C Library (`stdlib.h`, `stdio.h`)

---

## Project Description

The goal of the project is to sort a list of integers using two stacks (`a` and `b`) and a minimal number of operations. The allowed operations are:

1. **sa**: Swap the first two elements of stack `a`.
2. **sb**: Swap the first two elements of stack `b`.
3. **ss**: Perform `sa` and `sb` simultaneously.
4. **pa**: Push the top element of stack `b` onto stack `a`.
5. **pb**: Push the top element of stack `a` onto stack `b`.
6. **ra**: Rotate stack `a` (move the first element of stack `a` to the bottom).
7. **rb**: Rotate stack `b` (move the first element of stack `b` to the bottom).
8. **rr**: Perform `ra` and `rb` simultaneously.
9. **rra**: Reverse rotate stack `a` (move the last element of stack `a` to the top).
10. **rrb**: Reverse rotate stack `b` (move the last element of stack `b` to the top).
11. **rrr**: Perform `rra` and `rrb` simultaneously.

### Steps:
1. The program should read a series of integers from the command line (or from a file).
2. It must then sort them into ascending order using the fewest operations.
3. The program will output the sequence of operations that transforms the unsorted list into the sorted list.

---

## Usage

1. **Compilation**:  
   To compile the program, use the following command in your terminal:

   ```bash
   make
   ```

2. **Running the program**:  
   After compiling, you can run the program with the list of integers as arguments:

   ```bash
   ./push_swap 5 3 9 1 4 7
   ```

   The program will output the sequence of operations that sorts the integers in the fewest moves.

3. **Check the output**:  
   The program should print the sorting operations (`sa`, `pb`, `ra`, etc.) required to sort the integers. For example, if you provide the list `5 3 9 1 4 7`, the program might output:

   ```bash
   sa
   pb
   ra
   pb
   rr
   ```

---

## Implementation Details

### Data Structures
- Two stacks, `a` and `b`, are used to perform the sorting operations. 
- The list of integers is initially placed in stack `a`, and stack `b` is used to hold intermediate values during the sorting process.

### Algorithms
- The sorting algorithm should make use of the stack operations in an optimized manner. Common strategies include:
  - **Bubble Sort**-like approach with rotations and swaps.
  - **QuickSort**-inspired approach by dividing the list into smaller sections (if applicable).

### Optimization
- Aim to reduce the number of operations. A solution that uses fewer operations will be more efficient and will likely pass the 42 test checker.
- Analyze the algorithm's complexity and try to implement a more efficient solution if possible (for example, reduce operations from O(n^2) to O(n log n)).

---

## Additional Information

- The project is assessed based on code quality, efficiency (in terms of operations), and clarity.
- You should test your program with various input sizes and edge cases, such as:
  - A list with only one element.
  - A list that's already sorted.
  - A list in reverse order.
  - Duplicate numbers (if allowed).
- You can also use `checker` (another program provided in the project) to validate that your solution sorts correctly and that the operations are valid.

---

## Example

### Input:
```bash
$ ./push_swap 5 3 9 1 4 7
```

### Output:
```bash
sa
pb
ra
pb
rr
```

---

## Author

- **Name**: Yassine Ajagrou
- **1337 School**

This project is part of the 42 curriculum. The code is released under the [42 License](https://github.com/42School/lib42).
