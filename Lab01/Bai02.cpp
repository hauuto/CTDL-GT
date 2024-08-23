//
// Created by thanh on 8/20/2024.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXN 100



void PhatSinhMang(int a[], int size, int max_number, int min_number);
int Linear_Search(int a[], int size, int key);
void print_Linear_Search(int a[], int size, int key);

int main(void){
    int a[MAXN];
    int size_a;
    int max_key, min_key;
    int key;

    printf("Nhap so phan tu mang:"); scanf("%d",&size_a);
    printf("Nhap gia tri nho nhat co the phat sinh:"); scanf("%d",&min_key);
    printf("Nhap gia tri lon nhat co the phat sinh:"); scanf("%d",&max_key);
    printf("Nhap phan tu can tim kiem:");scanf("%d",&key);

    PhatSinhMang(a,size_a,max_key,min_key);

    print_Linear_Search(a,size_a,key);


}

void PhatSinhMang(int a[], int size, int max_number, int min_number){
    srand(time(NULL));
    for (int i=0; i<size; ++i){
        a[i] = rand() % (max_number - min_number +1) + min_number;
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