// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Insertion Sort

#include <iostream>
using namespace std;

int main()
{
    int i, n, key;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements of array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << " : ";
        cin >> arr[i];
    }
    for (int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        cout << "\nThe value of key after " << j << "th iteration of for loop: " << key;
        while (i > 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
        cout << "\nThe array after this iteration: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
    }
    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}