#include<stdio.h>
 

int main()
{
    int arr[] = { 6,7,8,9,10,11,12,13,2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int key = 2;
    int index = linear_search(arr,n,key);
    if(index != -1){
printf("Last occurance of %d is at index %d\n", key,index);
}
else {
    printf("%d not found in the array\n", key);
}
return 0;
}

int linear_search(int arr[], int n, int key)
{
    int lastindex = -1;
    for(int i =0; i < n; i++)
    {
        if(arr[i] == key)
        {
            lastindex = i;
        }
    }
    return lastindex;
}