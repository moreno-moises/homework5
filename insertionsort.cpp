template<class ItemType>
InsertionSort<ItemType>::InsertionSort(){}

template<class ItemType>
void InsertionSort<ItemType>::sort(ArrayList<ItemType>& data){
    this->swaps = 0;
    this->comparisons = 0;

    auto begin = std::chrono::high_resolution_clock::now();
    int size = data.getLength();

    for(int i = 2; i <= size; i++){
        int j = i;
        while(j > 1 && data.getEntry(j) < data.getEntry(j-1)){
            ItemType old = data.getEntry(j);
            ItemType smallest = data.getEntry(j-1);
            data.replace(j, smallest);
            data.replace(j-1, old);

            this->swaps++;
            this->comparisons++;
            j--;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    this->runTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
}




/*
#include <bits/stdc++.h>
using namespace std;

/* Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i - 1;

       /* Move elements of arr[0..i-1], that are
       greater than key, to one position ahead
       of their current position 
       while (j >= 0 && arr[j] > key)
       {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i = 0; i < n; i++)
       cout << arr[i] << " ";
   cout << endl;
}
*/
