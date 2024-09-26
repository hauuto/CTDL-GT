//
// Created by thanh on 9/26/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include "Array.h"



//function prototypes
void inputArray(int arr[]);
void outputArray(int arr[]);
int arraySize(int arr[]);
void exportArray(char *filename, int arr[]);
void importArray(char *filename, int arr[]);
void randomArray(int arr[], int size, int min, int max);

//implementations
void inputArray(int arr[]){
    int i=0;
    do {
        printf("Array[%d]: ",i);
        scanf("%d",&arr[i]);
        fflush(stdin);
    }while(arr[i++]!=-1);
}

void outputArray(int arr[]){
    int i=0;
    while(arr[i]!=-1){
        printf("%d ",arr[i++]);
    }
    printf("\n");
}

int arraySize(int arr[]){
    int i=0;
    while(arr[i]!=-1){
        i++;
    }
    return i;
}

void exportArray(char *filename, int arr[]){
    FILE *file = fopen(filename,"w");
    if (file == NULL){
        printf("Cannot open file %s\n",filename);
        return;
    }
    for (int i=0; arr[i]!=-1; ++i){
        fprintf(file,"%d ",arr[i]);
    }
}

void importArray(char *filename, int arr[]){
    FILE *file = fopen(filename,"r");
    if (file == NULL){
        printf("Cannot open file %s\n",filename);
        return;
    }
    for (int i=0; arr[i] !=-1;++i){
        fscanf(file,"%d",&arr[i]);
    }
}

void randomArray(int arr[], int size, int min, int max){
    for (int i=0; i<size; ++i){
        arr[i] = rand() % (max-min+1) + min;
    }
    arr[size] = -1;
}