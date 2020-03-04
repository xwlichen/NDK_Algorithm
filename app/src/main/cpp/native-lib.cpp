#include <jni.h>
#include <string>
#include <android/log.h>

#include "034_LinkedList.hpp"
#include "035_sort.hpp"
#include "test_array_utils.cpp"
#include "036_sort.hpp"
#include "037_sort.hpp"


//using namespace ArrayUtils;



extern "C"
JNIEXPORT jstring JNICALL
Java_com_smart_ndk_algorithm_Algorlthm_test034(JNIEnv *env, jclass type) {
    std::string hello = "Hello from C++";


    //测试代码
    LinkedList<int> *linkedList = new LinkedList<int>();

    linkedList->push(0);
    linkedList->push(1);
    linkedList->push(2);


    linkedList->insert(0, -1);
    linkedList->insert(linkedList->size(), 3);
    linkedList->insert(2, 22);

    for (int i = 0; i < linkedList->size(); ++i) {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", linkedList->get(i));
    }

    __android_log_print(ANDROID_LOG_ERROR, "TAG", "----------------------");


    linkedList->remove(0);
    linkedList->remove(linkedList->size() - 1);
    linkedList->remove(2);

    for (int i = 0; i < linkedList->size(); ++i) {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", linkedList->get(i));
    }
//
//    time_t start = clock();
//    for (int i = 0; i < 5; ++i) {
//        linkedList->push(i);
//        __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", linkedList->get(i));
//    }
//
//
//    time_t end = clock();
//    __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", (end - start)/CLOCKS_PER_SEC);

    delete (linkedList);
    return env->NewStringUTF(hello.c_str());
}

static void printArr(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        LOGE("%d", arr[i]);
    }
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_smart_ndk_algorithm_Algorlthm_test035(JNIEnv *env, jclass type) {

    int len = 10;
//    int *arr1 = ArrayUtils::create_random_array(len, 0, 10);

//    int *arr1 = ArrayUtils::create_random_array(len, 20, 100);
    int *arr1 = ArrayUtils::create_nearly_order_array(len, 20);
    printArr(arr1, len);
    LOGE("%s", "------------------------------")
    int *arr2 = ArrayUtils::copy_arry(arr1, len);
    int *arr3 = ArrayUtils::copy_arry(arr1, len);
    int *arr4 = ArrayUtils::copy_arry(arr1, len);
    int *arr5 = ArrayUtils::copy_arry(arr1, len);
    int *arr6 = ArrayUtils::copy_arry(arr1, len);
    int *arr7 = ArrayUtils::copy_arry(arr1, len);






//    bubbleSort(arr, len);
//    selectSort(arr, len);
//    printArr(arr2, len);

//    ArrayUtils::sort_arry("bubbleSort", bubbleSort, arr1, len);
//    ArrayUtils::sort_arry("bubbleSort1", bubbleSort1, arr2, len);
//    ArrayUtils::sort_arry("selectSort", selectSort, arr3, len);
//    ArrayUtils::sort_arry("insertSort", insertSort, arr4, len);
//    printArr(arr4, len);
//    ArrayUtils::sort_arry("insertSort1", insertSort1, arr5, len);
//    ArrayUtils::sort_arry("shellInsertSort", shellInsertSort, arr6, len);
    ArrayUtils::sort_arry("mergeSort", mergeSort, arr7, len);

//    printArr(arr7, len);


    delete[](arr1);
    delete[](arr2);


    return env->NewStringUTF("test035");
}