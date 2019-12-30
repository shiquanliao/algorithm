//
// Created by 廖石泉 on 2019/11/10.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H


template<typename T>
void selectSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}



// 对arr[l...r]进行排序
template<typename T>
void __merge(T *arr, int l, int mid, int r) {
    T aux[r - l + 1];
    for (int i = l; i <= r; i++) {
        aux[i - l] = arr[i];
    }

    int i = l;
    int j = mid + 1;
//    cout << "mid is " << mid << "  j is " << j << endl;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }

}

// 递归使用归并排序，对arr[l...r]进行排序
template<typename T>
void __mergeSort(T *arr, int l, int r) {
    // 1.基准线
    if (l >= r) return;

    int middle = (l + r) / 2;
    // 递归
    __mergeSort(arr, l, middle);
    __mergeSort(arr, middle + 1, r);

    if (arr[middle] > arr[middle + 1])
        //子空间的排序
        __merge(arr, l, middle, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}


#endif //ALGORITHM_SORT_H
