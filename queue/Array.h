#ifndef TEST_01_ARRAY_H
#define TEST_01_ARRAY_H

#include <iostream>
#include <string.h>
//
// Created by multimicro on 2020/1/21.
//
template <class T>
class Array {

    /**
     * 指针和数组的区别：
        1.空间分配：数组是静态分配，且分配的空间是连续的；指针是动态分配，分配的空间不一定是连续的。
        2.安全性：使用数组可能会造成数组越界；指针使用时可能会造成内存泄漏。
        3.访问效率：数组直接访问数据；指针是间接访问数据。
        4.函数形参：一维数组用元素指针来接；指针用指针的指针来接。
        5.处理数据：指针偏向于地址的处理；数组偏向于数据的处理。
     */
private:
    int *data;
    int size;
    int capacity;
    int currentLen;

    //构造函数，传输数组的容量capacity构造array
public:
    Array(int capacity){
        data = new int [capacity];
        memset(data,0,capacity);
        size = 0;
        this->capacity = capacity;
        currentLen = 0;
    }
    //无参数的构造函数，默认数组的容量capacity=10
    Array(){
        data = new int[10];
        memset(data,0,10);
        size = 0;
        this->capacity = 10;
        currentLen = 0;
    }
    //获取数组中元素个数
    int getSize(){
        return size;
    }
    // 获取数组的容量
    int getCapacity(){
        return this->capacity;
    }
    // 返回数组是否为空
    bool isEmpty(){
        return size==0;
    }
    // 向所有元素后添加一个新元素
    void addLast(int e){
#if 0
        if(size == sizeof(data))
            throw "AddLast failed. Array is full!";
        data[size] = e;
        size ++;
#endif
        add(size, e);
    }
    // 向所有元素前添加一个新元素
    void addFirst(int e){
        add(0, e);
    }
    // 在第index个位置插入一个新元素e
    void add(int index, int e){

        if(index < 0 || index > size)
            throw "Add failed. Required index > 0 and index > size.";
        if(size == capacity)
            resize(2 * capacity);

        for (int i = size - 1; i >=index; i --) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size ++;
        if(currentLen<size)
            currentLen = size;
    }

    // 获取index索引位置的元素
    T get(int index){
        if(index <0 || index >= capacity)
            throw 2;
        return data[index];
    }

    T getLast(){
        return get(size - 1);
    }

    T getFirst(){
        return get(0);
    }
    // 更改index索引位置的元素
    void set(int index, int e){
        if(index < 0 || index >= capacity)
            throw "2";
        data[index] = e;
    }
    // 查找数组中是否有元素e
    bool contains(int e){
        for (int i = 0; i < size; ++i) {
            if(data[i] == e)
                return true;
        }
        return false;
    }
    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    int find(int e){
        for (int i = 0; i < size; ++i) {
            if(data[i] == e)
                return i;
        }
        return -1;
    }
    // 移除index位置的元素，并返回删除的元素
    int remove(int index){
        if(index <0 || index >= size)
            throw 2;
        int ret = data[index];
        for (int i = index + 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        size --;
        if(size == capacity / 4 && capacity / 2 != 0)
            resize(capacity / 2);
        return ret;
    }
    // 移除第一个位置的元素，并返回删除的元素
    int removeFirst(){
        return remove(0);
    }
    // 移除最后一个位置的元素，并返回删除的元素
    int removeLast(){
        return remove(size-1);
    }
    // 从数组中删除元素e
    bool removeElement(int e){
        int index = find(e);
        if(index != -1){
            remove(index);
            return true;
        }
        return false;
    }

    // 输出数组内容
    void printArray(){
        std::cout << "Array: size = " << size << " , capacity = " << capacity <<std::endl;
        std::cout << "[";
        for (int i = 0; i < size-1; ++i) {
            std::cout  << data[i] << ",";
        }
        std::cout << data[size-1] << "]" << std::endl;
    }

private:
    void resize(int newCapacity) {
        capacity = newCapacity;
        int *newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        data = newData;
    }
};

#endif //TEST_01_ARRAY_H