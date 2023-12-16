// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Linear and Binary Search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int size, element;
    cout << "Enter no. of elements in the array: ";
    cin >> size;
    int arr[size];
    cout << "\nEnter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cout << "\nElement at " << i << ": ";
        cin >> arr[i];
    }
    cout << "\nEnter element to search: ";
    cin >> element;
    cout << "\nLinear Search";
    int searchIndex1 = linearSearch(arr, size, element);
    cout << "\nThe searched element is at position " << searchIndex1;
    cout << "\nThe time complexity of linear search is O(n)";
    cout << "\n\nBinary Search";
    int searchIndex2 = binarySearch(arr, size, element);
    cout << "\nThe searched element is at position " << searchIndex2;
    cout << "\nThe time complexity of binary search is O(log n)";
    return 0;
}