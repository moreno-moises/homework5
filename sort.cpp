template<class ItemType> 
Sort<ItemType>::Sort(): swaps(0), comparisons(0){}

template<class ItemType> 
int Sort<ItemType>::getSwaps(){
    return swaps;
}

template<class ItemType> 
int Sort<ItemType>::getComparisons(){
    return comparisons;
}

template<class ItemType> 
std::chrono::milliseconds Sort<ItemType>::getRunTime(){

    return runTime;
}