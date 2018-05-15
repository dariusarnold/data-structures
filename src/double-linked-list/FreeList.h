#ifndef FREELIST_H
#define FREELIST_H

#include "Item.h"
#include "List.h"

/*
 * Die Klasse FreeList implementiert einen Speicher für unbenutzte Elemente
 * einer LinkedList. Wird einer LinkedList ein Element hinzugefügt, muss
 * diese somit kein neues Element allokieren, sondern kann eines der
 * Elemente der FreeList verwenden (das aus dieser entfernt und in die
 * LinkedList eingehängt wird). Ist die FreeList leer, werden mittels
 * reallocate() mehrere neue leere Elemente gleichzeitig allokiert. Dies
 * spart Kosten gegenüber der einzelnen Allokation von Elementen. Wird ein
 * Element aus der LinkedList entfernt, kann es in die FreeList eingehängt
 * und zu einem späteren Zeitpunkt wiederverwendet werden.
 */
class FreeList{
public:
	/**
	 * Create a new FreeList, allocating a chunk of blocksize new items.
	 */
	FreeList();
	/**
	 * Delete FreeList with all items including the dummy element.
	 */
	~FreeList();
	/**
	 * @return True if the list is empty, false otherwise
	 */
	bool isEmpty();
	/**
	 * Get item from free list, allocating a chunk of blocksize new items if FreeList is empty.
	 * @return Pointer to new item
	 */
	Item* getItem();
	/**
	 * Append an item to the FreeList.
	 * @param a Item to append. Will be inserted into the first position behind the dummy element.
	 */
	void appendItem(Item* a);
private:
	/**
	 * Size of chunk of items to be allocated at once
	 */
	int blocksize = 10;
	/**
	 * Pointer to dummy node
	 */
	Item* dummy;
	/**
	 * Allocate a block of new items with size blocksize, used when FreeList is empty
	 */
	void allocateItemBlock();
};

#endif // FREELIST_H
