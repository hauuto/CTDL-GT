//
// Created by thanh on 8/20/2024.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXN 100



void PhatSinhMang(int a[], int size);
void XuatMang(int a[],int size);
int Linear_Search(int a[], int size, int key);

int main(void){
    int a[MAXN];
    int size_a;
    printf("Nhap so phan tu mang: "); scanf("%d",&size_a);
    PhatSinhMang(a,size_a);
    XuatMang(a,size_a);
    int find_element = Linear_Search(a,size_a,20);

    if (find_element == -1){
        printf("Khong tim thay phan tu");
    }else {
        printf("Phan tu can tim o vi tri %d",find_element);
    }

}

void PhatSinhMang(int a[], int size){
    srand(time(NULL));
    for (int i=0; i<size; ++i){
        a[i] = rand() % 101;
    }
}
void XuatMang(int a[], int size){
    printf("Mang co %d phan tu:\n",size);
    for (int i=0; i<size; ++i){
        printf("%d\t",a[i]);
    }
}

int Linear_Search(int a[], int size, int key){
    int x = a[size];
    int i =0;
    while (a[i]!=key){
        ++i;
    }
    if (i<size){
        return i;
    }
    return -1;
}