#include "iostream"
using namespace std;

//heapify
void heapify(int arr[], int n, int root){
    int largest = root; // root is the larget element
    int l = 2*root + 1; // left 
    int r = 2*root + 2; // right

    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // if right child is larget thatn root
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not root
    if (largest != root)
    {
        swap(arr[root] , arr[largest]); //swap root and largest
        heapify(arr, n, largest);       //recursively call heapify function

    }
    
    
}

//heap sort
void heapSort(int arr[], int n){
    //build heap
    for (int i = (n/2) - 1; i >= 0; i--)
    {
        heapify(arr,n ,i);
    }

    //extracting elements from heap one by one
    for (int i = n - 1 ; i >= 0; i--)
    {
        //Move current root to end
        swap(arr[0] , arr[i]);
        //again call max heapifu on the reduced heap
        heapify(arr, i, 0);

    }
    
    
}
//display array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }
    
}


int main(int argc, const char** argv) {
    int heap_arr[] = {4,17,3,12,9,6};
    int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
    cout << "n: " << n << endl;

    cout << "Input array: " << endl;
    displayArray(heap_arr, n);
    

    heapSort(heap_arr, n);

    cout << "Sorted array" << endl;
    displayArray(heap_arr, n);



    return 0;
}