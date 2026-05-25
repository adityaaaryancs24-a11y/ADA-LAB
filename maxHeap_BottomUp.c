#include <stdio.h>

void bottomUpHeapify(int arr[], int n, int i)
{
    int temp = arr[i];
    int child = 2 * i + 1;

    while (child < n)
    {
        if (child + 1 < n && arr[child + 1] > arr[child])
            child++;

        if (arr[child] > temp)
        {
            arr[i] = arr[child];
            i = child;
            child = 2 * i + 1;
        }
        else
        {
            break;
        }
    }
    arr[i] = temp;
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        bottomUpHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        bottomUpHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}
