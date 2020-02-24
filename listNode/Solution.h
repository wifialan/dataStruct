//
// Created by alan on 2020/2/24.
//

#ifndef LISTNODE_SOLUTION_H
#define LISTNODE_SOLUTION_H

#include "ListNode.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if ( head != NULL && head->val == val) {
            ListNode *delNode = head;
            delNode->next = NULL;
        }

    }
};

#endif //LISTNODE_SOLUTION_H
