//
// Created by 李陈 on 2019-06-21.
//


#ifndef NDK_ALGORITHM_LINKEDLIST_HPP
#define NDK_ALGORITHM_LINKEDLIST_HPP

#include <assert.h>


template<class E>
struct Node {

    Node<E> *prev;
    Node<E> *next;

    E value;

public:
    Node(E value, Node<E> *prev, Node<E> *next) {
        this->value = value;
        this->prev = prev;
        this->next = next;

    }

};


template<class E>
class LinkedList {
public:
    //头指针
    Node<E> *head = NULL;
    //尾节点
    Node<E> *last = NULL;
    //集合的长度
    int len = 0;


public:

    /**
     * 添加数据
     * @param e  元素
     */
    void push(E e);

    /**
     * 长度
     * @return  int
     */
    int size();

    /**
     * 获取值
     * @param index
     */
    E get(int index);

    void insert(int index, E e);

    E remove(int index);


    Node<E> *node(int index);

    ~LinkedList();

    void linkLast(E e);

    void linkBefore(Node<E> *pNode, E e);

    E unlink(Node<E> *pNode);
};

template<class E>
void LinkedList<E>::push(E e) {

    //单链表的添加
//    Node<E> *new_node = new Node<E>(e, NULL);
//    if (head) {
//        //找到尾巴节点，又一个特定就是next节点为空
//        /*Node<E> *h = head;
//        while (h) {
//            if (h->next == NULL) {
//                break;
//            }
//            h = h->next;
//        }
//
//        h->next = new_node;*/
//
//        //优化  O(n)
//        //Node<E> *last = node(len - 1);
//        //last->next = new_node;
//
//        //双向链表优化
//        last->next = new_node; //O(1)
//
//
//    } else {
//        head = new_node;
//    }
//    last = new_node;
//    len++;



    //双向链表的添加
    linkLast(e);
    len++;

}

template<class E>
Node<E> *LinkedList<E>::node(int index) {

    //单链表
//    Node<E> *h = head;
//    for (int i = 0; i < index; ++i) {
//        h = h->next;
//
//    }
//    return h;

    //双链表优化
    if (index < len >> 1) {
        //从前往后遍历
        Node<E> *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;

        }
        return cur;

    } else {
        Node<E> *cur = last;
        for (int i = len - 1; i > index; --i) {
            cur = cur->prev;

        }
        return cur;
    }

}

template<class E>
int LinkedList<E>::size() {
    return len;
}


template<class E>
E LinkedList<E>::get(int index) {

    assert(index >= 0 && index < len);
    return node(index)->value;

}


template<class E>
void LinkedList<E>::insert(int index, E e) {
    assert(index >= 0 && index <= len);

    //单链表的插入
//    Node<E> *new_node = new Node<E>(e, NULL);
//
//    //考虑边界
//    if (index == 0) {
//
//        Node<E> *h = head;
//        head = new_node;
//        new_node->next = h;
//
//    } else {
//        //考虑最后的位置
//
//        Node<E> *prev_node = node(index - 1);
//
//        //Node *next_node=prev_node->next;
//
//        new_node->next = prev_node->next;
//        prev_node->next = new_node;
//    }
//
//    len++;


    //双向链表的插入
    if (index == len) {
        linkLast(e);
    } else {
        linkBefore(node(index), e);
    }
    len++;
}


template<class E>
E LinkedList<E>::remove(int index) {
    assert(index >= 0 && index < len);
    //单链表的删除
//    Node<E> *current = node(index);
//
//    if (index == 0) {
//        head = head->next;
//    } else {
//        Node<E> *prev = node(index - 1);
//        prev->next = current->next;
//        //释放 因为节点都是 new出来的所以要手动释放
//        delete current;
//    }
//
//
//    len--;



    //双向链表的删除
    return unlink(node(index));


}


template<class E>
LinkedList<E>::~LinkedList() {
    //析构释放内存，析构节点指针
    Node<E> *h = head;
    while (h) {
        // next 保存
        Node<E> *next = h->next;
        delete h;
        h = next;
    }
    __android_log_print(ANDROID_LOG_ERROR, "TAG", "析构函数");
    head = NULL;
    last = NULL;

}

template<class E>
void LinkedList<E>::linkLast(E e) {
//    Node<E> *last_temp = last;

    Node<E> *new_node = new Node<E>(e, last, NULL);


    if (head) {
        last->next = new_node;

    } else {
        head = new_node;
    }

    last = new_node;


}

template<class E>
void LinkedList<E>::linkBefore(Node<E> *cur, E e) {
    Node<E> *prev = cur->prev;
    Node<E> *new_node;
    new_node = new Node<E>(e, prev, cur);
    cur->prev = new_node;
    if (prev) {
        prev->next = new_node;
    } else {
        head = new_node;

    }

}

template<class E>
E LinkedList<E>::unlink(Node<E> *cur) {

    Node<E> *prev = cur->prev;
    Node<E> *next = cur->next;
    E value = cur->value;

    if (prev) {
        prev->next = next;
    } else {
        head = next;
    }

    if (next) {
        next->prev = prev;
    } else {
        last = prev;
    }

    delete cur;
    len--;
    return value;

}

#endif //NDK_ALGORITHM_LINKEDLIST_HPP