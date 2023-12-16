// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Selection Sort

#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}

void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
        cout << "\nArray in Iteration number: " << i+1 << " : ";
        printArray(A, n);
    }
}

int main()
{
    int n;
    cout << "Enter no. of elements in the array: ";
    cin >> n;
    int A[n];
    cout << "\nEnter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\nElement at " << i << ": ";
        cin >> A[i];
    }
    cout << "\nBefore selection sort, the array is: \n";
    printArray(A, n);
    selectionSort(A, n);
    cout << "\nAfter selection sort, the array is: \n";
    printArray(A, n);
    cout << "\nThe time complexity of selection sort is O(n*n)";
    return 0;
}