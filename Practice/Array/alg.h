#ifndef ALG_H
#define ALG_H

//  SEARCH  //
int linear_serach(int* arr, int n, int num);
int binary_search(int* arr, int n, int num);
//  SORT   //
void selection_sort(int* arr, int n);
void quick_sort(int* arr, int n);
void bubble_sort(int* arr, int n);
void insertion_sort(int* arr, int n);
void merge_sort(int* arr, int left, int right);
void merge(int* arr, int left, int right);

#endif // ALG_H