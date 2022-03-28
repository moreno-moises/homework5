#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "arraylist.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "mergesort.h"


void generateRandomValues(int, ArrayList<int>&);
void runSort(string, Sort<int>*, ArrayList<int>&);
void runMergeSort(string, MergeSort<int>*, ArrayList<int>&, int);


int main(){

    ArrayList<int> random1000;
    ArrayList<int> random10000;
    ArrayList<int> random100000;
    int n;

    generateRandomValues(1000, random1000);
    generateRandomValues(10000, random10000);
    generateRandomValues(100000, random100000);

    cout << "insertion sort" << endl;
    InsertionSort<int> insertionSort;
    runSort("Insertion1000", &insertionSort, random1000);
    runSort("Insertion10000", &insertionSort, random10000);
    runSort("Insertion100000", &insertionSort, random100000);

    cout << "selection sort" << endl;
    SelectionSort<int> selectionSort;
    runSort("Selection1000", &selectionSort, random1000);
    runSort("Selection10000", &selectionSort, random10000);
    runSort("Selection100000", &selectionSort, random100000);

    
    cout << "merge sort" << endl;
    MergeSort<int> mergeSort;
    runMergeSort("Merge1000", &mergeSort, random1000, n);
    runMergeSort("Merge10000", &mergeSort, random10000, n);
    runMergeSort("Merge100000", &mergeSort, random100000, n);
    

    return 0;

}

//sort type = filename 
void runSort(string sortType, Sort<int>* sort, ArrayList<int>& random){
    ofstream outfile;
    outfile.open("output/" + sortType + ".csv");
    outfile << "Run Time, Comparisons, Swaps" << endl;
    ArrayList<int> sorted = random;
    for(int i = 0; i < 10; i++){ //runs for 10 times
        sorted = random;
        // sort random
        sort->sort(sorted);
        outfile << sort->getRunTime().count() << ", " << sort->getComparisons() << ", " << sort->getSwaps() << endl;
    }
    outfile << "Sorted" << endl;
    for(int i = 0; i < 10; i++){
        // sort sorted
        sort->sort(sorted);
        outfile << sort->getRunTime().count() << ", " << sort->getComparisons() << ", " << sort->getSwaps() << endl;
    }

    outfile.close();
}

void runMergeSort(string sortType, MergeSort<int>* sort, ArrayList<int>& random, int n){
    ofstream outfile;
    outfile.open("output/" + sortType + ".csv");
    outfile << "Run Time, Comparisons, Swaps" << endl;
    ArrayList<int> sorted = random;
    for(int i = 0; i < 10; i++){ //runs for 10 times
        sorted = random;
        // sort random
        sort->mergeSort(sorted,0,n);
        outfile << sort->getRunTime().count() << ", " << sort->getComparisons() << ", " << sort->getSwaps() << endl;
    }
    outfile << "Sorted" << endl;
    for(int i = 0; i < 10; i++){
        // sort sorted
        sort->mergeSort(sorted,0,n);
        outfile << sort->getRunTime().count() << ", " << sort->getComparisons() << ", " << sort->getSwaps() << endl;
    }

    outfile.close();
}

void generateRandomValues(int numValues, ArrayList<int>& data){
    srand (time(NULL));
    for(int i = 1; i <= numValues; i++){
        data.insert(i, rand() % 1000000 + 1);
    }
}




/*
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[1000000]);

    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    printArray(arr, n);

    return 0;
}

/*
int main()
{

    int arr[] = {1000,10000,100000};
    int n = sizeof(arr)/sizeof(arr[0]);

    auto start = high_resolution_clock::now();
    selectionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    cout << "selection sort: \n";

    printArray(arr, n);

    insertionSort(arr, n);

    cout << "insertion sort: \n";

    printArray(arr, n); 

    return 0;

}
*/
