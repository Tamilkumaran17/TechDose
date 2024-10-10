#include <stdio.h>
#define n 5
int arr[n];

void quick_sort(int arr[], int first, int last)
{
    if (first < last)
    {
        int pivot, i, j, temp;
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (arr[pivot] >= arr[i] && i < last)
                i++;
            while (arr[pivot] < arr[j])
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        
        quick_sort(arr, first, j - 1);
        quick_sort(arr, j + 1, last);
    }
}


int main()
{

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quick_sort(arr, 0, n - 1);
    for (int i = 0; i <= n - 1; i++)
        printf("%d ", arr[i]);
    return 0;
}
