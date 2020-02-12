//
// Created by cody on 2020-02-11.
//

#include "sort.h"

void bubbleSort(int *arr, int n) {

}

void selectionSort(int *arr, int n) {
    // 选择排序
    for (int i = 0; i < n; i++) {
        int maxIndex = i;
        // 在[i, n)的区间中寻找最大值
        for (int j = i + 1; j < n; j++) {
            if (arr[maxIndex] < arr[j]) {
                maxIndex = j;
            }
        }
        // 将i位置的元素和最大值进行交换
        std::swap(arr[i], arr[maxIndex]);
    }
}

void insertSort1(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        // 寻找元素arr[i]合适的插入位置
        for (int j = i; j > 0; j--) {
            if (arr[j] > arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

void insertSort2(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int e = arr[i];
        int j;  // 元素e应该插入的位置
        for (j = i; j > 0 && arr[j - 1] < e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}


// 归并排序辅助函数，合并两个有序数组[l, mid], [mid+1, r]
void __merge(int arr[], int l, int mid, int r) {
    int aux[r - l + 1];
    for (int i = l; i <= r; i++)
        aux[i - l] = arr[i];

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {

        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] > aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
void __mergeSort(int arr[], int l, int r) {

    if (l >= r)
        return;

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

void mergeSort(int arr[], int n) {

    __mergeSort(arr, 0, n - 1);
}

