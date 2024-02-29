#ifndef C_AND_CPP_ARRSORT_H
#define C_AND_CPP_ARRSORT_H
#endif //C_AND_CPP_ARRSORT_H

#include <iostream>

template<typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void mergeSort(T arr[], long long low, long long high) {
    if (low >= high)
        return;
    long long mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    long long tlen = high - low + 1;
    long long *temp = (long long *) calloc(tlen, sizeof(long long));
    long long i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (i = 0; i < tlen; i++)
        arr[low + i] = temp[i];
    free(temp);
}
