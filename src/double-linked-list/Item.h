#ifndef ITEM_H
#define ITEM_H

/*
 * Die Klasse Item repräsentiert die Listenelemente.
 */
//template <typename T>
class Item{
public:
    Item(){};
    //Item<T>(T value);
    //Item<T>(T value, Item* next_item, Item* prev_item);
    Item(int value){e = value; next = nullptr; prev = nullptr;};
	Item(int value, Item* next_item, Item* prev_item){
		e = value; next = next_item; prev = prev_item;
	};
    Item* next;
    Item* prev;
    int e;
    //T e;

};

#endif // ITEM_H
