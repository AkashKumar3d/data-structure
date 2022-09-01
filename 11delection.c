#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void intdeletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100] = {1, 2, 3, 45, 36};
    int size = 5, element = 65, index = 1;
    display(arr, size);
    intdeletion(arr, size, index);
    size -= 1;
    display(arr, size);
}