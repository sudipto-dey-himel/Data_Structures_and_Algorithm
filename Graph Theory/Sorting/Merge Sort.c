#include <stdio.h>

void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
}

int main()
{
    int n;
    printf("Enter the number of elements ::  ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements :: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);
    printf("Sorted Array ::  ");
    print(a, n);
}
