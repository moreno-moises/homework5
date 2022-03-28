#ifndef SORT_H
#define SORT_H

#include <chrono>
#include "arraylist.h"

template<class ItemType>
class Sort {
protected:
    int swaps;
    int comparisons;
    std::chrono::milliseconds runTime;

    public:
    Sort();

    int getSwaps();
    int getComparisons();
    std::chrono::milliseconds getRunTime();

    virtual void sort(ArrayList<ItemType>&) = 0;

};

#include "sort.cpp"
#endif