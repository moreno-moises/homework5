#ifndef SELECTION_H
#define SELECTION_H

#include "sort.h"

template <class ItemType>
class SelectionSort: public Sort<ItemType>{

public:
    SelectionSort();

    void sort(ArrayList<ItemType>&);

};

#include "selectionsort.cpp"
#endif