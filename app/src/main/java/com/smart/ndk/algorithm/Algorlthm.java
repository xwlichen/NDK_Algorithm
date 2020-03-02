package com.smart.ndk.algorithm;

/**
 * @author lichen
 * @date ：2019-07-23 08:30
 * @email : 196003945@qq.com
 * @description :
 */
public class Algorlthm {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    /**
     * 链表
     * @return
     */
    public static native String test034();


    /**
     * 冒泡
     * @return
     */
    public  static  native  String test035();
}
