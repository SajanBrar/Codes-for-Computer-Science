// Sajanjit Singh Brar
// 20124087
// First Come First Serve Scheduling

#include <iostream>
using namespace std;

int main()
{
    int n, time;
    time = 0;
    cout << "Sajanjit Singh Brar\n20124087\nOS Lab\nFirst Come First Serve\n";
    cout << "Enter the number of processes: ";
    cin >> n;
    int BurstTime[n];
    int ArrivalTime[n];
    cout << "\nEnter the burst time for each process: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i + 1 << " : ";
        cin >> BurstTime[i];
    }
    cout << "\nEnter the arrival time for each process: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Arrival time for process " << i + 1 << " : ";
        cin >> ArrivalTime[i];
    }
    cout << "\nProcess\tBurst Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        if (ArrivalTime[i] <= time)
        {
            time = time + BurstTime[i];
            cout << i + 1 << "\t" << BurstTime[i] << "\t\t" << time << "\n";
        }
    }
    cout << "\nTotal time taken is " << time << " msec.";
    return 0;
}