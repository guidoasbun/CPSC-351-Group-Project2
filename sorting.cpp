// Programming Assignment #2, Threads
// Class: CPSC 351-09 22045
// Group: 1
// Members:
//      - Alex Le
//      - Conner Robbins
//      - Harry Derderian
//      - Guido Asbun
// GitHub:
//      - https://github.com/guidoasbun/CPSC-351-Group-Project2

#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

// Global variables as per instructions
const int SIZE {11};
int numbers[SIZE] {7, 12, 19, 3, 18, 4, 2, -5, 6, 15, 8};
int sortedNumbers[SIZE];

// Function declarations
int partition(int *arr, int left, int right);
void quickSort(int *arr, int left, int right);
void sortHalf(int *start, int size);
void mergeArray(int mid);
void printArray(int *arr, int size);

int main() 
{
    int mid {SIZE / 2};

    // threads are created and ran here
    thread sortThread1(sortHalf, numbers, mid);
    thread sortThread2(sortHalf, numbers + mid, SIZE - mid);
    // threads are joined here
    sortThread1.join();
    sortThread2.join();

    // merge thread is created and ran here
    thread mergeThread(mergeArray, mid);
    // merge thread is joined here
    mergeThread.join();

    // Print the sorted array
    printArray(sortedNumbers, SIZE);
}

// Function to partition an array using a pivot
// All values less than the pivot are on the left, and all values greater are on the right
int partition(int *arr, int left, int right) 
{
    // Select the pivot (the rightmost element)
    int pivot = arr[right]; 
    // Initialize pointers
    int lesserValues = left - 1;
    int greaterValues = left;
    // Iterate through the array
    for(; greaterValues < right; greaterValues++)
    {
        // If the current value is less than the pivot, move it to the back of lesser values
        if(arr[greaterValues] < pivot)
        {
            // Move the smaller pointer to the back of lesser values
            lesserValues++;
            // move the lesser value to left, greater value to the right
            swap(arr[greaterValues], arr[lesserValues]);
        }
    }
    // Move the pivot to its sorted position (between lesser and greater values)
    lesserValues++;
    swap(arr[lesserValues], arr[right]);
    // Return the index of the pivot
    return lesserValues;
}

// Function to sort an array using the quicksort algorithm
void quickSort(int *arr, int left, int right) 
{
    if (left >= right) return; // Base case

    int sortedIndex = partition(arr, left, right);
    quickSort(arr, left, sortedIndex - 1);
    quickSort(arr, sortedIndex + 1, right);
}

// Sorting function for each half
void sortHalf(int *start, int size) {
    quickSort(start, 0, size - 1);
}

// Function to merge two sorted arrays
void mergeArray(int mid) {
    int i = 0, j = mid, k = 0;
    while (i < mid && j < SIZE) {
        if (numbers[i] < numbers[j]) {
            sortedNumbers[k++] = numbers[i++];
        } else {
            sortedNumbers[k++] = numbers[j++];
        }
    }
    while (i < mid) {
        sortedNumbers[k++] = numbers[i++];
    }
    while (j < SIZE) {
        sortedNumbers[k++] = numbers[j++];
    }
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = sortedNumbers[i];
    }
}

// Function to print the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
