//
// Created by thanh on 8/20/2024.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXN 100



void Nhap_Mang(int a[], int size);
void XuatMang(int a[], int size);
void PhatSinhMang(int a[], int size, int max_number, int min_number);
int Write_File(char* file_name, int a[], int size);
int Read_File(char* file_name, int a[]);

int main(void){
    int a[MAXN];
    int b[MAXN];
    int size_a, size_b;
    int max_key, min_key;
    printf("Hay nhap so phan tu cua mang a:"); scanf("%d",&size_a);

    Nhap_Mang(a,size_a);
    XuatMang(a,size_a);

    printf("Hay nhap so phan tu cua mang b:"); scanf("%d",&size_b);
    printf("Nhap gia tri nho nhat co the phat sinh: "); scanf("%d",&min_key);
    printf("Nhap gia tri lon nhat co the phat sinh: "); scanf("%d",&max_key);
    PhatSinhMang(b,size_b,max_key, min_key);


    char* ten_file = "Bai1_output.txt";
    if(Write_File(ten_file,b,size_b)){
        printf("Ghi ra file thanh cong\n");
    }else{
        printf("Ghi ra file khong thanh cong\n");
    }

    int c[MAXN];
    int size_c;

    char* ten_file_read = "Bai1_input.txt";
    if (Read_File(ten_file_read, c) == 0){
        printf("Doc file khong thanh cong\n");
    }else{
        printf("Doc file thanh cong\n");
        size_c = Read_File(ten_file_read, c)-1;
        XuatMang(c,size_c);
    }

}


void Nhap_Mang(int a[], int size){
    printf("Cac phan tu cua mang:\n");
    for (int i=0; i<size; ++i){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
}


void XuatMang(int a[], int size){
    printf("Mang co %d phan tu\n",size);
    for (int i=0; i<size; ++i){
        printf("Phantu[%d]: %d\n",i,a[i]);
    }
}

void PhatSinhMang(int a[], int size, int max_number, int min_number){
    srand(time(NULL));
    for (int i=0; i<size; ++i){
        a[i] = rand() % (max_number - min_number +1) + min_number;
        printf("Phat sinh lan %d: %d\n",i,a[i]);
    }
}

int Write_File(char* file_name, int a[], int size){
    FILE* f = fopen(file_name,"w");
    if (f == NULL){
        printf("Mo file that bai");
        return 0;
    }
    fprintf(f,"So phan tu trong mang: %d\n",size);
    for (int i = 0; i<size;++i){
        fprintf(f,"%d\t",a[i]);

    }
    fclose(f);
    return 1;
}

int Read_File(char* file_name, int a[]){
    FILE* f = fopen(file_name,"r");
    if (f == NULL){
        printf("Mo file khong thanh cong\n");
        return 0;
    }
    int i =0;
    while (!feof(f)){ // feof = file-end of file
        fscanf(f,"%d",&a[i]);
        ++i;

    }
    return i;
}