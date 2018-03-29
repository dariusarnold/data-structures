using namespace std;
#include <iostream>

#include "single_linked_list.h"

int main(){
    SingleLinkedList<int> li;
    cout << "Before:" << endl;
    li.printList();
    li.appendNode(1);
    li.appendNode(7);
    li.appendNode(9);
    cout << "Index Access" << endl;
    for (int i = 0; i < li.length; i++){
        cout << "Position: " << i << " | " << "data: " << li[i] << endl;
    }
    cout << "After:" << endl;
    li.printList();

    
    
    return 0;
}