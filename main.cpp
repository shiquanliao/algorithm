#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
#include "Sort.h"

using namespace std;

template<typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n + 1; ++i)
        for (int j = i; j > 0 && (arr[j] < arr[j - 1]); j--)
            swap(arr[j], arr[j - 1]);
}

template<typename T>
void insertSort1(T arr[], int n) {
    for (int i = 1; i < n + 1; i++) {
        T temp = arr[i];
        int j;
        for (j = i; j > 0 && (arr[j - 1] > temp); j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}


int main() {
    int n = 50000;
//    int *array = SortTestHelper::generateRandomArray(n, 0, n);
    int *array = SortTestHelper::generateNearlyOrderArray(n, 1);
    int *array1 = SortTestHelper::copyIntArray(array, n);
    int *array2 = SortTestHelper::copyIntArray(array, n);
    int *array3 = SortTestHelper::copyIntArray(array, n);

    SortTestHelper::testSort("Select Sort", selectSort, array, n);
    SortTestHelper::testSort("Insert Sort", insertSort, array1, n);
    SortTestHelper::testSort("Insert Sort1", insertSort1, array2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, array3, n);

    delete[] array;
    delete[] array1;
    delete[] array2;
    delete[] array3;
    return 0;
}

/**
 *   int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selectSort(arr, 11);
    for (int i = 0; i < 11; ++i)
        cout << arr[i] << " ";
    cout << endl;

    float arr2[] = {4.4, 3.3, 2.2, 1.1};
    selectSort(arr2, 4);
    for (int j = 0; j < 4; ++j)
        cout << arr2[j] << " ";
    cout << endl;

    string c[4] = {"D", "C", "A", "B"};
    selectSort(c, 4);
    for (int k = 0; k < 4; k++)
        cout << c[k] << " ";
    cout << endl;

    Student student[] = {{"D", 90},
                         {"C", 100},
                         {"B", 95},
                         {"A", 95}};
    selectSort(student, 4);
    for (int l = 0; l < 4; ++l)
        cout << student[l];
    cout << endl;
*/