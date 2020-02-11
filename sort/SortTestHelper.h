//
// Created by cody on 2020-02-11.
//

#ifndef ALGORITHM_SORTTESTHELPER_H
#define ALGORITHM_SORTTESTHELPER_H

#include <iostream>

using namespace std;

namespace SortTestHelper {
    // 生成一个随机的数组, 值在指定的区间中
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    // 打印数组元素
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << "\t";
        }
        std::cout << std::endl;
    }

    // 判断一个数组是否有序
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }

        return true;
    }

    // 计算一个排序算法的时间
    template<typename T>
    void testSort(string sortName, void (*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
    }

    // 拷贝数组
    int *copyIntArray(int *arr, int n) {
        int *retArray = new int[n];
        copy(arr, arr + n, retArray);

        return retArray;
    }

}

#endif //ALGORITHM_SORTTESTHELPER_H
