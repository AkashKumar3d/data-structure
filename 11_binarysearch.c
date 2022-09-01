#include <stdio.h>
int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int main()
{
    //binary search always apply the sorted array;

    int arr[] = {1, 3, 36, 25, 29, 46};
    int size = sizeof(arr) / sizeof(int);
    int element = 36;
    int searchindex = binarysearch(arr, size, element);
    printf("the element %d is found is index %d ", element, searchindex);
    return 0;
}