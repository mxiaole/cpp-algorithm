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
