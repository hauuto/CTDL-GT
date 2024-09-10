//
// Created by thanh on 8/27/2024.
//


#include <stdio.h>
#define MAXN 100


void nhapMang(int a[], int size);
void xuatMang(int a[], int size);
void selectionSort(int a[], int n);
void swap(int &a, int &b);
void copyArray(int a[], int b[], int size);
void insertionSort(int a[], int size);
void interchangeSort(int a[], int size);
void bubbleSort(int a[], int size);
void quickSort(int a[], int left, int right);

int main(void){
    int choose;
    do{
        printf("Chon cac hanh dong sau\n");
        printf("0. Thoat khoi man hinh\n");
        printf("1. Nhap mang\n");
        printf("2. Xuat mang\n");
        printf("3. Selection Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Bubble Sort\n");
        printf("7. Interchange Sort\n");
        printf("Choose:");
        scanf("%d",&choose);

        switch(choose){
            case 1:
                int a[MAXN];
                int size_a;
                do{
                    printf("Nhap so phan tu mang:");scanf("%d",&size_a);
                    if (size_a < 0){
                        printf("Phan tu mang khong duoc nho hon 0\n");
                    }
                }while(size_a<0);
                nhapMang(a,size_a);
                printf("\n");
                break;
            case 2:
                xuatMang(a,size_a);
                break;
            case 3:
                int b[MAXN];
                copyArray(a,b,size_a);
                selectionSort(b,size_a);
                printf("Mang sau khi sort\n");
                xuatMang(b,size_a);
                break;
            case 4:
                int c[MAXN];
                copyArray(a,c,size_a);
                insertionSort(c,size_a);
                printf("Mang sau khi sort\n");
                xuatMang(c,size_a);
                break;
            case 5:
                int d[MAXN];
                copyArray(a,d,size_a);
                quickSort(d,0,size_a-1);
                xuatMang(d,size_a);
                break;
            case 6:
                int e[MAXN];
                copyArray(a,e,size_a);
                bubbleSort(e,size_a);
                xuatMang(e,size_a);
                break;
            case 7:
                int f[MAXN];
                copyArray(a,f,size_a);
                interchangeSort(f,size_a);
                xuatMang(f,size_a);
                break;

        }









    }while(choose != 0);
}




void nhapMang(int a[], int size){
    for (int i=0;i<size;++i){
        printf("Nhap phan tu %d:",i);
        scanf("%d",&a[i]);
        fflush(stdin);
    }
}

void xuatMang(int a[], int size){
    printf("Mang co %d phan tu\n",size);
    for (int i=0; i<size;++i){
        printf("%d\t",a[i]);
        if(i%10==0){
            printf("\n");
        }
    }
    printf("\n");
}

void selectionSort(int a[], int n){
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void copyArray(int a[], int b[], int size){
    for (int i=0;i<size;++i){
        b[i] = a[i];
    }
}

void insertionSort(int a[], int size){
    int i, j, last;

    for (i=1;i<size;++i){
        last = a[i];
        j=i;
        while((j>0)&&(a[j-1]>last)) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = last;
    }
}


void interchangeSort(int a[], int size){

    for (int i=0; i<size-1;i++){
        for (int j = i+1;j<size;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }

    }
}


void bubbleSort(int a[], int size){
    for (int i=0;i<size-1;++i){
        for (int j=size-1;j>i;--j){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }
}

void quickSort(int a[], int left, int right){
    int i, j, x;
    i = left;
    j = right;
    x = a[(left+right)/2];
    do{
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j) quickSort(a,left,j);
    if(i<right) quickSort(a,i,right);
}

