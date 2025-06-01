#include<stdio.h>

int findoccurrence(int arr[], int size, int element, int n)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            count++;
    if (count ==n)
    {
        return i;
    }
}
    }

    return -1;
}
int main()
{
int arr[] = {5,3,7,5,2,5,8,5,1};
int size = sizeof(arr) / sizeof(arr[0]);
int element, n;

printf("Enter the element to search: ");
scanf("%d", &element);
printf("Enter the occurrence number to find: ");
scanf("%d", &n);

int result = findoccurrence(arr, size, element, n);
if (result != -1) 
    printf("Element %d found at index %d\n", element, result);
else 
    printf("Element %d not found or does not occur %d times in the array\n", element, n);
    return 0;

}

