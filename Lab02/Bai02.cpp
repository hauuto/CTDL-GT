//
// Created by thanh on 9/2/2024.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXN 50000

int countCompare = 0;
long long countSwap = 0;

void phatsinhMang();
void selectionSort(int a[], int n);
void swap(int &a, int &b);
void copyArray(int a[], int b[], int size);
void insertionSort(int a[], int size);
void interchangeSort(int a[], int size);
void bubbleSort(int a[], int size);
void quickSort(int a[], int left, int right);
void toString(float a, int b, long long c, char* name, int number);

int main(void){
    FILE *f = fopen("report.txt", "w");
    fclose(f);
    phatsinhMang();
    int a[6][50001];
    int choose;
    do {
        printf("Chon cac hanh dong sau\n");
        printf("1. Xem thoi gian chay Selection Sort\n");
        printf("2. Xem thoi gian chay Insertion Sort\n");
        printf("3. Xem thoi gian chay Bubble Sort\n");
        printf("4. Xem thoi gian chay Interchange Sort\n");
        printf("5. Xem thoi gian chay Quick Sort\n");
        printf("0. Thoat khoi chuong trinh\n");
        printf("Choose: ");
        scanf("%d", &choose);



        for (int i = 1; i<=5;++i){
            char filename[20];
            sprintf(filename, "mang%d.int", i);
            FILE *g = fopen(filename, "r");
            int n;
            fscanf(g, "%d", &n);
            for (int j = 1; j<=n;++j){
                fscanf(g, "%d", &a[i][j]);
            }
            fclose(g);
        }
        switch(choose){
            case 1:
                fprintf(f,"Selection Sort\n");
                for (int i = 1; i<=5;++i){
                    countCompare = 0;
                    countSwap = 0;
                    clock_t start = clock();
                    int size = 50000;
                    selectionSort(a[i], size);
                    clock_t end = clock();
                    float time_run = (double)(end-start);
                    toString(time_run, countCompare, countSwap, "Selection Sort", i);

                }
                break;
            case 2:
                fprintf(f,"Insertion Sort\n");

                for (int i = 1; i<=5;++i){

                    countCompare = 0;
                    countSwap = 0;
                    clock_t start = clock();
                    int size = 50000;
                    insertionSort(a[i], size);
                    clock_t end = clock();
                    float time_run = (double)(end-start);
                    toString(time_run, countCompare, countSwap, "Insertion Sort", i);
                }

                break;
            case 3:
                fprintf(f,"Bubble Sort\n");
                for (int i = 1; i<=5;++i){
                    countCompare = 0;
                    countSwap = 0;
                    clock_t start = clock();
                    int size = 50000;
                    bubbleSort(a[i], size);
                    clock_t end = clock();
                    float time_run = (double)(end-start);
                    toString(time_run, countCompare, countSwap, "Bubble Sort", i);

                }
                break;
            case 4:
                fprintf(f,"Interchange Sort\n");
                for (int i = 1; i<=5;++i){
                    countCompare = 0;
                    countSwap = 0;
                    clock_t start = clock();
                    int size = 50000;
                    interchangeSort(a[i], size);
                    clock_t end = clock();
                    float time_run = (double)(end-start);
                    toString(time_run, countCompare, countSwap, "Interchange Sort", i);
                }
                break;
            case 5:
                fprintf(f,"Quick Sort\n");
                for (int i = 1; i<=5;++i){
                    countCompare = 0;
                    countSwap = 0;
                    clock_t start = clock();
                    int size = 50000;
                    quickSort(a[i], 1, size);
                    clock_t end = clock();
                    float time_run = (double)(end-start);
                    toString(time_run, countCompare, countSwap, "Quick Sort", i);

                }
                break;
            case 0:
                printf("Thoat khoi chuong trinh\n");
                break;
        }

    }while(choose !=0);

}

void phatsinhMang(){
    srand(time(NULL));
    for (int i = 1; i <= 5; i++){
        char filename[20];
        sprintf(filename, "mang%d.int", i);
        FILE *f = fopen(filename, "w");
        int n = MAXN + 1;
        fprintf(f, "%d\n", n);
        for (int j = 1; j <= n; j++){
            fprintf(f, "%d ", rand());
        }
        fclose(f);
    }
}
void selectionSort(int a[], int n){
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (a[j] < a[min]) {
                min = j;
                countCompare++;
            };
        }
        swap(a[i], a[min]);
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    countSwap++;
}

void copyArray(int a[], int b[], int size){
    for (int i=0;i<size;++i){
        b[i] = a[i];
    }
}

void insertionSort(int a[], int size){
    for (int i=1;i<size;++i){
        int x = a[i];
        int pos = i-1;
        while(pos>=0 && a[pos]>x){
            a[pos+1] = a[pos];
            pos--;
            countCompare++;
            countSwap++;
        }
        a[pos+1] = x;
    }
}



void interchangeSort(int a[], int size){

    for (int i=0; i<size-1;i++){
        for (int j = i+1;j<size;j++){
            if(a[i]>a[j]){
                countCompare++;
                swap(a[i],a[j]);
            }
        }

    }
}


void bubbleSort(int a[], int size){
    for (int i=0;i<size-1;++i){
        for (int j=size-1;j>i;--j){
            if(a[j]<a[j-1]){
                countCompare++;
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
            countCompare++;
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j){
        quickSort(a,left,j);
        countCompare++;
    };
    if(i<right) {
        quickSort(a,i,right);
        countCompare++;
    };
}

//make toString function print out to the file name report.txt
void toString(float a, int b, long long c, char* name, int number){
    FILE *f = fopen("report.txt", "a");
    fprintf(f,"Mang %d: ", number);
    fprintf(f, "%f\t", a);
    fprintf(f, "%d\t", b);
    fprintf(f, "%lld\n", c);
    fclose(f);
    printf("Done\n");
    printf("\n");
}
