#include "alg.h"
#include <iostream>

//  SEARCH  //

int linear_search(int* arr, int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int binary_search(int* arr, int n, int num) {
    int left = 0;
    int right = n - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == num) {
            return mid;
        }
        if (arr[mid] > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
//  SORT   //

void selection_sort(int* arr, int n) {
    int min_index = 0;
    for (int i = 0; i < n-1; i++) {
        min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

void quick_sort(int* arr, int n) {
    if (n < 2) {
        return;
    }
    int left = 0;
    int right = n - 1;
    int pivot = arr[n/2];
    while (left < right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot && left < right) {
            right--;
        }
        if (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    quick_sort(arr, left);
    quick_sort(&arr[left], n-left);
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertion_sort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j > -1; j--) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void merge_sort(int* arr, int left, int right) {
    int mid = (left + right) / 2;
    if (left < right) {
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

void merge(int* arr, int left, int right) {
    int* temp = new int[left + right + 1];
    int mid = (left + right) / 2;
    int start = left; 
    int final = mid + 1;
    for (int i = left; i <= right; i++) {
        if ((start <= mid) && ((final > right) || (arr[start] < arr[final]))) {
            temp[i] = arr[start];
            start++;
        } else {
            temp[i] = arr[final];
            final++;
        }
    }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
}; 