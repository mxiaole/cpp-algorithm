//
// Created by cody on 2020-02-11.
//

#include "sort/sort.h"
#include "sort/SortTestHelper.h"
#include "Student.h"


int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);

    // 选择排序
    SortTestHelper::testSort("选择排序", selectionSort, arr, n);
    // 插入排序
    SortTestHelper::testSort("插入排序", insertSort2, arr2, n);
    // 归并排序
    SortTestHelper::testSort("归并排序", mergeSort, arr3, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    return 0;
}