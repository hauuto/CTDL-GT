//
// Created by thanh on 9/10/2024.
//
#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh dùng để sắp xếp tăng dần
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Hàm so sánh dùng để sắp xếp giảm dần
int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Hàm so sánh giá trị tuyệt đối
int compare_abs(const void *a, const void *b) {
    return abs(*(int *)a) - abs(*(int *)b);
}

// Hàm kiểm tra số chẵn
int is_even(int n) {
    return n % 2 == 0;
}

// Hàm kiểm tra số lẻ
int is_odd(int n) {
    return n % 2 != 0;
}

int main() {
    int A[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    int n = sizeof(A) / sizeof(A[0]);

    // 1. Sắp xếp dãy tăng dần
    qsort(A, n, sizeof(int), compare);
    printf("1. Day sap xep tang dan: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    // 2. Suy ra số lớn thứ 3 trong dãy
    printf("2. So lon thu 3: %d\n", A[n-3]);

    // 3. Số lượng phần tử lớn nhất (số lớn nhất là A[n-1])
    int max_count = 0, max_value = A[n-1];
    for (int i = 0; i < n; i++) {
        if (A[i] == max_value) max_count++;
    }
    printf("3. So luong phan tu lon nhat: %d\n", max_count);

    // 4. Sắp xếp theo giá trị tuyệt đối tăng dần
    qsort(A, n, sizeof(int), compare_abs);
    printf("4. Day sap xep theo gia tri tuyet doi tang dan: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    // 5. Sắp xếp số dương giảm dần, số âm tăng dần
    int pos[n], neg[n], pos_count = 0, neg_count = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) pos[pos_count++] = A[i];
        else if (A[i] < 0) neg[neg_count++] = A[i];
    }
    qsort(pos, pos_count, sizeof(int), compare_desc); // Số dương giảm dần
    qsort(neg, neg_count, sizeof(int), compare);      // Số âm tăng dần
    printf("5. Day theo quy luat duong giam dan, am tang dan: ");
    for (int i = 0; i < pos_count; i++) printf("%d ", pos[i]);
    for (int i = 0; i < neg_count; i++) printf("%d ", neg[i]);
    printf("\n");

    // 6. Sắp xếp chẵn tăng dần, lẻ giảm dần
    int even[n], odd[n], even_count = 0, odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (is_even(A[i])) even[even_count++] = A[i];
        else if (is_odd(A[i])) odd[odd_count++] = A[i];
    }
    qsort(even, even_count, sizeof(int), compare);   // Số chẵn tăng dần
    qsort(odd, odd_count, sizeof(int), compare_desc);// Số lẻ giảm dần
    printf("6. Day theo quy luat chan tang dan, le giam dan: ");
    for (int i = 0; i < even_count; i++) printf("%d ", even[i]);
    for (int i = 0; i < odd_count; i++) printf("%d ", odd[i]);
    printf("\n");

    return 0;
}
