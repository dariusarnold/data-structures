/* ! Exclude this file from the build when compiling in Eclipse */

#include <iostream>
#include "SingleLinkedList.h"

#define DEBUG 1

template<class T>
SingleLinkedList<T>::SingleLinkedList(){
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList(){
    std::cout << "Destructor called" << std::endl;
    if (head != nullptr){
        Node *current = head;
        while (current != nullptr){
                Node *next = current->next;
                std::cout << "Deleting " << current->data << std::endl;
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
    	std::cout << "EMPTY" << std::endl;
    }else{
        while (current != nullptr){
        	std::cout << current->data << std::endl;
            current = current->next;
        }
    }
}

template<class T>
bool SingleLinkedList<T>::isEmpty(){
	return length == 0 ? true : false;
}

template<class T>
void SingleLinkedList<T>::appendNode(T dat){
    // Append data dat to the end of the list
    Node *n = new Node();
    n->data = dat;
    n->next = nullptr;
    if (length == 0){
    	// Empty list: head also points to new node
        head = n;
    }else{
    	// List not empty: next of previous node points to new node
        tail->next = n;
    }
    tail = n;
    length++;
}

template <class T>
void SingleLinkedList<T>::prependNode(T dat){
	// Prepend data dat to the beginning of the list
	Node *n = new Node();
	n->data = dat;
	n->next = head;
	head = n;
	if (tail == nullptr) tail = n;
	length++;
}

template<class T>
T& SingleLinkedList<T>::operator[](int index){
    if (index > length){
    	std::string error_message = "List index " + std::to_string(index) + " out of range: " + std::to_string(length);
        throw std::out_of_range(error_message);
    }
    int position = 0;
    Node *current_node = head;
    while (position < index){
        current_node = current_node->next;
        position++;
    }
    return current_node->data;
}

template<class T>
void SingleLinkedList<T>::insertNode(int index, T dat){
	// Insert node at a given position. Throws out of range exception if index is larger than list size
	if (index > length){
		std::string error_message = "List index " + std::to_string(index) + " out of range: " + std::to_string(length);
		throw std::out_of_range(error_message);
	}
	if (index == 0){
		prependNode(dat);
	}else if (index == length){
		appendNode(dat);
	}
	else{
		Node *n = new Node();
		n->data = dat;
    	int position = 0;
    	Node *current_node = head;
    	Node *previous_node = head;
    	while (position < index){
    		previous_node = current_node;
    		current_node = current_node->next;
    		position++;
    	}
    	// Insert node into list
    	previous_node->next = n;
    	n->next = current_node;
    	length++;
    }
}

template<class T>
void SingleLinkedList<T>::deleteNode(int index){
	if (head == nullptr){
		throw std::logic_error("Can't delete node in empty list!");
	}else{
		int position = 0;
		Node *current_node = head;
		while (position < index){
			current_node = current_node->next;
			position++;
		}
		length--;
	}
}
