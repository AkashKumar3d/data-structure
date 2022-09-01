#include <stdio.h>
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void insertionshort(int *a, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int a[] = {12, 3, 6, 9, 5};
    int n = 5;
    printarr(a, n);
    insertionshort(a, n);
    printarr(a, n);
    return 0;
}
// -1   0    1   2   3   4   
//      12 , | 3 ,  6 ,  9 ,  5 -->i=1,key=3 ,j=0
//       3,  |12 ,  6  , 9 ,  5-->1st  pass complete

//       3,   12 ,  |6  , 9 ,  5-->i=2,key=6,j=1
//       3,    6 ,  |12  , 9 ,  5-->2nd pass complete

//       3,    6 ,  12 | , 9 ,  5-->i=3,key=9,j=2
//       3,    6 ,  9 |, 12 ,  5-->3rd pass is complete

//       3,    6 ,  9 , 12 |,  5-->i=4,key=5,j=3
//       3,    6 ,  9 , 12 |,  12-->i=4,key=5,j=2
//       3,    6 ,  9 , 9  |,  12-->i=4,key=5,j=1
//       3,    6 ,  6 , 9  |,  12-->i=4,key=5,j=0;
//       3,    5 ,  6 , 9  |,  12-->i=4,key=5,j=-1
//       3,    5 ,  6 , 9  |,  12-->i=4,key=5,j=-1-->4th pass is done

