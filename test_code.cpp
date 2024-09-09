//
// Created by thanh on 9/3/2024.
//
#include <stdio.h>
#include <time.h>

time_t b1,b2,l1,l2;

void CompareLinearBinarySearch(int a[], int size, int key) {
    int flag = 0;
    // Linear Search
    l1 = time(NULL);
    for (int i = 0; i < size; ++i) {
        if (a[i] == key) {
            printf("%d\n", i);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("-1\n");
    }
    l2 = time(NULL);
    double total_l = l2-l1;

    // Binary Search
    flag = 0;
    b1 = time(NULL);
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == key) {
            flag = 1;
            printf("%d\n", mid);
            break;
        } else if (a[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (flag == 0) {
        printf("-1\n");
    }
    b2 = time(NULL);
    long long total_b = b2-b1;
    printf("Linear: %ld\n", total_l);
    printf("%ld\n",l1);
    printf("%ld\n",l2);
    printf("Binary: %ld\n", total_b);
    printf("%ld\n",b1);
    printf("%ld\n",b2);


    // Compare times
    if (total_b < total_l) {
        printf("Binary faster than Linear\n");
    } else if (total_b > total_l) {
        printf("Linear faster than Binary\n");
    } else {
        printf("Linear equal to Binary\n");
    }
}



int main() {
    int arr[] = {1,2,4,5,8,10,12,12,13,13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;

    CompareLinearBinarySearch(arr, n, x);

    return 0;
}
