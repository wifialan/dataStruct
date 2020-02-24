#include <iostream>
#include "ArrayQueue.h"
#include "LoopQueue.h"

using namespace std;


int main() {

//    ArrayQueue<int> *queue = new ArrayQueue<int>();
//    for (int i = 0; i < 10; ++i) {
//        queue->enqueue(i);
//        queue->print();
//    }
//    std::cout << queue->getCapacity() << std::endl;
//    queue->dequeue();
//    queue->print();
//    std::cout << "Hello" << std::endl;
    LoopQueue<int> * loop_queue = new LoopQueue<int>(20);
    for (int i = 0; i < 12; ++i) {
        loop_queue->enqueue(i);
        loop_queue->print();
    }
    loop_queue->dequeue();
    loop_queue->print();

    return 0;
}
