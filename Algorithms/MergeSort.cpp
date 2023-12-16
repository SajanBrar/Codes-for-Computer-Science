// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Merge Sort

#include <iostream>
using namespace std;

void Merge(int A[], int p, int q, int r)
{
    int i, j;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    for (int i = 1; i <= n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (int j = 1; j <= n2; j++)
    {
        R[j] = A[q + j];
    }
    L[n1 + 1] = 1000;
    R[n2 + 1] = 1000;
    cout << "\nLeft subarray:\n";
    for (int i = 1; i <= n1; i++)
    {
        cout << L[i] << " ";
    }
    cout << "\nRight subarray:\n";
    for (int i = 1; i <= n2; i++)
    {
        cout << R[i] << " ";
    }

    i = 1;
    j = 1;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j] && L[i] != 1000)
        {
            A[k] = L[i];
            i = i + 1;
        }
        else if (L[i] > R[j] && R[j] != 1000)
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
    cout << "\nIn Merge: ";
    for (int i = p; i <= r; i++)
    {
        cout << A[i] << " ";
    }
}

void MergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = ((p + r) / 2);
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int A[n];
    cout << "\nEnter the elements of array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << " : ";
        cin >> A[i];
    }
    MergeSort(A, 0, n - 1);
    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}