// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Matrix Multiplication (Divide and Conquer)

#include <iostream>
using namespace std;

const int l = 3;

void Partition(int A[l][l], int Ap[l][l], int section, int n)
{
    if (section == 1)
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                Ap[i][j] = A[i][j];
            }
        }
    }
    if (section == 2)
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = n / 2; j < n; j++)
            {
                Ap[i][j - (n / 2)] = A[i][j];
            }
        }
    }
    if (section == 3)
    {
        for (int i = n / 2; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                Ap[i - (n / 2)][j] = A[i][j];
            }
        }
    }
    if (section == 4)
    {
        for (int i = n / 2; i < n; i++)
        {
            for (int j = n / 2; j < n; j++)
            {
                Ap[i - (n / 2)][j - (n / 2)] = A[i][j];
            }
        }
    }
}

void MatrixAddition(int A[l][l], int B[l][l], int C[l][l], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void MatrixMultiply(int A[l][l], int B[l][l], int C[l][l], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int A11[l][l];
        Partition(A, A11, 1, n);
        int A12[l][l];
        Partition(A, A12, 2, n);
        int A21[l][l];
        Partition(A, A21, 3, n);
        int A22[l][l];
        Partition(A, A22, 4, n);
        int B11[l][l];
        Partition(B, B11, 1, n);
        int B12[l][l];
        Partition(B, B12, 2, n);
        int B21[l][l];
        Partition(B, B21, 3, n);
        int B22[l][l];
        Partition(B, B22, 4, n);
        int C11[l][l];
        Partition(C, C11, 1, n);
        int C12[l][l];
        Partition(C, C12, 2, n);
        int C21[l][l];
        Partition(C, C21, 3, n);
        int C22[l][l];
        Partition(C, C22, 4, n);
        int m1[l][l];
        int m2[l][l];
        int m3[l][l];
        int m4[l][l];
        int m5[l][l];
        int m6[l][l];
        int m7[l][l];
        int m8[l][l];
        MatrixMultiply(A11, B11, m1, n / 2);
        MatrixMultiply(A12, B21, m2, n / 2);
        MatrixMultiply(A11, B12, m3, n / 2);
        MatrixMultiply(A12, B22, m4, n / 2);
        MatrixMultiply(A21, B11, m5, n / 2);
        MatrixMultiply(A22, B21, m6, n / 2);
        MatrixMultiply(A21, B12, m7, n / 2);
        MatrixMultiply(A22, B22, m8, n / 2);
        MatrixAddition(m1, m2, C11, n / 2);
        MatrixAddition(m3, m4, C12, n / 2);
        MatrixAddition(m5, m6, C21, n / 2);
        MatrixAddition(m7, m8, C22, n / 2);
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + (n / 2)] = C12[i][j];
                C[i + (n / 2)][j] = C21[i][j];
                C[i + (n / 2)][j + (n / 2)] = C22[i][j];
            }
        }
    }
}

int main()
{
    int n;
    int A[l][l], B[l][l], C[l][l];
    cout << "Enter number of rows/colums for Matrix: ";
    cin >> n;
    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
        }
    }
    cout << "\nMatrix Multiplication of A and B gives:\n";
    MatrixMultiply(A, B, C, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}