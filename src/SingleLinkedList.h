#ifndef SINGLELIST_H
#define SINGLELIST_H

template<class T>
class SingleLinkedList{
    
    struct Node{
    	Node();
    	Node(T data);
    	Node(T dat, Node* n);
        T data;
        Node *next = nullptr;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    public:
    int length = 0;

    // Create an empty linked list
    SingleLinkedList();
    ~SingleLinkedList();
    // Append dat to the end if the list
    void appendNode(T dat);
    // Prepend dat to the beginning of the list
    void prependNode(T dat);
    // Enable read/write index access
    T& operator[](int index);
    // Insert dat at position index
    void insertNode(int index, T dat);
    // Delete Node at index
    void deleteNode(int index);
    bool isEmpty();
    // Output List
    void printList();
};

#include "SingleLinkedList.cpp"

#endif
