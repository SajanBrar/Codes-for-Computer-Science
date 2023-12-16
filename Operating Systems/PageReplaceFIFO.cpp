// Sajanjit Singh Brar
// 20124087
// OS Lab
// FIFO Page Replacement

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\n";
    int noofpages;
    cout << "Enter number of pages: ";
    cin >> noofpages;
    queue<int> memory;
    for (int i = 0; i < noofpages; i++)
    {
        cout << "Entering Process " << i + 1 << "\n";
        memory.push(i + 1);
    }
    int noofnewprocesses;
    cout << "Enter number of new processes: ";
    cin >> noofnewprocesses;
    for (int i = 0; i < noofnewprocesses; i++)
    {
        cout << "Entering Process " << noofpages + i + 1 << " in place of Process " << i + 1 << "\n";
        memory.pop();
        memory.push(noofpages + i + 1);
    }
    return 0;
}