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
void SingleLinkedList<T>::appendNode(T dat){
    // Append data dat to the end of the list
    Node *n = new Node();
    n->data = dat;
    
    if (head == nullptr){
        // list is empty
        if (DEBUG){
        	std::cout << "Creating new list, ";
        }
        
        n->next = nullptr;
        head = n;
        tail = n;

    }else{
        // list already contains at least one node
    	std::cout << "Appending to List, ";
        tail->next = n;
        tail = n;
        n->next = nullptr;
    }
    if (DEBUG){
    	std::cout << "Data: " << n->data << std::endl;
        }
    length++;
}

template<class T>
T& SingleLinkedList<T>::operator[](int index){
	std::cout << "Called Normal []" << std::endl;
    if (index > length){
    	std::cout << index << std::endl;
        throw std::out_of_range("List index out of range");
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
    if (head == nullptr){
    	appendNode(dat);
    }else{
    	int position = 0;
    	Node *current_node = head;
    	while (position < index){
    		current_node = current_node->next;
    		position++;
    	}
    	Node *n = new Node;
    	n->data = dat;

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
	}
}
