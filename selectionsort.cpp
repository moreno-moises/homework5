template<class ItemType> 
SelectionSort<ItemType>::SelectionSort(){}


template<class ItemType>
void SelectionSort<ItemType>::sort(ArrayList<ItemType>& data){
    this->swaps = 0;
    this->comparisons = 0;

    auto begin = std::chrono::high_resolution_clock::now();

    int size = data.getLength();

    for(int i = 1; 1 <= size; i++){
        int smallInd = i;
        for(int j = i+1; j <= size; j++){
        this->comparisons++;
        if(data.getEntry(j) < data.getEntry(smallInd)){
            smallInd = j;
        }
    }
    ItemType old = data.getEntry(i);
    ItemType smallest = data.getEntry(smallInd);
    data.replace(i, smallest);
    data.replace(smallInd,old);
    this->swaps++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    this->runTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
}



/*
#include <bits/stdc++.h>

using namespace std;

void swap(int *xp, int *yp)
{

    int temp = *xp;

    *xp = *yp;

    *yp = temp;

}

void selectionSort(int arr[], int n)
{

    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;

        for (j = i+1; j < n; j++)

        if (arr[j] < arr[min_idx])

        min_idx = j;

        swap(&arr[min_idx], &arr[i]);

    }

}
*/
