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
    bool counter = false;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int answer1 = A[i];
        for (int j = i + 1; j < n; j++)
        {
            if (answer1 == A[j])
            {
                answer1 = A[j];
                counter = true;
                cout << "\n"
                     << answer1;
                break;
            }
        }
    }
    return 0;
}