#ifndef SLL_H
#define SLL_H

template<class T>
class SingleLinkedList{
    
    struct Node{
        T data;
        Node *next;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    public:
    unsigned int length = 0;

    SingleLinkedList();
    ~SingleLinkedList();
    void appendNode(T dat);
    T operator[](int index);
    void insertNode(int index, T dat);
    void deleteNode(int index);
    void printList();
};

#include "single_linked_list.cpp"

#endif