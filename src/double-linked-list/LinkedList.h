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
    LinkedList();
    void splice(Item* a, Item* b, Item* t);
    Item* head();
    bool isEmpty();
    Item* first();
    Item* last();
    void moveAfter(Item* b, Item* a);
    void moveToFront(Item* b);
    void moveToBack(Item* b);
    void remove(Item* b);
    void popFront();
    void popBack();
    Item* insertAfter(int x, Item* a);
    Item* insertBefore(int x, Item* b);
    void pushFront(int x);
    void pushBack(int x);
    Item* find(int x);
    int size();
private:
    Item* dummy;
    /**
     * Returns a new node instance with a set value. If the FreeList contains nodes, returns one from the FreeList,
     * otherwise it will allocate multiple new nodes, attach them to the FreeList and return one.
     * @param x
     * @return
     */
    Item* getNewNode(int x);
};


#endif // LINKEDLIST_H
