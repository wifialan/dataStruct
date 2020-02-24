//
// Created by root on 2/11/20.
//

#ifndef QUEUE_ARRAYQUEUE_H
#define QUEUE_ARRAYQUEUE_H

#include <iostream>
#include "Array.h"

template<class T>
class ArrayQueue{
private:
    Array<T> *array;
public:
    ArrayQueue(int capacity) {
        array = new Array<T>(capacity);
    }

    ArrayQueue() {
        array = new Array<T>(10);
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

    void enqueue(T e) {
        array->addLast(e);
    }

    T dequeue() {
        return array->removeFirst();
    }

    T getFront() {
        return array->getFirst();
    }

    void print() {
        std::cout << "Queue: front [";
        for (int i = 0; i < array->getSize() - 1; ++i) {
            std::cout << array->get(i) << ", ";
        }
        std::cout << array->get(array->getSize() - 1);
        std::cout << "]" << " Tail" << std::endl;
    }
};

#endif //QUEUE_ARRAYQUEUE_H
