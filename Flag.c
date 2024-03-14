#include <stdio.h>
int main() {
    // int arr[] = {1, -1, 2, 10, 123, 101}; 
    int arr[] = {10, 8, 6, 4, 2, 1}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int flag = 0;
    // Bubble Sort
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(arr[i] > arr[j]) {
                flag = 1;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        if(flag == 0) {
            break;
        }
    }

    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}