#include <stdio.h>
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void bubbleshort(int *a, int n)
{
    int issorted = 0;
    for (int i = 0; i < n - 1; i++) //no of pass
    {
        printf("no of in sorting array %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // camparion of each pass
        {
            if (a[j] > a[j + 1])
            {
                //swaping logic
                int c = a[j];
                a[j] = a[j + 1];
                a[j + 1] = c;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}
int main()
{
    int a[] = {12, 2, 36, 445, 15};
    //int a[] = {1, 2, 3, 4, 5};adoptive array
    int n = 5;
    printarr(a, n);
    bubbleshort(a, n);
    printarr(a, n);
    return 0;
}