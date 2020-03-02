//
// Created by 李陈 on 2019-07-30.
//

#ifndef NDK_ALGORITHM_A_LOG_H
#define NDK_ALGORITHM_A_LOG_H

#include <android/log.h>
#include <string>



#define TAG "smart"
////结构体别名
//typedef int size_int_1;
////方法别名
//#define printT(num) print(TAG,int num)
//
//
//void print(char *tag, int num) {
//
//}

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__);
//#define LOGE(tag, ...) __android_log_print(ANDROID_LOG_ERROR,tag, __VA_ARGS__);


#endif //NDK_ALGORITHM_A_LOG_H
