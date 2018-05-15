#include "FreeList.h"

FreeList::FreeList(){
	dummy = new Item();
	dummy->next = dummy;
	dummy->prev = dummy;
	allocateItemBlock();
}

void FreeList::allocateItemBlock(){
	for (int i = 0; i < blocksize; i++){
		Item* t = new Item();
		appendItem(t);
	}
}

bool FreeList::isEmpty(){
	return dummy->next == dummy->prev;
}

void FreeList::appendItem(Item* a){
	Item* b = dummy->next;
	a->next = b;
	a->prev = dummy;
	dummy->next = a;
	b->prev = a;
}

Item* FreeList::getItem(){
	if (!isEmpty()){
		// there is at least one item in the free list, remove it and return it
		Item* a = dummy->next;
		dummy->next = a->next;
		a->next->prev = dummy;
		return a;
	}else{
		// free list is empty, allocate a new item block and return one
		allocateItemBlock();
		return getItem();
	}
}
