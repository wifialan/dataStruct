//
// Created by alan on 2020/2/24.
//

#ifndef LISTNODE_LINKEDLIST_H
#define LISTNODE_LINKEDLIST_H

#include <iostream>

template <class E>

class LinkedList{

private:
    class Node{

    public:
        E e;
        Node next;

    public:
        Node(E e, Node nest){
            this->e = e;
            this->next = next;
        }
        Node(E e){
            this->e = e;
            this->next = NULL;
        }
        Node(){
            this->e = NULL;
            this->next = NULL;
        }
    };


private:
    Node dummyHead;
    int size;

public:
    LinkedList(){
        dummyHead = new Node(NULL, NULL);
        size = 0;
    }

    //获取链表中的元素个数
public:
    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void addFirst(E e){
//        Node node = new Node(e);
//        node.next = head;
//        head = node;
        head = new Node(e, head);

        size ++;
    }

    // 在链表的index(0-based)位置添加新的元素e
    // 在链表中不是一个常用的操作，练习用：）
    void add(int index, E e){
        if(index < 0 || index > size){
            std::cout << "Add failed, Illegal index.";
            return;
        }
        //若要在"索引"为0的位置插入元素，根据链表的插入法则，需要构建一个虚拟的前序节点
//        if(index == 0){
//            addFirst(e);
//        } else {
//            Node prev = head; //首先获取链表的头部节点
            Node prev = dummyHead;
            for(int i = 0; i < index - 1; i++){ // 遍历查询到待插入"索引"位置的节点
                prev = prev.next;
            }
            Node node = new Node(e); //将待插入的元素e构造为一个细胞节点(链表中的基本单元)
            node.next = prev.next;
            prev.next = node;

            size ++;
//        }
    }

    void addLast(E e){
        add(size, e);
    }


};

#endif //LISTNODE_LINKEDLIST_H
