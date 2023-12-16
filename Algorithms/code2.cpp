#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "\nEnter the number of elements in array: ";
    cin >> n;
    int A[n];
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter element " << i << ": ";
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            int temp = A[i];
            for (int j = i - 1; j >= 0; j--)
            {
                A[j + 1] = A[j];
            }
            A[0] = temp;
        }
    }
    cout << "\nResultant Array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
    return 0;
}