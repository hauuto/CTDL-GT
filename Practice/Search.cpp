//
// Created by thanh on 9/26/2024.
//

#include <stdio.h>
#include <Search.h>


//function prototypes
int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int size, int key);



//implementations
int linearSearch(int arr[], int size, int key){
    for (int i =0; i<size;++i){
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key){
    int left = 0;
    int right = size-1;
    while (left<=right){
        int mid = (right+left)/2;
        if (arr[mid] == key){
            return mid;
        }
        if (arr[mid]<key){
            left = mid+1;
        } else{
            right = mid-1;
        }
    }
    return -1;
}


