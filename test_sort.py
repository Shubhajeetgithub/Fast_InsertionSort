import numpy as np
from fastsort import FastInsertionSort

# Create a random array
arr = np.random.randint(0, 1000, 10000).tolist()
print("Original array (first 10 elements):", arr[:10])

# Create sorter instance
sorter = FastInsertionSort(arr)

# Test each sorting method
sorted_arr, time_basic = sorter.basic_insertionSort()
print("\nBasic Insertion Sort (first 10 elements):", sorted_arr[:10])
print("Time taken:", time_basic, "seconds")

sorted_arr, time_binary = sorter.binarySearch_insertionSort()
print("\nBinary Search Insertion Sort (first 10 elements):", sorted_arr[:10])
print("Time taken:", time_binary, "seconds")

sorted_arr, time_binary_pair = sorter.binarySearchPairing_insertionSort()
print("\nBinary Search Pairing Sort (first 10 elements):", sorted_arr[:10])
print("Time taken:", time_binary_pair, "seconds")

sorted_arr, time_pair = sorter.pairing_insertionSort()
print("\nPairing Sort (first 10 elements):", sorted_arr[:10])
print("Time taken:", time_pair, "seconds")
