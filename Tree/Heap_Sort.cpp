#include<bits/stdc++.h>
using namespace std;

//swap

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// To add a new node to a heaped tree

void Heapify(int i, int *array,int heapsize) {
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l< heapsize&&array[l]>array[i]){
        largest = l;
    }
    if(r<heapsize&&array[r]>array[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(&array[largest],&array[i]);
        Heapify(largest,array,heapsize);
    }
}


// HeapSort

void heapsort(int *array,int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        Heapify(i,array,n);
    }
    for(i=n-1;i>=0;i--){
        swap(&array[0],&array[i]);
        Heapify(0,array,i);
    }
}

int main(){

    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
 }