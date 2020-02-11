//
// Created by root on 1/31/20.
//

#ifndef STACK_ARRAYSTACK_H
#define STACK_ARRAYSTACK_H

#include<iostream>
#include <string>
#include "Array.h"

using namespace std;

template<class T>
class arrayStack {
    Array<T> *array;
public:

public:
    arrayStack(int capacity) {
        array = new Array<T>[capacity];
    }

    arrayStack() {
        array = new Array<T>[10];
    }

    int getSize() {
        return array->getSize();
    }

    bool isEmpty() {
        return array->isEmpty();
    }

    int getCapacity() {
        return array->getCapacity();
    }

    void push(T e) {
        array->addLast(e);
    }

    T pop() {
        return array->removeLast();
    }

    T peek() {
        return array->getLast();
    }

    void print() {
        std::cout << "Stack: [";
        for (int i = 0; i < array->getSize() - 1; ++i) {
            std::cout << array->get(i) << ", ";
        }
        std::cout << array->get(array->getSize() - 1);
        std::cout << "]" << " Top" << std::endl;
    }
};

#endif //STACK_ARRAYSTACK_H
