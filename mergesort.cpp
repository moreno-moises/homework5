template<class ItemType> 
MergeSort<ItemType>::MergeSort(){}

template<class ItemType> 
int MergeSort<ItemType>::getSwaps(){
    return swaps;
}

template<class ItemType> 
int MergeSort<ItemType>::getComparisons(){
    return comparisons;
}

template<class ItemType> 
std::chrono::milliseconds MergeSort<ItemType>::getRunTime(){

    return runTime;
}

template<class ItemType>
void MergeSort<ItemType>::mergeSort(ArrayList<ItemType>& data, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(data, left, right);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }

}

template<class ItemType>
void MergeSort<ItemType>::merge(ArrayList<ItemType>& arr, int low, int mid, int high){
    int i, j, k;
    int len1 = mid - low + 1;
    int len2 = high - mid;
    int left[len1], right[len2];
    int arr1[k];

    for (i = 0; i < len1; i++)
    left[i] = arr1[low + i];
    for (j = 0; j < len2; j++)
    right[j] = arr1[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr1[k] = left[i];
            i++;
        }
        else {
            arr1[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr1[k] = left[i];
        i++;
        k++;
    }


    while (j < len2) {
        arr1[k] = right[j];
        j++;
        k++;
    }


}

