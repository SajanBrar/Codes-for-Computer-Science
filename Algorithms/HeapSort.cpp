// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Heap Sort

#include <iostream>
using namespace std;

int length, heaplength;

int Parent(int i)
{
    return (i / 2);
}
int Left(int i)
{
    return (2 * i);
}
int Right(int i)
{
    return ((2 * i) + 1);
}

void MaxHeapify(int A[], int i)
{
    int largest;
    int l = Left(i);
    int r = Right(i);
    if (l < heaplength && A[l] > A[i])
    {
        largest = l;
    }
    else
        largest = i;
    if (r <= heaplength && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp;
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, largest);
    }
}

void BuildMaxHeap(int A[])
{
    heaplength = length;
    for (int i = (length / 2); i >= 1; i--)
    {
        MaxHeapify(A, i);
    }
}

void HeapSort(int A[])
{
    BuildMaxHeap(A);
    cout << "After building max heap: ";
    for (int i = 1; i <= length; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i = length; i >= 2; i--)
    {
        int temp;
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heaplength = heaplength - 1;
        MaxHeapify(A, 1);
        for (int i = 1; i <= length; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cout << "\nEnter array length: ";
    cin >> length;
    heaplength = length;
    int A[length];
    cout << "\nEnter the elements of array:\n";
    for (int i = 1; i <= length; i++)
    {
        cout << "Element " << i << " :";
        cin >> A[i];
    }
    HeapSort(A);
    cout << "\nThe sorted array is: ";
    for (int i = 1; i <= length; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}