// Sajanjit Singh Brar 
// 20124087
// OS Lab
// Paging

#include <iostream>
using namespace std;

int main()
{
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\n";
    int memorysize, noofframes, noofpages, noofprocesses;
    cout << "Enter memory size: ";
    cin >> memorysize;
    cout << "Enter no of frames: ";
    cin >> noofframes;
    cout << "Enter no of pages: ";
    cin >> noofpages;
    cout << "Enter no of processes: ";
    cin >> noofprocesses;
    int pages[noofpages];
    int framesize = memorysize / noofframes;
    int processreq[noofprocesses];
    int pageno = 0;
    for (int i = 0; i < noofprocesses; i++)
    {
        cout << "Enter no of pages req by process " << i + 1 << ": ";
        cin >> processreq[i];
        cout << "Enter page table requirement of Process " << i + 1 << ": ";
        for (int j = 0; j < processreq[i]; j++)
        {
            cin >> pages[j + pageno];
            pageno = pageno + processreq[i];
        }
    }
    int prono, pagno;
    cout << "Enter logical address: ";
    cout << "Process no: ";
    cin >> prono;
    cout << "Page no: ";
    cin >> pagno;
    cout << "Physical address is: ";
    cout << (memorysize / noofpages) * (pagno + prono);
    return 0;
}