//
// Created by alan on 2020/2/24.
//

#ifndef LISTNODE_LISTNODE_H
#define LISTNODE_LISTNODE_H

#include <iostream>
using namespace std;


class ListNode {

public:
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


};


#endif //LISTNODE_LISTNODE_H
