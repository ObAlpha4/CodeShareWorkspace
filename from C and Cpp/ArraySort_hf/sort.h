#include "sortdef.h"

void printArray(const char *str, int arr[], int len) {
    puts(str);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverseSort(int arr[], int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(arr, i, len - i - 1);
    }
}

void bubbleSort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

void selectSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        swap(arr, i, index);
    }
}

void insertSort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int j = i, temp = arr[i];
        while (j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

void shellSort(int arr[], int len) {
    int gap = len;
    while (gap > 1) {
        gap = gap / 3 + 1;
        for (int i = 0; i < len - gap; i++) {
            int end = i;
            int temp = arr[end + gap];
            while (end >= 0) {
                if (arr[end] > temp) {
                    arr[end + gap] = arr[end];
                    end -= gap;
                }
                arr[end + gap] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int key = left;
    int prev = left, cur = left + 1;
    while (cur <= right) {
        if (arr[cur] <= arr[key] && ++prev != cur) {
            swap(arr, cur, prev);
        }
        cur++;
    }
    swap(arr, key, prev);
    key = prev;
    quick_sort(arr, left, key - 1);
    quick_sort(arr, key + 1, right);
}

void quickSort(int arr[], int len) {
    quick_sort(arr, 0, len - 1);
}

void merge_add(int arr[], int low, int mid, int high) {
    int len = high - low + 1;
    int *temp = (int *) malloc(len * sizeof(int));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (int i = 0; i < len; i++) {
        arr[low + i] = temp[i];
    }
}

void merge_sort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge_add(arr, low, mid, high);
}

void mergeSort(int arr[], int len) {
    merge_sort(arr, 0, len - 1);
}

void heapSort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        int child = i, parent = (child - 1) / 2;
        while (child > 0 && arr[child] > arr[parent]) {
            swap(arr, child, parent);
            child = parent;
            parent = (child - 1) / 2;
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        swap(arr, 0, i);
        int parent = 0, child = 1;
        while (child < i) {
            if (child + 1 < i && arr[child] < arr[child + 1]) {
                child++;
            }
            if (arr[parent] > arr[child]) {
                swap(arr, parent, child);
                parent = child;
                child = parent * 2 + 1;
            } else {
                break;
            }
        }
    }
}

void countSort(int arr[], int len) {
    int max = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
    }
    int tlen = arr[max] + 1;
    int *count = (int *) malloc(tlen * sizeof(int));
    for (int i = 0; i < len; i++) {
        count[arr[i]]++;
    }
    for (int i = 0, j = 0; i < tlen; i++) {
        while (count[i]-- != 0) {
            arr[j++] = i;
        }
    }
    free(count);
}