//
// Created by root on 2/11/20.
//

#ifndef VALIDPARENTHESES_SOLUTION_H
#define VALIDPARENTHESES_SOLUTION_H

#include <string>
#include "arrayStack.h"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        arrayStack<char> *stack = new arrayStack<char>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.at(i);
            if(c == '(' || c == '[' || c == '{')
                stack->push(c);
            else{
                if(stack->isEmpty())
                    return false;
                char topChar = stack->pop();
                if(c == ')' && topChar != '(')
                    return false;
                if(c == ']' && topChar != '[')
                    return false;
                if(c == '}' && topChar != '{')
                    return false;
            }
        }
        return stack->isEmpty();
    }
};

#endif //VALIDPARENTHESES_SOLUTION_H
