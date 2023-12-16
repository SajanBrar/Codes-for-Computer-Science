#include <iostream>
using namespace std;

// semaphore
class semaphore
{
public:
    int val;
    semaphore(int v) { val = v; }
};

int down(semaphore s)
{
    return (s.val--);
}

int up(semaphore s)
{
    return (s.val++);
}

// Semaphore Declaration
semaphore READ(1);
semaphore WRITE(1);

int addWriter()
{
    int writer;
    cout << "Add Writer: ";
    cin >> writer;
    return writer;
}
int addReader()
{
    int reader;
    cout << "Add Reader: ";
    cin >> reader;
    return reader;
}

void write()
{
    int t = 3;
    while (t--)
    {
        // Writing in Process
        down(WRITE);

        // New Writer Enters
        if (addWriter())
            cout << "\n*Writing in Process*\n"
                 << endl;

        // Read Blocked While Writing
        if (addReader())
            cout << "\nREADER BLOCKED\n"
                 << endl;

        // New Writer Blocked while Writing
        if (addWriter())
            cout << "\nNEW WRITER BLOCKED\n"
                 << endl;

        // Writing Ends
        up(WRITE);

        cout << "\n*Writing Completed*\n"
             << endl;
    }
}

void read()
{
    int temp = 1;
    int read = 1;
    int readerCount = 0;

    while (true)
    {
        down(READ);
        while (temp == 1 && addReader())
        { // initial readers
            readerCount++;
        }
        cout << "\nCurrent Reader Count: " << readerCount << endl
             << endl;

        temp = 0;
        if (readerCount && addWriter())
        { // new writer in b/w //writing not allowed
            down(WRITE);
            cout << "--WRITER BLOCKED--\n";
        }
        if (addReader())
        { // new reader if any
            readerCount++;
        }
        // 1 reader leave
        up(READ);
        cout << "*Reader " << (read++) << " reading completed*" << endl;
        readerCount--;

        if (readerCount == 0)
        { // all readers out
            cout << endl
                 << "All Readers' Reading Completed" << endl;
            // now writing allowed
            up(WRITE);
            break;
        }
    }
}

int main()
{
    while (true)
    {
        cout << endl
             << "Options:" << endl
             << "1. Want to Read" << endl
             << "2. Want to Write" << endl
             << "3. Exit" << endl;
        int ch;
        cout << "Enter Option: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            read();
            break;
        case 2:
            write();
            break;
        case 3:
            exit(1);
            break;
        }
    }
    return 0;
}