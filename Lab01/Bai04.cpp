//
// Created by thanh on 8/23/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start,end;

#define MAXN 100001


void PhatSinhMang(int a[], int size);
int Linear_Search(int a[], int size, int key);
void print_Linear_Search(int a[], int size, int key);

void PhatSinhMangTang(int a[], int size);
int Binary_Search(int a[], int size, int key);
void print_Search(int a[], int size, int key);


int main(void){

    int a[MAXN];
    int b[MAXN];
    int size,key;

    printf("Nhap kich thuoc mang:");scanf("%d",&size);
    printf("Nhap key can tim");scanf("%d",&key);
/*
    PhatSinhMang(a,size);
    start = clock();
    print_Linear_Search(a,size,key);
    end = clock();
    double time = end - start;
    printf("\nThoi gian Linear: %f",time); */


    PhatSinhMangTang(b,size);
    start = clock();
    print_Search(b,size,key);
    end = clock();
    double time = end - start;
    printf("\nThoi gian Binary: %f",time);


}


void PhatSinhMang(int a[], int size){
    srand(time(NULL));
    for (int i=0; i<size; ++i){
        a[i] = rand();
        printf("Phat sinh lan %d: %d\n",i,a[i]);
    }
}

int Linear_Search(int a[], int size, int key){
    int i = 0;
    a[size] = key;
    while (a[i]!=key){
        ++i;
    }
    if (i<size){
        return i;
    }
    return -1;
}

void print_Linear_Search(int a[], int size, int key){
    int temp = Linear_Search(a,size,key);
    if ( temp == -1){
        printf("Khong tim thay phan tu");
    }else{
        printf("Phan tu tim thay tai vi tri: %d",temp);
    }
}

void PhatSinhMangTang(int a[], int size){
    srand(time(NULL));
    a[0] = rand() % 100;
    printf("Phat sinh lan %d: %d\n",0,a[0]);
    for (int i=1; i<size; ++i){
        a[i] = a[i-1] + rand()%10;
        printf("Phat sinh lan %d: %d\n",i,a[i]);
    }
}

int Binary_Search(int a[], int left,int right, int key){
    if (left>right) return -1;
    int mid = (left + right)/2;
    if (a[mid]==key){
        return mid;
    }else if (a[mid]<key){
        return Binary_Search(a,left,mid-1,key);
    }else if (a[mid]>key){
        return Binary_Search(a,mid+1,right,key);
    }
    return -1;
}

void print_Search(int a[], int size, int key){
    int temp = Binary_Search(a,0,size-1,key);
    if (temp == -1){
        printf("Khong tim thay phan tu");
    }else{
        printf("Phan tu tim thay tai vi tri: %d",temp);
    }
}