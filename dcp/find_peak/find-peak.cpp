// This problem was asked by Sumo Logic.

// Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

// An element is considered a peak if it is greater than both its left and right neighbors. It is guaranteed that the first and last elements are lower than all others.

#include <iostream>

using namespace std;

#define SIZE 6

// Find pivot position of array.
int pivot(int arr_size) {
    return arr_size / 2;
}

int find_peak(int arr[SIZE], int pivot_idx) {
    // If we've reached the left edge of array - start checking right of pivot.
    if (pivot_idx <= 0) {
        return find_peak(arr, pivot(SIZE)+1);
    }

    // Base case
    if (pivot_idx >= SIZE) {
        return -1;
    }

    // If element at pivot is peak, return index
    if (arr[pivot_idx] > arr[pivot_idx-1] && arr[pivot_idx] > arr[pivot_idx + 1]) {
        return pivot_idx;
    }

    // Recursive calls
    if (pivot_idx > SIZE / 2) {
        return find_peak(arr, pivot_idx+1);
    } else {
        return find_peak(arr, pivot_idx-1);
    }    
}

int main() {
    int arr[SIZE] = {1, 5, 4, 2, 2, 1};

    int peak_element = find_peak(arr, pivot(SIZE));

    cout << "index of peak: " << peak_element << endl;

    if (peak_element == -1) {
        cout << "No peak found in arr." << endl;
    } else {
        cout << "Peak value in arr is: " << arr[peak_element] << endl;
    }

}