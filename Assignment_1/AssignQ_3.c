#include<stdio.h>
 
int binarySearchDescending(int arr[],int n, int key)
{
    int low = 0, high = n - 1;
    while (low<= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main(){
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);
    int result = binarySearchDescending(arr, n, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");
    return 0;
}