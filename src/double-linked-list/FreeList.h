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
class FreeList
{

};

#endif // FREELIST_H
