#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <chrono>
#include <utility>

namespace py = pybind11;
using namespace std::chrono;

class FastInsertionSort {
private:
    std::vector<int> A;

public:
    FastInsertionSort(const std::vector<int>& arr) : A(arr) {}

    std::pair<std::vector<int>, double> basic_insertionSort() {
        std::vector<int> B = A;
        auto start = high_resolution_clock::now();
        
        for (size_t i = 0; i < B.size(); i++) {
            size_t j = i;
            while (j > 0 && B[j-1] > B[j]) {
                std::swap(B[j-1], B[j]);
                j--;
            }
        }
        
        auto end = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end - start);
        return {B, time_span.count()};
    }

    std::pair<std::vector<int>, double> binarySearch_insertionSort() {
        std::vector<int> B = A;
        auto start = high_resolution_clock::now();
        
        for (size_t i = 1; i < B.size(); i++) {
            int s = 0, e = i - 1;
            int id = -1;
            while (s <= e) {
                int m = s + ((e - s) >> 1);
                if (B[m] <= B[i]) {
                    id = m;
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
            
            if (id != static_cast<int>(i) - 1) {
                int temp = B[i];
                for (int j = i; j > id + 1; j--) {
                    B[j] = B[j - 1];
                }
                B[id + 1] = temp;
            }
        }
        
        auto end = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end - start);
        return {B, time_span.count()};
    }

    std::pair<std::vector<int>, double> binarySearchPairing_insertionSort() {
        std::vector<int> B = A;
        auto start = high_resolution_clock::now();
        size_t n = B.size();
        
        if (n >= 2 && B[0] > B[1]) {
            std::swap(B[0], B[1]);
        }

        for (size_t i = 2; i < n; i += 2) {
            if (i + 1 < n) {
                if (B[i] > B[i + 1]) {
                    std::swap(B[i], B[i + 1]);
                }

                int min_val = B[i];
                int max_val = B[i + 1];
                int s = 0, e = i - 1;
                int id = -1;

                while (s <= e) {
                    int m = s + ((e - s) >> 1);
                    if (B[m] <= min_val) {
                        id = m;
                        s = m + 1;
                    } else {
                        e = m - 1;
                    }
                }

                if (id != static_cast<int>(i) - 1) {
                    int temp = B[i];
                    for (int j = i; j > id + 1; j--) {
                        B[j] = B[j - 1];
                    }
                    B[id + 1] = temp;
                }

                s = id + 1;
                e = i;
                id = -1;

                while (s <= e) {
                    int m = s + ((e - s) >> 1);
                    if (B[m] <= max_val) {
                        id = m;
                        s = m + 1;
                    } else {
                        e = m - 1;
                    }
                }

                if (id != static_cast<int>(i)) {
                    int temp = B[i + 1];
                    for (int j = i + 1; j > id + 1; j--) {
                        B[j] = B[j - 1];
                    }
                    B[id + 1] = temp;
                }
            } else {
                int val = B[i];
                int j = i;
                while (j > 0 && B[j - 1] > val) {
                    B[j] = B[j - 1];
                    j--;
                }
                B[j] = val;
            }
        }
        
        auto end = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end - start);
        return {B, time_span.count()};
    }

    std::pair<std::vector<int>, double> pairing_insertionSort() {
        std::vector<int> B = A;
        auto start = high_resolution_clock::now();
        size_t n = B.size();

        if (n >= 2) {
            if (B[0] > B[1]) {
                std::swap(B[0], B[1]);
            }
            
            for (size_t i = 2; i < n; i += 2) {
                int maxNum = B[i];
                int minNum = B[i];
                
                if (i + 1 < n) {
                    maxNum = std::max(B[i], B[i + 1]);
                    minNum = std::min(B[i], B[i + 1]);
                    
                    int j = i - 1;
                    int k = i + 1;
                    while (j >= 0 && B[j] > maxNum) {
                        B[k] = B[j];
                        k--;
                        j--;
                    }
                    B[j + 2] = maxNum;
                    B[j + 1] = minNum;

                    int l = j + 1;
                    while (l > 0 && B[l - 1] > B[l]) {
                        std::swap(B[l - 1], B[l]);
                        l--;
                    }
                } else {
                    int j = i;
                    while (j > 0 && B[j - 1] > B[j]) {
                        std::swap(B[j - 1], B[j]);
                        j--;
                    }
                }
            }
        }
        
        auto end = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end - start);
        return {B, time_span.count()};
    }
};

PYBIND11_MODULE(fastsort, m) {
    py::class_<FastInsertionSort>(m, "FastInsertionSort")
        .def(py::init<const std::vector<int>&>())
        .def("basic_insertionSort", &FastInsertionSort::basic_insertionSort)
        .def("binarySearch_insertionSort", &FastInsertionSort::binarySearch_insertionSort)
        .def("binarySearchPairing_insertionSort", &FastInsertionSort::binarySearchPairing_insertionSort)
        .def("pairing_insertionSort", &FastInsertionSort::pairing_insertionSort);
}
