﻿// HeapSort.cpp : Defines the entry point for the application.
//

#include "HeapSort.h"
#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int n) {

    int root = 0;
    int parent = root;
    // establish indexes for heap
    int leftchild = 2 * root + 1;
    int rightchild = 2 * root + 2;

    while (root < n/2) {
        if (leftchild < n) {
            parent = (leftchild - 1) / 2;

            // while the newly added child is less than its parent, keep swapping up the parents until parent is less than or you've
            // reached the top of the heap
            while (arr[leftchild] < arr[parent]) {
                swap(arr[leftchild], arr[parent]);
                leftchild = root;
                parent = (leftchild - 1) / 2;
            }
        }

        if (rightchild < n) {
            parent = (rightchild - 1) / 2;
            // while the newly added child is less than its parent, keep swapping up the parents until parent is less than or you've
            // reached the top of the heap
            while (arr[rightchild] < arr[parent]) {
                swap(arr[rightchild], arr[parent]);
                rightchild = root;
                parent = (rightchild - 1) / 2;
            }
        }

        root++;
        leftchild = 2 * root + 1;
        rightchild = 2 * root + 2;
        cout << "Heapify Iteration: " << root << endl;
        printArray(arr, n);
         cout << endl;
    }
}


// Main function to perform heap sort on the array
void heapSort(int arr[], int n) {
    // Step 1: Build a min-heap

    heapify(arr, n);


    // Step 2: Extract elements from the heap one by one
    // root of min heap is always the minimum number

    // Step 3: Down Heapify
    // THIS SECTION IS NOT YET FUNCTIONAL
    for (int i = 1; i < n; i++) {
        arr[0] = arr[n - i];
        heapify(arr, n - i);
        arr[i] = arr[0]; // sort the next element
    }
    
}

int main() {
    // Test array
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    // Call the heapSort function
    heapSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}