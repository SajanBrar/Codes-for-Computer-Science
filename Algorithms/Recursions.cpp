// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Recursions

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
        return n;
}

int fibonacci(int n)
{
    if (n > 2)
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    else
        return n - 1;
}

int summation(int n)
{
    if (n > 1)
    {
        return n + summation(n - 1);
    }
    else
        return n;
}

int binarysearch(int A[], int p, int r, int x)
{
    if (p <= r)
    {
        int q = p + (r - p) / 2;
        if (A[q] == x)
        {
            return q;
        }
        else if (A[q] > x)
        {
            return binarysearch(A, p, q - 1, x);
        }
        else
            return binarysearch(A, q + 1, r, x);
    }
    else
        return -1;
}

int main()
{
    cout << "\nFactorial";
    cout << "\n7!= ";
    int f1 = factorial(7);
    cout << f1;
    cout << "\n5!= ";
    int f2 = factorial(5);
    cout << f2;
    cout << "\nFibonacci Series";
    cout << "\nFirst 10 elements: ";
    for (int i = 1; i <= 10; i++)
    {
        int fb = fibonacci(i);
        cout << fb << " ";
    }
    cout << "\nSummation of first n natural numbers";
    cout << "\nFor n=5, S= ";
    int s1 = summation(5);
    cout << s1;
    cout << "\nFor n=15, S= ";
    int s2 = summation(15);
    cout << s2;
    cout << "\nBinary Search";
    int arr[] = {3, 6, 8, 9, 10, 15, 16, 20, 25, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index1 = binarysearch(arr, 0, n - 1, 8);
    cout << "\nIndex of 8: " << index1;
    int index2 = binarysearch(arr, 0, n - 1, 25);
    cout << "\nIndex of 25: " << index2;
    return 0;
}