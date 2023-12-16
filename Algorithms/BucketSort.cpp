// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Bucket Sort

#include <iostream>
#include <list>
using namespace std;

void display(list<float> &L)
{
    list<float>::iterator it;
    for (it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
}

void BucketSort(float A[], int n)
{
    list<float> B[n];
    for (int i = 0; i < n; i++)
    {
        int d = n * A[i];
        B[d].push_back(A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        B[i].sort();
        display(B[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    float A[n];
    cout << "\nEnter the elements of array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << " : ";
        cin >> A[i];
    }
    cout << "\nThe sorted array is: \n";
    BucketSort(A, n);
    return 0;
}
