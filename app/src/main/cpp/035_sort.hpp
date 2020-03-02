//
// Created by 李陈 on 2019-07-23.
//

#ifndef NDK_ALGORITHM_035_SORT_H
#define NDK_ALGORITHM_035_SORT_H


#include <android/log.h>
#include "test_log.hpp"

using namespace std;

//冒泡排序 时间复杂度O(n^2)
//优化 1、鸡尾酒排序；2、记一个标志位排序；3、遍历的可以记录一下位置
static void bubbleSort(int arr[], int len) {

    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);  //一次交换3次赋值
            }
        }
    }

}



#endif //NDK_ALGORITHM_035_SORT_H
