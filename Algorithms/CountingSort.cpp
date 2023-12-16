// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Counting Sort

#include <iostream>
using namespace std;

void CountingSort(int A[5], int B[5], int k, int A_length)
{
    int C[k];
    for (int i = 0; i <= k; i++)
    {
        C[i] = 0;
    }
    for (int i = 1; i <= A_length; i++)
    {
        C[A[i]] = C[A[i]] + 1;
    }
    cout << "\nThe array C: \n";
    for (int i = 0; i <= k; i++)
    {
        cout << C[i] << " ";
    }
    for (int i = 1; i <= k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    cout << "\nThe array C: \n";
    for (int i = 0; i <= k; i++)
    {
        cout << C[i] << " ";
    }
    for (int i = A_length; i > 0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
    cout << "\nSorted Array: \n";
    for (int i = 1; i <= A_length; i++)
    {
        cout << B[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements to be in array: ";
    cin >> n;
    int A[n];
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter element A[" << i << "]: ";
        cin >> A[i];
    }
    int B[n];
    for (int i = 1; i <= n; i++)
    {
        B[i] = 0;
    }
    int max = A[0];
    for (int i = 2; i <= n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    cout << "k is: " << max;
    int k = max;
    CountingSort(A, B, k, n);
    return 0;
}