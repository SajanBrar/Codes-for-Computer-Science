// Sajanjit Singh Brar
// 20124087
// OS Lab
// LRU Page Replacement

#include <iostream>
using namespace std;

int main()
{
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\n";
    int noofpages;
    cout << "Enter number of pages: ";
    cin >> noofpages;
    int index = 0;
    int pages[noofpages];
    for (int i = 0; i < noofpages; i++)
    {
        cout << "Entering Process: " << i + 1 << "\n";
        pages[i] = i + 1;
    }
    int counter = index;
    int noofnewprocesses;
    cout << "Enter number of new processes: ";
    cin >> noofnewprocesses;
    cout << "Selecting least recently used process with rand() function.\n";
    for (int i = 0; i < noofnewprocesses; i++)
    {
        int a = rand() % noofpages;
        index = a;
        pages[index] = noofpages + i + 1;
        cout << "Entering Process " << noofpages + i + 1 << " in place of Process " << index << "\n";
    }
    return 0;
}