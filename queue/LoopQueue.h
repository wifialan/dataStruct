//
// Created by root on 2/11/20.
//

#ifndef QUEUE_LOOPQUEUE_H
#define QUEUE_LOOPQUEUE_H

#include <iostream>
#include "Array.h"

template<class E>
class LoopQueue{

private:
    E *data;
    int front, tail;
    int capacity, size;
    int len;

public:
    LoopQueue(int capacity) {
        data = new E (capacity + 1);
        front = 0;
        tail = 0;
        size = 0;
        len = capacity + 1;
        this->capacity = capacity;

    }

    LoopQueue() {
        data = new E (10 + 1);
        front = 0;
        tail = 0;
        size = 0;
        len = 10 + 1;
        this->capacity = 10;
    }

    int getCapacity() {
        return capacity;
    }

    int getLen(){
        return len;
    }

    bool isEmpty() {
        return front == tail;
    }

    int getSize() {
        return size;
    }

    void enqueue(E e) {
        std::cout << "tail: " << tail;
        std::cout << " front: " << front;
        std::cout << " capacity: " << getCapacity() << std::endl;
        std::cout << "writing data: " << e << std::endl;
//        if ((tail + 1) % getLen() == front) {
//            std::cout << "Begin to resize" << std::endl;
//            resize(getCapacity() * 2);
//        }
//        *(&data[0] + tail) = e;
        data[tail] = e;
        printf("Addr: %p\n",&data[tail]);
        size ++;
        tail ++;
    }

    E dequeue(){
        if(isEmpty())
            throw "Error 404";
        E ret = data[front];
        data[front] = 0;
        front = (front + 1) % getLen();
        size --;
        if(size == getCapacity() / 4 && getCapacity() / 2 != 0)
            resize(getCapacity()/2);
        return ret;
    }

    E getFront(){
        if(isEmpty())
            throw "Error 404";
        return data[front];
    }

    void resize(int newCapacity) {
        std::cout << "RESIZE" << std::endl;
        E *newData = new E (newCapacity);
        for (int i = 0; i < size; ++i) {
            newData[i] = data[(i + front) % getLen()];
        }
        data = newData;
        front = 0;
        tail = size;
    }

    void print() {
        std::cout << "Queue: size = " << size << " capacity = " << getCapacity() << std::endl;
        std::cout << "front [";
        for (int i = front; i != tail; i = (i + 1) % getCapacity()) {
            std::cout << *(&data[0] + i);
            if((i + 1) % getCapacity() != tail)
                std::cout << " ,";
        }
//        std::cout << data->get(data->getSize() - 1);
        std::cout << "]" << " Tail" << std::endl;
    }

};

#endif //QUEUE_LOOPQUEUE_H
