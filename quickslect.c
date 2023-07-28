#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void kthLargestAndSmallest(int arr[], int n, int k)
{
    sortArray(arr, n);

    printf("\nkth Largest element: %d\n", arr[n - k]);
    printf("kth Smallest element: %d\n", arr[k - 1]);
}

int main()
{
    int t;
    printf("Enter the Test Cases: ");
    scanf("%d",&t);
    while(t>0)
    {
        int n;
        printf("Enter the Array Size: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the Array elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int k;
        printf("Enter the value of k: ");
        scanf("%d", &k);
        kthLargestAndSmallest(arr, n, k);
        t--;
    }
    return 0;
}
