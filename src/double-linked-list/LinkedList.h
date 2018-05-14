#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include "FreeList.h"
#include "Item.h"

/*
 * Deklariert hier die LinkedList mit Dummy-Element.
 * In CodeBlocks könnt ihr die Liste bauen und testen, indem ihr in der
 * Target-DropDown-Liste "LinkedList" auswählt.
 */
class LinkedList : public List{
public:
	/**
	 * Create an empty LinkedList. Contains only dummy node.
	 */
    LinkedList();
    /**
     * Remove sequence a to b from list and attach it after t.
     */
    void splice(Item* a, Item* b, Item* t);
    /**
     * Get dummy node
     * @return Pointer to dummy node
     */
    Item* head();
    /**
     * Return first node in list. Returns dummy node if llist is empty.
     * @return Pointer to first node in list
     */
    Item* first();
    /**
     * Return last node in list. Returns dummy node if list is empty.
     * @return Pointer to last node in list
     */
    Item* last();
    /**
     * Check if list is empty.
     * @return true for empty list, false otherwise
     */
    bool isEmpty();
    /**
     * Cut item b out of list and move it after item a.
     */
    void moveAfter(Item* b, Item* a);
    /**
     * Move item b from its position in the list to the front of the list.
     * @param b Node to move
     */
    void moveToFront(Item* b);
    /**
     * Move item b from its position in the list to the back of the list.
     * @param b Node to move
     */
    void moveToBack(Item* b);
    /**
     * Remove item b from the list
     * @param b Item to remove
     */
    void remove(Item* b);
    /**
     * Remove the first item in the list
     */
    void popFront();
    /**
     * Remove the last item in the list
     */
    void popBack();
    /**
     * Insert value x after Item a
     * @param x Integer value to insert into the list
     * @param a Item after which x is to be inserted
     * @return Pointer to newly inserted item with value x
     */
    Item* insertAfter(int x, Item* a);
    /**
     * Insert value x in front of Item b
     * @param x Integer value to insert into the list
     * @param b Item in front of which x is to be inserted
     * @return Pointer to newly inserted item with value x
     */
    Item* insertBefore(int x, Item* b);
    /**
     * Insert value x as the first element of the list
     * @param x Integer value to insert
     */
    void pushFront(int x);
    /**
     * Insert value x as the last element of the list
     * @param x Integer value to insert
     */
    void pushBack(int x);
    /**
     * Search a value in the list. Will return the pointer to the first item with value x if x is in the list.
     * Otherwise this function will return the pointer to the dummy element. To get a boolean result, the return
     * value of this function has to be compared with head().
     * @param x Integer value to find in list
     * @return Pointer to the first element with value x if x is in list, pointer to dummy element otherwise.
     */
    Item* find(int x);
    int size();
private:
    /**
     * Pointer to dummy element, acts as an entry point to the list.
     */
    Item* dummy;
    /**
     * Returns a new node instance with a set value. If the FreeList contains nodes, returns one from the FreeList,
     * otherwise it will allocate multiple new nodes, attach them to the FreeList and return one.
     * @param x
     * @return
     */
    Item* getNewNode(int x);
    /**
     * "Delete" a node by attaching it to the FreeList.
     * @param a The node to "delete"
     */
    void deleteNode(Item* a);
};


#endif // LINKEDLIST_H
