#include <iostream>
using namespace std;

void MAXheapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i) {
        swap(arr[i], arr[largest]);
        MAXheapify(arr, n, largest);
    }
}


void MINheapify(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[left] < arr[largest])
        largest = left;

    if (right < n && arr[right] < arr[largest])
        largest = right;

   
    if (largest != i) {
        swap(arr[i], arr[largest]);
        MINheapify(arr, n, largest);
    }
}


void heapSortMAX(int arr[], int n) {

    for (int i = n / 2; i >= 1; i--)
        MAXheapify(arr, n, i);


    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);

        cout << "Max Heap: ";
        cout << arr[i] << endl;

  
        MAXheapify(arr, i, 0);
    }
}
void heapSortMIN(int arr[], int n) {

    for (int i = n / 2; i >= 1; i--)
        MINheapify(arr, n, i);


    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);

        cout << "Max Heap: ";
        cout << arr[i] << endl;


        MINheapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


int main() {
    int arr[] = { 1, 12, 9, 5, 6, 10, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "MAX HEAP:" << endl;
    heapSortMAX(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
    
    cout << endl;

    cout << "MIN HEAP:" << endl;
    heapSortMIN(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}
