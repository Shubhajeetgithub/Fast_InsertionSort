# FastSort: High-Performance Insertion Sort Variations

This package implements four different variations of insertion sort in C++ with Python bindings:

1. **Basic Insertion Sort**: The classic implementation of insertion sort
2. **Binary Search Insertion Sort**: Uses binary search to find the insertion position
3. **Binary Search Pairing Sort**: Combines binary search with pair-wise comparisons
4. **Pairing Sort**: A variation that processes elements in pairs

## Installation

Requirements:
- Python 3.7 or higher
- C++ compiler with C++11 support
- pybind11
- numpy

```bash
# Create and activate a virtual environment (recommended)
python -m venv .venv
source .venv/bin/activate  # On Windows use: .venv\Scripts\activate

# Install dependencies
pip install numpy pybind11

# Install the package
pip install .
```

## Usage

```python
import numpy as np
from fastsort import FastInsertionSort

# Create a random array to sort
arr = np.random.randint(0, 1000, 1000).tolist()

# Initialize the sorter
sorter = FastInsertionSort(arr)

# Use any of the sorting methods
sorted_arr, time_taken = sorter.basic_insertionSort()
sorted_arr, time_taken = sorter.binarySearch_insertionSort()
sorted_arr, time_taken = sorter.binarySearchPairing_insertionSort()
sorted_arr, time_taken = sorter.pairing_insertionSort()
```

Each sorting method returns a tuple containing:
- The sorted array
- The time taken to sort (in seconds)

## Algorithm Details

### Basic Insertion Sort
- Traditional insertion sort implementation
- Time Complexity: O(n²)
- Space Complexity: O(1)

### Binary Search Insertion Sort
- Uses binary search to find the insertion position
- Reduces comparisons but not swaps
- Time Complexity: O(n log n) for comparisons, O(n²) for swaps
- Space Complexity: O(1)

### Binary Search Pairing Sort
- Processes elements in pairs
- Uses binary search for both elements of the pair
- Time Complexity: O(n log n) for comparisons, O(n²) for swaps
- Space Complexity: O(1)

### Pairing Sort
- Processes elements in pairs
- Optimizes insertions by handling two elements at once
- Time Complexity: O(n²)
- Space Complexity: O(1)

## Performance

The performance of each algorithm varies depending on:
- Input size
- Initial order of elements
- Hardware characteristics

Generally:
- Binary search variants perform fewer comparisons
- Pairing variants can be faster on modern hardware due to better cache utilization
- For large arrays, binary search variants typically provide better performance

## License

This project is licensed under the MIT License - see the LICENSE file for details.
```bash
git clone https://github.com/Shubhajeetgithub/fastsort.git
cd fastsort
pip install .
```

## Usage
```py
import fastsort

arr = [5, 2, 4, 6, 1, 3]
sorted_arr = fastsort.basic_insertion_sort(arr)
print(sorted_arr)

# Other available functions:
# fastsort.binary_search_insertion_sort(arr)
# fastsort.binary_search_pairing_insertion_sort(arr)
# fastsort.pairing_insertion_sort(arr)
```