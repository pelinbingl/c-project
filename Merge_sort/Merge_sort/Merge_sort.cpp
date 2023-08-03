#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int* left_arr = new int[left_size];
    int* right_arr = new int[right_size];

    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }

    for (int j = 0; j < right_size; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter the elements: "<< endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i] ;
        cout << " ";
    }
    cout << "Array:";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}

