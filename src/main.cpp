using namespace std;
#include <iostream>

#include "SingleLinkedList.h"

int main(){
	std::cout << "Testing linked List" << std::endl;
	SingleLinkedList<int> li;
	li.insertNode(0, 5);
	li.insertNode(1, 10);
	li.insertNode(-1, 15);
	/*
    cout << "Before:" << endl;
    li.printList();
    //li.insertNode(1, 33);
    li.appendNode(1);
    li.appendNode(7);
    li.appendNode(9);
    cout << "Index Access" << endl;
    for (int i = 0; i < li.length; i++){
        cout << "Position: " << i << " | " << "data: " << li[i] << endl;
    }
    cout << "Setting a new value by [] access" << endl;
    li[1] = 99;
    cout << "After:" << endl;
    li.printList();
    cout << "Inserting a node" << endl;
    li.insertNode(1, 15);
    */
    li.printList();

    return 0;
}
