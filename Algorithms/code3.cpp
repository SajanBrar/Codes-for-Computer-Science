#include <iostream>
using namespace std;

struct TreeNodes
{
    int val;
    TreeNodes *left;
    TreeNodes *right;
    TreeNodes *parent;
};

int main()
{
    TreeNodes N3;
    TreeNodes N5;
    TreeNodes N1;
    TreeNodes N6;
    TreeNodes N2;
    TreeNodes N0;
    TreeNodes N8;
    TreeNodes N7;
    TreeNodes N4;

    N3.val = 3;
    *N3.left = N5;
    *N3.right = N1;
    N3.parent = NULL;

    N5.val = 5;
    *N5.left = N6;
    *N5.right = N2;
    *N5.parent = N3;

    N1.val = 1;
    *N1.left = N0;
    *N1.right = N8;
    *N1.parent = N3;

    N6.val = 6;
    N6.left = NULL;
    N6.right = NULL;
    *N6.parent = N5;

    N2.val = 2;
    *N2.left = N7;
    *N2.right = N4;
    *N2.parent = N5;

    N0.val = 0;
    N0.left = NULL;
    N0.right = NULL;
    *N0.parent = N1;

    N8.val = 8;
    N8.left = NULL;
    N8.right = NULL;
    *N8.parent = N1;

    N7.val = 7;
    N7.left = NULL;
    N7.right = NULL;
    *N7.parent = N2;

    N4.val = 3;
    N4.left = NULL;
    N4.right = NULL;
    *N4.parent = N2;

    int N5anc, N1anc;
    TreeNodes N5ances;
    TreeNodes N1ances;
    N5ances = N5;
    N1ances = N1;
    while (N5ances.val != N1ances.val)
    {
        N5ances = *N5.parent;
        N1ances = *N1.parent;
    }
    cout << N5ances.parent;
    return 0;
}