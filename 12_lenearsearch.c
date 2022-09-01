#include <stdio.h>
int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
        }
}
int main()
{
    int arr[100] = {1, 3, 36, 25, 29, 46};
    int size = sizeof(arr) / sizeof(int);
    int element = 46;
    int searchindex = linearsearch(arr, size, element);
    printf("the element %d is found is index %d ", element, searchindex);
    return 0;
}