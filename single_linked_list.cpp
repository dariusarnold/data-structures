#include <iostream>
#include "single_linked_list.h"

#define DEBUG 1

template<class T>
SingleLinkedList<T>::SingleLinkedList(){
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList(){
    cout << "Destructor called" << endl;
    if (head != nullptr){
        Node *current = head;
        while (current != nullptr){
                Node *next = current->next;
                cout << "Deleting " << current->data << endl;
                delete current;
                
                current = next;
        }
        head = nullptr;
    }
}

template<class T>
void SingleLinkedList<T>::printList(){
    // Traverse list from head to tail and print all data
    Node *current = head;
    if (current == nullptr){
        cout << "EMPTY" << endl;
    }else{
        while (current != nullptr){
            cout << current->data << endl;
            current = current->next;
        }
    }
}

template<class T>
void SingleLinkedList<T>::appendNode(T dat){
    // Append data dat to the end of the list
    Node *n = new Node();
    n->data = dat;
    
    if (head == nullptr){
        // list is empty
        if (DEBUG){
            cout << "Creating new list, ";
        }
        
        n->next = nullptr;
        head = n;
        tail = n;

    }else{
        // list already contains at least one node
        cout << "Appending to List, ";
        tail->next = n;
        tail = n;
        n->next = nullptr;
    }
    if (DEBUG){
            cout << "Data: " << n->data << endl;
        }
    length++;
}

template<class T>
T SingleLinkedList<T>::operator[](int index){
    int position = 0;
    Node *current_node = head;
    while (position < index){
        current_node = current_node->next;
        position++;
    }
    return current_node->data;
}

/*
template<class T>
void SingleLinkedList<T>::insertNode(unsigned int index, T dat){
    if (head == nullptr){
        return
    }

}
*/