#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int a[100];
    int n, i, ch;
    while (ch != 5)
    {
        printf("\nMenu\n");
        printf("\n1.Selection Sort\n");
        printf("\n2.Bubble Sort\n");
        printf("\n3.Quick Sort\n");
        printf("\n4.Heap Sort\n");
        printf("\n5.EXIT\n");
        printf("\n Select choice : ");
        scanf("%d", &ch);
        int i;
        if (ch != 5)
        {
            printf("\n Enter the Number of elements to Sort (MAX=100) ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\n Enter the element number %d : ", i + 1);
                scanf("%d", &a[i]);
            }
        }
        switch (ch)
        {
        case 1:
            selectionSort(a, n);

            break;
        case 2:
            bubbleSort(a, n);

            break;
        case 3:
            quickSort(a, 0, n - 1);

            break;
        case 4:
            heapSort(a, n);

            break;
        case 5:
            printf("\nExiting the code ....");
            exit(0);
            break;
        default:
            printf("\n Incorrect choice please choose the correct one (1-5)");
        }
        printf("\nSorted array: ");
        printArray(a, n);
    }
    return 0;
}
