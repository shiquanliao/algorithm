//
// Created by 廖石泉 on 2019/11/9.
//

#ifndef ALGORITHM_SORTTESTHELPER_H
#define ALGORITHM_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>

namespace SortTestHelper {
    int *generateRandomArray(int n, int RangeL, int RangeR) {
        // generate array  range [RangeL, RangeR]
        assert(RangeL < RangeR);
        int *arr = new int[n];
        srand(time(nullptr));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (RangeR - RangeL + 1) + RangeL;
        }
        return arr;
    }

    int *generateNearlyOrderArray(int n, int swapTime) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = i;

        for (int j = 0; j < swapTime; ++j) {
            int posX = rand() % n;
            int posY = rand() % n;
            swap(arr[posX], arr[posY]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T>
    bool isSort(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    template<typename T>
    void testSort(const string &sortName, void(*sort)(T arr[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSort(arr, n));
        cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

}

#endif //ALGORITHM_SORTTESTHELPER_H
