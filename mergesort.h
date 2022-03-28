#ifndef MERGE_H
#define MERGE_H


template <class ItemType>
class MergeSort{
protected:
    int swaps;
    int comparisons;
    std::chrono::milliseconds runTime;

public:
    MergeSort();

    void mergeSort(ArrayList<ItemType>& data, int left, int right);
    void merge(ArrayList<ItemType>& data, int begin, int mid, int end);

    int getSwaps();
    int getComparisons();
    std::chrono::milliseconds getRunTime();


};

#include "mergesort.cpp"
#endif
