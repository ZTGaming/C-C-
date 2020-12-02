// C program to implement recursive Binary Search
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void)
{
    int a[100];
    int n, x, i;
    printf("\n Enter the Number of elements to Sort (MAX=100) ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the element number %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n Enter the element to be searched ");
    scanf("%d", &x);
    int result = binarySearch(a, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);
    return 0;
}
