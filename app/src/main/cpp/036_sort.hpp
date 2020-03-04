//
// Created by 李陈 on 2020-01-02.
//

#ifndef NDK_ALGORITHM_036_SORT_HPP
#define NDK_ALGORITHM_036_SORT_HPP

#include "test_log.hpp"

using namespace std;

//冒泡排序优化，记录最后一次交换位置
//能够提前终止循环
static void bubbleSort1(int arr[], int len) {

    //记录最后一次交换位置
    int n = len;
    int newn = 0;

    do {
        newn = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);  //一次交换3次赋值
                newn = i;
            }
        }

        n = newn;
    } while (n > 0);


}

//因为开发过程中很少对int类型进行排序，所以需要使用模版进行封装
template <class T>
static void bubbleSortTemplate(T arr[], int len) {

    //记录最后一次交换位置
    int n = len;
    int newn = 0;

    do {
        newn = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);  //一次交换3次赋值
                newn = i;
            }
        }

        n = newn;
    } while (n > 0);


}


/**
 * 选择排序
 * 遍历找出最小的位置，与第一个位置交换 以此类推
 * 时间复杂度O(n^2) 空间复杂度O(1)
 * @param arr
 * @param len
 */
static void selectSort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
            }

        }
        swap(arr[i], arr[min]);

    }

}


//插入排序的前身()
void insertSort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0; --j) {

            if (arr[j] < arr[j - 1]) {
                swap(arr[j - 1], arr[j]);
            } else {
                break;
            }
        }

    }

}

//插入排序 O(n^2)
//在接近排好序的数组，时间复杂度接近O(n)）
void insertSort1(int arr[], int len) {
    int j;
    for (int i = 1; i < len; ++i) {
        int temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; --j) {

            arr[j] = arr[j - 1];


        }

        arr[j] = temp;
    }

}


//希尔排序，是插入排序的另一个优化
void shellInsertSort(int arr[], int len) {
    int increment = len / 2; //

    int i, j, k;
    while (increment > 0) {
        for (i = 0; i < increment; ++i) {
            for (j = i + increment; j < len; j += increment) {
                int temp = arr[j];
//                LOGE("temp:%d", temp);
                for (k = j; k >= increment && arr[k - increment] > temp; k -= increment) {
                    arr[k] = arr[k - increment];
                }
                arr[k] = temp;
            }
        }
//        if()
        increment /= 2;

    }

}


#endif //NDK_ALGORITHM_036_SORT_HPP
