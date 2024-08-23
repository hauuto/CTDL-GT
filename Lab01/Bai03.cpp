//
// Created by thanh on 8/20/2024.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXN 100



void PhatSinhMangTang(int a[], int size, int max_number, int min_number);
int Binary_Search(int a[], int left,int right, int key);
void print_Search(int a[], int size, int key);

int main(void){
    int a[MAXN];
    int size_a;
    int max_key, min_key;
    int key;

    printf("Nhap so phan tu mang:"); scanf("%d",&size_a);
    printf("Nhap gia tri nho nhat co the phat sinh:"); scanf("%d",&min_key);
    printf("Nhap gia tri lon nhat co the phat sinh:"); scanf("%d",&max_key);
    printf("Nhap phan tu can tim kiem:");scanf("%d",&key);

    PhatSinhMangTang(a,size_a,max_key,min_key);

    print_Search(a,size_a,key);


}

void PhatSinhMangTang(int a[], int size, int max_number, int min_number){
    srand(time(NULL));
    int random = rand() % (max_number - min_number +1) + min_number;
    a[0] = random;
    printf("Phat sinh lan %d: %d\n",0,a[0]);
    for (int i=1; i<size; ++i){
        int range = (max_number - a[i-1] > 0) ? rand() % (max_number - a[i-1] + 1) : 0;
        a[i] = a[i-1] + range%10;
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