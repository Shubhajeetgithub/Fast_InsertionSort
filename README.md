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
git clone https://github.com/Shubhajeetgithub/Fast_InsertionSort.git
cd Fast_InsertionSort
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

## Using the Package in Other Projects

There are two ways to use this package in your other projects:

### 1. Install from GitHub

```bash
# Create and activate a virtual environment in your project directory
python -m venv .venv
source .venv/bin/activate  # On Windows use: .venv\Scripts\activate

# Install the package directly from GitHub
pip install git+https://github.com/Shubhajeetgithub/Fast_InsertionSort.git
```

### 2. Install in Development Mode

If you want to modify the package while using it:

```bash
# Create and activate a virtual environment in your project directory
python -m venv .venv
source .venv/bin/activate  # On Windows use: .venv\Scripts\activate

# Install in development mode using the path to your clone of the repository
pip install -e /path/to/Fast_InsertionSort
```

Then you can use it in your code:

```python
import numpy as np
from fastsort import FastInsertionSort

# Create a random array
arr = np.random.randint(0, 1000, 1000).tolist()

# Initialize sorter
sorter = FastInsertionSort(arr)

# Use any sorting method
sorted_arr, time_taken = sorter.binarySearchPairing_insertionSort()
```

### Example Benchmark Script

Here's a complete example that benchmarks all sorting algorithms:

```python
import numpy as np
from fastsort import FastInsertionSort
import time

def benchmark_sorts(size=1000):
    # Generate random data
    arr = np.random.randint(0, 1000, size).tolist()
    sorter = FastInsertionSort(arr)
    
    # Test all algorithms
    algorithms = [
        ('Basic', sorter.basic_insertionSort),
        ('Binary Search', sorter.binarySearch_insertionSort),
        ('Binary Search Pairing', sorter.binarySearchPairing_insertionSort),
        ('Pairing', sorter.pairing_insertionSort)
    ]
    
    for name, algorithm in algorithms:
        sorted_arr, sort_time = algorithm()
        print(f"{name} Sort Time: {sort_time:.6f} seconds")

if __name__ == "__main__":
    print("Benchmarking with array size 10000:")
    benchmark_sorts(10000)
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.