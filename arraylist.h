#ifndef ARRAY_LIST
#define ARRAY_LIST
#include "listinterface.h"

template<class ItemType> 
class ArrayList : public ListInterface<ItemType> { 
private: 
    static const int DEFAULT_CAPACITY = 100; 
    ItemType items[DEFAULT_CAPACITY + 1]; //(ignore items[0])
    int itemCount; 
    int maxCount; 
public: 
    ArrayList();
    bool isEmpty() const; 
    int getLength() const; 
    bool insert(int newPosition, const ItemType& newEntry); 
    bool remove(int position); 
    void clear(); 
    ItemType replace(int position, const ItemType& newEntry); 
    ItemType getEntry(int position) const; 
    ~ArrayList() { }
}; 
#include "arraylist.cpp" 
#endif
