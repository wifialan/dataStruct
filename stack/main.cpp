#include <iostream>
#include "arrayStack.h"

int main() {

    arrayStack<int> *stack = new arrayStack<int>();
    for (int i = 0; i < 5; ++i) {
        stack->push(i);
        stack->print();
    }
    stack->pop();
    stack->print();

    return 0;
}
