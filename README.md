# Parallel Merge Sort

This project implements the **Merge Sort** algorithm with multithreading support, leveraging C++'s `std::thread` to perform sorting in parallel, significantly improving performance for large datasets. The program sorts an array of integers using the divide-and-conquer approach, while taking advantage of modern hardware by splitting the workload across multiple threads.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [How It Works](#how-it-works)
- [Performance](#performance)
- [Screenshot](#screenshot)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Parallel Sorting**: Utilizes multiple threads to divide and sort subarrays in parallel.
- **Efficient Merge**: Merges the sorted subarrays after recursive sorting, ensuring a stable, O(n log n) sorting time.
- **C++17**: The project uses C++17 features such as `std::thread` for multithreading.

## Installation

### Prerequisites

- C++17 compiler (GCC or Clang recommended)
- POSIX threads (`pthread` library)

### Clone the Repository

```bash
git clone https://github.com/Prashantdhaka23/parallelMergeSort.git
cd parallelMergeSort
```

### Compile the Code

To compile the code, you can use the following command:

```bash
g++ -std=c++17 main.cpp sorting/mergeSort.cpp sorting/parallelMergeSort.cpp -pthread -o main
```

### Run the Program

Once compiled, you can run the executable:

```bash
./main
```


## How It Works

1. **Divide and Conquer**: 
   - The array is recursively divided into smaller subarrays until the base case of a single-element array is reached.
   
2. **Parallel Sorting**:
   - At each recursive level, two threads are spawned to sort the two halves of the array concurrently.
   - Threads are created using `std::thread` and synchronized using `join()` to ensure both halves are sorted before merging.
   
3. **Merge**:
   - The sorted halves are merged into a single sorted array.

### Code Overview

- **main.cpp**: Entry point of the program, initializes the array, and calls the `parallelMergeSort` function.
- **mergeSort.cpp**: Contains the implementation of the sequential merge sort algorithm.
- **parallelMergeSort.cpp**: Implements the parallelized version of merge sort using threads.

## Performance

- **Sequential Merge Sort**: O(n log n) time complexity.
- **Parallel Merge Sort**: Performance improves as the workload is divided among multiple threads, reducing overall sorting time for large arrays.

### Screenshot
![Merge Sort Output](images/result.png)

## Contributing

Contributions are welcome! If you have any improvements or bug fixes, feel free to create a pull request or open an issue.

### Steps to Contribute

1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Make your changes
4. Push to your branch (`git push origin feature-branch`)
5. Create a pull request

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
