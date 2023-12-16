#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int degree;
    Node *parent;
    Node *child;
    Node *sibling;
};

Node MakeHeap()
{
    Node H;
    H.child = NULL;
    H.degree = 0;
    H.key = 0;
    H.parent = NULL;
    H.sibling = NULL;
    return H;
}

void BinomialLink(Node y, Node z)
{
    *y.parent = z;
    y.sibling = z.child;
    *z.child = y;
    z.degree = z.degree + 1;
}

Node *Merge(Node *h1, Node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;
    if (h1->degree < h2->degree)
    {
        h1->sibling = Merge(h1->sibling, h2);
        return h1;
    }
    else
    {
        h2->sibling = Merge(h1, h2->sibling);
        return h2;
    }
}

Node *BinomialHeapMerge(Node H1, Node H2)
{
    Merge(H1.parent, H2.parent);
    return H1.parent;
}

Node HeapUnion(Node H1, Node H2)
{
    Node H = MakeHeap();
    H.parent = BinomialHeapMerge(H1, H2);
    if (H.parent == NULL)
    {
        return H;
    }
    Node *x;
    Node *prev_x;
    Node *next_x;
    prev_x = NULL;
    x = H.parent;
    next_x = x->sibling;
    while (next_x != NULL)
    {
        if ((x->degree != next_x->degree) or ((next_x->sibling != NULL) and (next_x->sibling->degree == x->degree)))
        {
            prev_x = x;
            x = next_x;
        }
        else
        {
            if (x->key <= next_x->key)
            {
                x->sibling = next_x->sibling;
                BinomialLink(*next_x, *x);
            }
            else if (prev_x == NULL)
            {
                H.parent = next_x;
            }
            else
            {
                prev_x->sibling == next_x;
            }
            BinomialLink(*x, *next_x);
            x = next_x;
        }
        next_x = x->sibling;
    }
    return H;
}

void Insert(Node H, Node x)
{
    Node H_ = MakeHeap();
    x.parent = NULL;
    x.child = NULL;
    x.sibling = NULL;
    x.degree = 0;
    *H_.parent = x;
    H = HeapUnion(H, H_);
}

Node *Minimum(Node H)
{
    Node *y;
    y = NULL;
    Node *x;
    x = H.parent;
    int *min;
    *min = 1000;
    while (x != NULL)
    {
        if (H.key < *min)
        {
            *min = H.key;
            y = x;
        }
        x = H.sibling;
    }
    return y;
}

Node *ExtractMin(Node H)
{
    Node *Min = Minimum(H);
    Node H_1 = MakeHeap();
    Node List;
    int a;
    while (H.sibling->key != 0)
    {
        a = H.sibling->key;
    }
    List.key = a;
    while (H.sibling->key != H.key)
    {
        int b = a;
        while (H.sibling->key != b)
        {
            a = H.sibling->key;
        }
        List.sibling->key = a;
    }
    H_1.parent = List.parent;
    H = HeapUnion(H, H_1);
    return Min;
}

void DecreaseKey(Node H, Node x, int k)
{
    if (k > x.key)
    {
        cout << "\nError: New key is greater than current key.";
    }
    x.key = k;
    Node y = x;
    Node z = *y.parent;
    while ((z.key != 0) and (y.key < z.key))
    {
        int temp = y.key;
        y.key = z.key;
        z.key = temp;
        y = z;
        z = *y.parent;
    }
}

void Delete(Node H, Node x)
{
    DecreaseKey(H, x, -1000);
    ExtractMin(H);
}

void DisplayHeap(Node Head)
{
    cout << Head.key << " ";
    cout << Head.sibling->key << " ";
    cout << Head.sibling->sibling->key << " ";
}

void SampleHeaps()
{
    Node N10;
    Node N1;
    Node N12;
    Node N25;
    Node N18;
    Node N6;
    Node N8;
    Node N14;
    Node N29;
    Node N11;
    Node N17;
    Node N38;
    Node N27;
    *N10.parent = N10;
    N10.key = 10;
    N10.degree = 0;
    N10.child = NULL;
    *N10.sibling = N1;
    N1.parent = NULL;
    N1.key = 1;
    N1.degree = 2;
    *N1.child = N12;
    *N1.sibling = N6;
    N6.parent = NULL;
    N6.key = 6;
    N6.degree = 3;
    *N6.child = N8;
    N6.sibling = NULL;
    *N12.parent = N1;
    *N12.sibling = N25;
    N12.key = 12;
    N12.degree = 1;
    *N12.child = N18;
    *N25.parent = N1;
    N25.sibling = NULL;
    N25.child = NULL;
    N25.key = 25;
    N25.degree = 0;
    *N8.parent = N6;
    *N8.child = N11;
    *N8.sibling = N14;
    N8.key = 8;
    N8.degree = 2;
    N14.key = 14;
    N14.degree = 1;
    *N14.child = N38;
    *N14.parent = N6;
    *N14.sibling = N29;
    N29.key = 29;
    N29.degree = 0;
    N29.sibling = NULL;
    N29.child = NULL;
    *N29.parent = N6;
    N18.key = 18;
    N18.degree = 0;
    N18.sibling = NULL;
    N18.child = NULL;
    *N18.parent = N12;
    N11.key = 11;
    N11.degree = 1;
    *N11.child = N27;
    *N11.parent = N8;
    *N11.sibling = N17;
    N17.key = 17;
    N17.degree = 0;
    N17.child = NULL;
    *N17.sibling = N38;
    *N17.parent = N8;
    N38.key = 38;
    N38.degree = 0;
    N38.child = NULL;
    N38.sibling = NULL;
    *N38.parent = N14;
    N27.key = 27;
    N27.degree = 0;
    *N27.parent = N11;
    N27.child = NULL;
    N27.sibling = NULL;
    Node M12;
    Node M7;
    Node M15;
    Node M25;
    Node M28;
    Node M33;
    Node M41;
    M12.key = 12;
    M12.degree = 0;
    *M12.parent = M12;
    M12.child = NULL;
    *M12.sibling = M7;
    M7.key = 7;
    M7.degree = 1;
    *M7.child = M25;
    *M7.sibling = M15;
    M7.parent = NULL;
    M15.key = 15;
    M15.degree = 2;
    M15.sibling = NULL;
    M15.parent = NULL;
    *M15.child = M28;
    M25.key = 25;
    M25.degree = 0;
    M25.sibling = NULL;
    M25.child = NULL;
    *M25.parent = M7;
    M28.key = 28;
    M28.degree = 1;
    *M28.sibling = M33;
    *M28.parent = M15;
    *M28.child = M41;
    M33.key = 33;
    M33.degree = 0;
    M33.sibling = NULL;
    M33.child = NULL;
    *M33.parent = M15;
    M41.key = 41;
    M41.degree = 0;
    M41.child = NULL;
    M41.sibling = NULL;
    *M41.parent = M28;
}

int main()
{
    cout << "Binomial Heap\n";
    Node H1 = MakeHeap();
    Node H2;
    Node xyz;
    xyz.key = 7;
    cout << "Demonstrating Insert\n";
    Insert(H1, xyz);
    cout << "Demostrating Minimum\n";
    Node *M = Minimum(H1);
    cout << "Demonstrating ExtractMin\n";
    Node *EM = ExtractMin(H1);
    cout << "Demonstrating HeapUnion\n";
    Node M1;
    M1.key = 15;
    M1.sibling = NULL;
    M1.degree = 0;
    M1.child = NULL;
    *M1.parent = M1;
    Node H__ = HeapUnion(H1, M1);
    cout << "Demonstrating DecreaseKey\n";
    DecreaseKey(H1, H2, 1);
    cout << "Demonstrating Delete\n";
    Delete(H1, H2);
    return 0;
}