#ifndef ALTERNATIVELINKEDLIST_H
#define ALTERNATIVELINKEDLIST_H

#include "Item.h"
#include "List.h"

/*
 * Deklariert hier die AlternativeLinkedList ohne Dummy-Element.
 *
 * Diese Liste soll keine FreeList verwenden, denn die move-Methoden
 * erlauben es in dieser Implementierung nicht Elemente aus anderen
 * Listen einzufügen (dafür benötigten wir einen Pointer auf die Liste,
 * aus denen die Elemente stammen).
 *
 * In CodeBlocks könnt ihr die Liste bauen und testen, indem ihr in der
 * Target-DropDown-Liste "AlternativeLinkedList" auswählt.
 */
class AlternativeLinkedList : public List
{

};

#endif // ALTERNATIVELINKEDLIST_H
