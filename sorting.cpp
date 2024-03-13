#include <iostream>
#include <thread>
#include <algorithm>

// Global variables as per instructions
const int SIZE = 11;
int numbers[SIZE] = {7, 12, 19, 3, 18, 4, 2, -5, 6, 15, 8};
int sortedNumbers[SIZE];

// Function declarations
void sortHalf(int *start, int size);
void mergeArray(int mid);


using namespace std;
int main() {
    int mid = SIZE / 2;

    // threads are created here
    thread sortThread1(sortHalf, numbers, mid);
    thread sortThread2(sortHalf, numbers + mid, SIZE - mid);

    // threads are joined here
    sortThread1.join();
    sortThread2.join();

    // merge thread is created here
    thread mergeThread(mergeArray, mid);
    // merge thread is joined here
    mergeThread.join();


    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << " ";
    }

}

// Function definitions


// TODO: implement sorting algorithm
// Maybe you can come up with something better
void quickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        int partition = i + 1;
        quickSort(arr, left, partition - 1);
        quickSort(arr, partition + 1, right);
    }
}

// Sorting function for each half
void sortHalf(int *start, int size) {
    quickSort(start, 0, size - 1);
}

// TODO: implement merge algorithm 
// Maybe you can come up with something better
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