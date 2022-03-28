#ifndef INSERTION_H
#define INSERTION_H

#include "sort.h"

template <class ItemType>
class InsertionSort: public Sort<ItemType>{

public:
    InsertionSort();

    void sort(ArrayList<ItemType>&);

};

#include "insertionsort.cpp"
#endif