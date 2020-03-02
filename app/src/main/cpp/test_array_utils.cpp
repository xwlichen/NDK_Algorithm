//
// Created by 李陈 on 2019-07-31.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>

namespace ArrayUtils {
    int *create_random_array(int len, int low, int high) {
        int *arr = new int[len];

        for (int i = 0; i < len; ++i) {
            arr[i] = rand() % (high - low) + low;
//            LOGE("%d", arr[i]);
//            LOGE("%d", arr[i]);

        }

        return arr;
    }


    int *copy_arry(int *arry, int len) {
        int *copy_arry = new int[len];
        memcpy(copy_arry, arry, sizeof(int) * len);
        return copy_arry;

    }

    void sort_arry(char *sortName, void(*sort)(int *, int), int *arry, int len) {
        size_t start_time = clock();
        sort(arry, len);
        size_t end_time = clock();

        double cost_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        LOGE("%s的耗时：%1f", sortName, cost_time);

        //检测这个数组有没有排好序
        for (int i = 0; i < len - 1; ++i) {
            assert(arry[i] <= arry[i + 1]);

        }

    }


    int *create_nearly_order_array(int len, int swapNUm) {
        int *arr = new int[len];

        for (int i = 0; i < len; ++i) {
            arr[i] = i;

        }

        for (int i = 0; i < swapNUm; ++i) {
            int randomX = rand() % (len - 1);
            int randomY = rand() % (len - 1);
            std::swap(arr[randomX], arr[randomY]);

        }

        return arr;
    }
}

