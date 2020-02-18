//
// Created by cody on 2020-02-12.
//
# include "search.h"

int binarySearch(int *arr, int n, int target) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (target == arr[mid]) {
            return mid;
        }
        if (arr[mid] > target) {
            end = mid - 1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        }
    }

    return -1;
}