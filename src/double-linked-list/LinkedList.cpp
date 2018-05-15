#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
	dummy = new Item();
	dummy->next = dummy;
	dummy->prev = dummy;
	dummy->e = 0;
	FreeList free;
}

void LinkedList::splice(Item* a, Item* b, Item* t){
	if (a->prev != nullptr and a-> next != nullptr and b->prev != nullptr and b->next != nullptr){
		//remove sequence a to b from list if it is in list
		a->prev->next = b->next;
		b->next->prev = a->prev;
	}
	//insert sequence a to b after t
	Item* t_next_saved = t->next;
	b->next = t_next_saved;
	a->prev = t;
	t->next = a;
	t_next_saved->prev = b;

}

Item* LinkedList::getNewNode(int x){
	Item* n = free.getItem();
	n->e = x;
	return n;
}

bool LinkedList::isEmpty(){
	return (dummy->next ==dummy->prev);
}

void LinkedList::moveAfter(Item* b, Item* a){
	// moves b after a
	splice(b, b, a);
}

void LinkedList::moveToFront(Item* b){
	splice(b, b, dummy);
}

void LinkedList::moveToBack(Item* b){
	splice(b, b, dummy->prev);
}

void LinkedList::remove(Item* b){
	if (b == head()) return; // dont remove dummy node
	b->prev->next = b->next;
	b->next->prev = b->prev;
	free.appendItem(b);
}

void LinkedList::popFront(){
	Item* front = first();
	remove(front);
}

void LinkedList::popBack(){
	Item* back = last();
	remove(back);
}

Item* LinkedList::insertAfter(int x, Item* a){
	Item* new_node = getNewNode(x);
	moveAfter(new_node, a);
	return new_node;
}

Item* LinkedList::insertBefore(int x, Item* b){
	return insertAfter(x, b->prev);
}

void LinkedList::pushFront(int x){
	insertAfter(x, dummy);
}

void LinkedList::pushBack(int x){
	insertAfter(x, dummy->prev);
}

Item* LinkedList::find(int x){
	dummy->e = x; //place an elephant in Kairo
	Item* current_node = dummy;
	do {
		current_node = current_node->next;
		if (current_node->e == x) break;
	}
	while (current_node != dummy);
	dummy->e = 0; //remove elephant from Kairo
	return current_node;
}

int LinkedList::size(){
	Item* current_node = dummy->next;
	int size = 0;
	while (current_node != dummy){
		current_node = current_node->next;
		++size;
	}
	return size;
}

Item* LinkedList::head(){
	return dummy;
}

Item* LinkedList::first(){
	return dummy->next;
}

Item* LinkedList::last(){
	return dummy->prev;
}
