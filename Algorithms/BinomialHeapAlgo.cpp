// Sajanjit Singh Brar
// 20124087
// IDAA Lab
// Binomial Heap

#include <iostream>
using namespace std;

struct Node
{
public:
    int key;
    int degree;
    Node *parent;
    Node *child;
    Node *sibling;
};

class BinomialHeap
{
public:
    Node *Head;
    Node *H;
    Node *InitializeHeap();
    void BinomialLink(Node *, Node *);
    Node *CreateNode(int);
    Node *HeapUnion(Node *, Node *);
    Node *Insert(Node *, Node *);
    Node *Search(Node *, int);
    Node *Merge(Node *, Node *);
    Node *ExtractMin(Node *);
    void ReverseList(Node *);
    void Display(Node *);
    void DecreaseKey(Node *, int, int);
    void Delete(Node *, int);
    BinomialHeap()
    {
        Head = InitializeHeap();
        H = InitializeHeap();
        int count = 1;
    }
};

Node *BinomialHeap::InitializeHeap()
{
    Node *p;
    p = NULL;
    return p;
}

Node *BinomialHeap::CreateNode(int k)
{
    Node *p1 = new Node;
    p1->key = k;
    return p1;
}

void BinomialHeap::BinomialLink(Node *y, Node *z)
{
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

Node *BinomialHeap::Insert(Node *H, Node *x)
{
    Node *H_ = InitializeHeap();
    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H_ = x;
    H = HeapUnion(H, H_);
    return H;
}

Node *BinomialHeap::HeapUnion(Node *H1, Node *H2)
{
    Node *H = InitializeHeap();
    H = Merge(H1, H2);
    if (H == NULL)
        return H;
    Node *prev_x;
    Node *next_x;
    Node *x;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL)
    {
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL) && (next_x->sibling)->degree == x->degree))
        {
            prev_x = x;
            x = next_x;
        }
        else
        {
            if (x->key <= next_x->key)
            {
                x->sibling = next_x->sibling;
                BinomialLink(next_x, x);
            }
            else
            {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                BinomialLink(x, next_x);
                x = next_x;
            }
        }
        next_x = x->sibling;
    }
    return H;
}

Node *BinomialHeap::Merge(Node *H1, Node *H2)
{
    Node *H = InitializeHeap();
    Node *y;
    Node *z;
    Node *a;
    Node *b;
    y = H1;
    z = H2;
    if (y != NULL)
    {
        if (z != NULL)
        {
            if (y->degree <= z->degree)
                H = y;
            else if (y->degree > z->degree)
                H = z;
        }
        else
            H = y;
    }
    else
        H = z;
    while (y != NULL && z != NULL)
    {
        if (y->degree < z->degree)
        {
            y = y->sibling;
        }
        else if (y->degree == z->degree)
        {
            a = y->sibling;
            y->sibling = z;
            y = a;
        }
        else
        {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
    }
    return H;
}

Node *BinomialHeap::ExtractMin(Node *H1)
{
    H = NULL;
    Node *t = NULL;
    Node *x = H1;
    if (x == NULL)
    {
        cout << "Nothing to Extract" << endl;
        return x;
    }
    int min = x->key;
    Node *p = x;
    while (p->sibling != NULL)
    {
        if ((p->sibling)->key < min)
        {
            min = (p->sibling)->key;
            t = p;
            x = p->sibling;
        }
        p = p->sibling;
    }
    if (t == NULL && x->sibling == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->sibling;
    else if (t->sibling == NULL)
        t = NULL;
    else
        t->sibling = x->sibling;
    if (x->child != NULL)
    {
        ReverseList(x->child);
        (x->child)->sibling = NULL;
    }
    H = HeapUnion(H1, H);
    return x;
}

void BinomialHeap::ReverseList(Node *y)
{
    if (y->sibling != NULL)
    {
        ReverseList(y->sibling);
        (y->sibling)->sibling = y;
    }
    else
    {
        H = y;
    }
}

Node *BinomialHeap::Search(Node *H, int k)
{
    Node *x = H;
    Node *p = NULL;
    if (x->key == k)
    {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL)
        p = Search(x->child, k);
    if (x->sibling != NULL && p == NULL)
        p = Search(x->sibling, k);
    return p;
}

void BinomialHeap::DecreaseKey(Node *H, int i, int k)
{
    int temp;
    Node *p;
    Node *y;
    Node *z;
    p = Search(H, i);
    if (p == NULL)
    {
        cout << "Invalid key" << endl;
    }
    if (k > p->key)
    {
        cout << "Error. New key is greater than current key" << endl;
    }
    p->key = k;
    y = p;
    z = p->parent;
    while (z != NULL && y->key < z->key)
    {
        temp = y->key;
        y->key = z->key;
        z->key = temp;
        y = z;
        z = z->parent;
    }
    cout << "Key reduced" << endl;
}

void BinomialHeap::Delete(Node *H, int k)
{
    Node *np;
    if (H == NULL)
    {
        cout << "\nEmpty Heap";
    }
    DecreaseKey(H, k, -1000);
    np = ExtractMin(H);
    if (np != NULL)
        cout << "Node Deleted" << endl;
}

void BinomialHeap::Display(Node *H)
{
    if (H != NULL)
    {
        Node *p;
        p = H;
        while (p != NULL)
        {
            cout << p->key;
            // cout << " ,";
            if (p->sibling != NULL)
                cout << "  ";
            p = p->sibling;
            // cout << "(";
            // cout << "\n";
            // Display(p->child);
            // cout << ")";
        }
    }
}

int main()
{
    cout << "\nDemonstrating Binomial Heap\n";
    BinomialHeap bh;
    Node *H;
    H = bh.InitializeHeap();
    Node *n1;
    cout << "\nDemonstrating CreateNode and Insert\n";
    n1 = bh.CreateNode(5);
    H = bh.Insert(H, n1);
    Node *n2;
    n2 = bh.CreateNode(10);
    H = bh.Insert(H, n2);
    Node *n3;
    n3 = bh.CreateNode(15);
    H = bh.Insert(H, n3);
    Node *n4;
    n3 = bh.CreateNode(20);
    H = bh.Insert(H, n3);
    Node *n5;
    n3 = bh.CreateNode(25);
    H = bh.Insert(H, n3);
    bh.Display(H);
    Node *m;
    cout << "\nDemonstrating ExtractMin\n";
    m = bh.ExtractMin(H);
    bh.Display(H);
    cout << "\nDemonstrating DecreaseKey\n";
    bh.DecreaseKey(H, 25, 7);
    bh.Display(H);
    cout << "\nDemonstrating Delete\n";
    bh.Delete(H, 5);
    bh.Display(H);
    return 0;
}