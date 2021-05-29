/*
Diana Palafox
02/13/2020
CSE 100 
LAB01
*/

#include <iostream>
#include <limits.h>
using namespace std;

/* Declaration*/
void merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);

/* User input*/
int main()
{

    int i, n; // n is the length
    cin >> n;
    int A[n];
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);
    /* User output*/
    for (i = 0; i < n; i++)
    {
        cout << A[i] << ";";
    }
    return 0;
}
/* Merge*/
void merge(int A[], int p, int q, int r)
{
    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];
    int i, j, k;

    for (i = 0; i < n1; i++)
    { // where the array is starts at 0
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }

    L[n1] = INT_MAX; // To create the infinity
    R[n2] = INT_MAX;

    i = 0; // where the array is starts at 0
    j = 0;
    for (k = p; k <= r; k++)
        if (L[i] <= R[j])
        {
            A[k] = L[i];

            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
}

/* Merge-Sort*/
void mergeSort(int A[], int p, int r)
{ // p is start inpoint and r is endpoint
    int q;

    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
