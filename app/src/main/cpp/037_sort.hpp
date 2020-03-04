//
// Created by 李陈 on 2020-03-04.
//

#ifndef NDK_ALGORITHM_037_SORT_HPP
#define NDK_ALGORITHM_037_SORT_HPP


#include "test_log.hpp"

using namespace std; //这个可能需要在native-lib中引用，才能直接倒入std


//对数组区间[left,mid]和[mid+1,right]进行归并
void merge_(int arr[], int left, int mid, int right) {
    LOGE("%s", "----------merge_");

    //1、对数组进行一次拷贝
    int temp[right - left + 1];
    for (int i = left; i <= right; ++i) {
        temp[i - left] = arr[i];

    }
    //确定好分析之后的变量
    int i = left;
    int j = mid + 1;
    int k = left;
    for (; k <= right; ++k) {

        if (i > mid) {
            arr[j] = temp[j - left];
            j++;
        } else if (j > right) {
            arr[k] = temp[i - left];
            i++;
        } else if (temp[i-left] < temp[j-left]) {
            arr[k] = temp[i - left];
            i++;
        } else {
            arr[j] = temp[j - left];
            j++;
        }

    }

//    1，4，3，6，2，7，9，8
//
//    mid =3 left=0  right=7

}
static void printArrx(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        LOGE("%d", arr[i]);
    }
}

//对数组的[left,right]区间进行归并排序
void mergeSort_(int arr[], int left, int right) {
    //递归到底
    if (left >= right) {
        return;
    }

    int mid = (left + right) >> 1;
    LOGE("%s%d", "----------start1:",mid);
    mergeSort_(arr, left, mid);
    LOGE("%s%d", "----------end1:",mid);

//    LOGE("%s", "----------start2");
    mergeSort_(arr, mid + 1, right);
//    LOGE("%s", "----------end2");
    // 优化要根据具体的场景去做
    if (arr[mid] > arr[mid + 1]) {
        merge_(arr, left, mid, right);
    }

//    printArrx(arr, 10);




}

//归并排序
static void mergeSort(int arr[], int len) {
    mergeSort_(arr, 0, len);

}


#endif //NDK_ALGORITHM_037_SORT_HPP
