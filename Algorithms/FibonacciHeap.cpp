// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Fibonacci Heap

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct node
{
    int n;
    int degree;
    node *parent;
    node *child;
    node *left;
    node *right;
    char mark;
    char C;
};

class FibonacciHeap
{
private:
    int nH;
    node *H;

public:
    node *InitializeHeap();
    void Fibonnaci_link(node *, node *, node *);
    node *Create_node(int);
    node *Insert(node *, node *);
    node *Union(node *, node *);
    node *Extract_Min(node *);
    void Consolidate(node *);
    void Display(node *);
    void DisplayHeap(node *);
    node *Find(node *, int);
    int Decrease_key(node *, int, int);
    int Delete_key(node *, int);
    void Cut(node *, node *, node *);
    void Cascase_cut(node *, node *);
    FibonacciHeap()
    {
        H = InitializeHeap();
    }
};

node *FibonacciHeap::InitializeHeap()
{
    node *np;
    np = NULL;
    return np;
}

node *FibonacciHeap::Create_node(int value)
{
    node *x = new node;
    x->n = value;
    return x;
}

node *FibonacciHeap::Insert(node *H, node *x)
{
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->left = x;
    x->right = x;
    x->mark = 'F';
    x->C = 'N';
    if (H != NULL)
    {
        (H->left)->right = x;
        x->right = H;
        x->left = H->left;
        H->left = x;
        if (x->n < H->n)
            H = x;
    }
    else
    {
        H = x;
    }
    nH = nH + 1;
    return H;
}

void FibonacciHeap::Fibonnaci_link(node *H1, node *y, node *z)
{
    (y->left)->right = y->right;
    (y->right)->left = y->left;
    if (z->right == z)
        H1 = z;
    y->left = y;
    y->right = y;
    y->parent = z;
    if (z->child == NULL)
        z->child = y;
    y->right = z->child;
    y->left = (z->child)->left;
    ((z->child)->left)->right = y;
    (z->child)->left = y;
    if (y->n < (z->child)->n)
        z->child = y;
    z->degree++;
}

node *FibonacciHeap::Union(node *H1, node *H2)
{
    node *np;
    node *H = InitializeHeap();
    H = H1;
    (H->left)->right = H2;
    (H2->left)->right = H;
    np = H->left;
    H->left = H2->left;
    H2->left = np;
    return H;
}

void FibonacciHeap::DisplayHeap(node *H)
{
    node *p = H;
    if (p == NULL)
    {
        cout << "Empty Heap" << endl;
    }
    else
    {
        cout << "Root Nodes: " << endl;

        do
        {
            cout << p->n;
            p = p->right;
            if (p != H)
            {
                cout << "-->";
            }
        } while (p != H && p->right != NULL);
        cout << endl;
    }
}

void FibonacciHeap::Display(node *H)
{
    int counter = 0;
    node *p = H;
    if (p == NULL)
    {
        cout << "\nThe Heap is Empty" << endl;
    }
    else
    {
        cout << "\nThe root nodes of Heap are: " << endl;
        do
        {
            cout << p->n;
            p = p->right;
            if (p != H)
            {
                cout << "-->";
            }
            counter++;
        } while (p != H && p->right != NULL && counter < 5);
        cout << endl;
    }
}

node *FibonacciHeap::Extract_Min(node *H1)
{
    node *p;
    node *ptr;
    node *z = H1;
    p = z;
    ptr = z;
    if (z == NULL)
        return z;
    node *x;
    node *np;
    x = NULL;
    if (z->child != NULL)
        x = z->child;
    if (x != NULL)
    {
        ptr = x;
        do
        {
            np = x->right;
            (H1->left)->right = x;
            x->right = H1;
            x->left = H1->left;
            H1->left = x;
            if (x->n < H1->n)
                H1 = x;
            x->parent = NULL;
            x = np;
        } while (np != ptr);
    }
    (z->left)->right = z->right;
    (z->right)->left = z->left;
    H1 = z->right;
    if (z == z->right && z->child == NULL)
        H = NULL;
    else
    {
        H1 = z->right;
        Consolidate(H1);
    }
    nH = nH - 1;
    return p;
}

void FibonacciHeap::Consolidate(node *H1)
{
    int d, i;
    float f = (log(nH)) / (log(2));
    int D = f;
    node *A[D];
    for (i = 0; i <= D; i++)
        A[i] = NULL;
    node *x = H1;
    node *y;
    node *np;
    node *pt = x;
    do
    {
        pt = pt->right;
        d = x->degree;
        while (A[d] != NULL)
        {
            y = A[d];
            if (x->n > y->n)
            {
                np = x;
                x = y;
                y = np;
            }
            if (y == H1)
                H1 = x;
            Fibonnaci_link(H1, y, x);
            if (x->right == x)
                H1 = x;
            A[d] = NULL;
            d = d + 1;
        }
        A[d] = x;
        x = x->right;
    } while (x != H1);
    H = NULL;
    for (int j = 0; j <= D; j++)
    {
        if (A[j] != NULL)
        {
            A[j]->left = A[j];
            A[j]->right = A[j];
            if (H != NULL)
            {
                (H->left)->right = A[j];
                A[j]->right = H;
                A[j]->left = H->left;
                H->left = A[j];
                if (A[j]->n < H->n)
                    H = A[j];
            }
            else
            {
                H = A[j];
            }
            if (H == NULL)
                H = A[j];
            else if (A[j]->n < H->n)
                H = A[j];
        }
    }
}

int FibonacciHeap::Decrease_key(node *H1, int x, int k)
{
    node *y;
    if (H1 == NULL)
    {
        cout << "The Heap is Empty" << endl;
        return 0;
    }
    node *ptr = Find(H1, x);
    if (ptr == NULL)
    {
        cout << "Node not found in the Heap" << endl;
        return 1;
    }
    if (ptr->n < k)
    {
        cout << "Entered key greater than current key" << endl;
        return 0;
    }
    ptr->n = k;
    y = ptr->parent;
    if (y != NULL && ptr->n < y->n)
    {
        Cut(H1, ptr, y);
        Cascase_cut(H1, y);
    }
    if (ptr->n < H->n)
        H = ptr;
    return 0;
}

void FibonacciHeap::Cut(node *H1, node *x, node *y)
{
    if (x == x->right)
        y->child = NULL;
    (x->left)->right = x->right;
    (x->right)->left = x->left;
    if (x == y->child)
        y->child = x->right;
    y->degree = y->degree - 1;
    x->right = x;
    x->left = x;
    (H1->left)->right = x;
    x->right = H1;
    x->left = H1->left;
    H1->left = x;
    x->parent = NULL;
    x->mark = 'F';
}

void FibonacciHeap::Cascase_cut(node *H1, node *y)
{
    node *z = y->parent;
    if (z != NULL)
    {
        if (y->mark == 'F')
        {
            y->mark = 'T';
        }
        else
        {
            Cut(H1, y, z);
            Cascase_cut(H1, z);
        }
    }
}

node *FibonacciHeap::Find(node *H, int k)
{
    node *x = H;
    x->C = 'Y';
    node *p = NULL;
    if (x->n == k)
    {
        p = x;
        x->C = 'N';
        return p;
    }
    if (p == NULL)
    {
        if (x->child != NULL)
            p = Find(x->child, k);
        if ((x->right)->C != 'Y')
            p = Find(x->right, k);
    }
    x->C = 'N';
    return p;
}

int FibonacciHeap::Delete_key(node *H1, int k)
{
    node *np = NULL;
    int t;
    t = Decrease_key(H1, k, -5000);
    if (!t)
        np = Extract_Min(H);
    if (np != NULL)
        cout << "Key Deleted" << endl;
    else
        cout << "Key not Deleted" << endl;
    return 0;
}

int main()
{
    FibonacciHeap FH;
    node *p;
    node *p1;
    node *p2;
    node *H;
    H = FH.InitializeHeap();
    cout << "\nDemonstrating CreateNode and Insert\n";
    p = FH.Create_node(7);
    H = FH.Insert(H, p);
    p1 = FH.Create_node(5);
    H = FH.Insert(H, p1);
    p2 = FH.Create_node(9);
    H = FH.Insert(H, p2);
    FH.Display(H);
    cout << "\nDemonstrating ExtractMin\n";
    p = FH.Extract_Min(H);
    if (p != NULL)
    {
        cout << "\nThe Node with Minimum Key: " << p->n;
    }
    else
    {
        cout << "\nEmpty Heap";
    }
    FH.Display(H);
    cout << "\nDemonstrating DecreaseKey\n";
    FH.Decrease_key(H, 9, 3);
    FH.Display(H);
    cout << "\nDemonstrating DeleteKey\n";
    FH.Delete_key(H, 5);
    FH.Display(H);
    return 0;
}