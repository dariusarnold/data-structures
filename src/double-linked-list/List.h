#ifndef LIST_H
#define LIST_H

#include "Item.h"

/*
 * Schnittstelle für Listen mit den aus Vorlesung 3 bekannten
 * Listenoperationen.
 */
class List
{
    public:
        virtual void splice(Item * a, Item * b, Item * t) = 0;

        virtual Item * head() = 0;
        virtual bool isEmpty() = 0;
        virtual Item * first() = 0;
        virtual Item * last() = 0;
        virtual void moveAfter(Item * b, Item * a) = 0;
        virtual void moveToFront(Item * b) = 0;
        virtual void moveToBack(Item * b) = 0;
        virtual void remove(Item * b) = 0;
        virtual void popFront() = 0;
        virtual void popBack() = 0;
        virtual Item * insertAfter(int x, Item * a) = 0;
        virtual Item * insertBefore(int x, Item * b) = 0;
        virtual void pushFront(int x) = 0;
        virtual void pushBack(int x) = 0;
        virtual Item * find(int x) = 0;
        virtual int size() = 0;
};

#endif // LIST_H
