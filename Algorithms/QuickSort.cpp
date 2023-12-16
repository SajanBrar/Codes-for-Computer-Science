// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Quick Sort

#include <iostream>
using namespace std;

int Partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    int temp1, temp2;
    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            temp1 = A[i];
            A[i] = A[j];
            A[j] = temp1;
        }
        cout << "\n";
        for (int k = p; k <= r; k++)
        {
            cout << A[k] << " ";
        }
    }
    cout << "\nPivot: " << A[r];
    cout << "\nBefore swapping pivot: ";
    for (int k = p; k <= r; k++)
    {
        cout << A[k] << " ";
    }
    temp2 = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp2;
    cout << "\nAfter Partition: ";
    for (int k = p; k <= r; k++)
    {
        cout << A[k] << " ";
    }
    return i + 1;
}

void QuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
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
    QuickSort(A, 0, n - 1);
    cout << "\nThe sorted array is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}