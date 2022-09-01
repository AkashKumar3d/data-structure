#include <stdio.h>

void printarr(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void selectionshort(int *a, int n)
{
    printf("after the selectionshort te element :\n");
    int index_min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        index_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index_min])
            {
                index_min = j;
            }
        }
        temp = a[i];
        a[i] = a[index_min];
        a[index_min] = temp;
    }
}
int main()
{
    // 5, 6, 4, 3, 7
//0th  pass
// |5, 6, 4, 3, 7

// 1nd pass
// 3,|6, 4, 5, 7

// 2rd pass
// 3,5,|4, 6, 7

// 3th pass
// 3,5,4,|6, 7

// 4th pass
// 3,5,4,6,| 7

// after forth pass algorithm is shorted;

    int a[] = {5, 6, 4, 3, 7};
    int n = 5;
    printarr(a, n);
    selectionshort(a, n);
    printarr(a, n);

    return 0;
}