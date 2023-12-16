#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, degree;
    Node *parent, *child, *sibling;
    Node()
    {
        this->parent = NULL;
    }
};
// Node *root = NULL;

Node *makeHeap()
{
    Node *newHeap;
    newHeap = NULL;
    return newHeap;
}

Node *BHCreateNode(int n)
{
    Node *new_node = new Node;
    new_node->key = n;
    new_node->parent = NULL;
    new_node->sibling = NULL;
    new_node->child = NULL;
    new_node->degree = 0;
    return new_node;
}

Node *BHMinimum(Node *head)
{
    Node *y = NULL, *x = head;
    int min = 10000;
    while (x != NULL)
    {
        if (x->key < min)
        {
            min = x->key;
            y = x;
        }
        x = x->sibling;
    }
    return y;
}

void BHLinkNodes(Node *h1, Node *h2)
{
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree++;
}

Node *BHMerge(Node *h1, Node *h2)
{
    Node *h3 = new Node;
    Node *temp = h3;
    h3->key = -1;
    while (h1 != NULL && h2 != NULL)
    {

        if (h1->degree > h2->degree)
        {

            h3->sibling = h2;
            h2->parent = h3;

            h2 = h2->sibling;
            h3 = h3->sibling;
        }
        else if (h1->key > h2->key)
        {

            h3->sibling = h2;
            h2->parent = h3;
            h3->degree++;
            h2 = h2->sibling;
            h3 = h3->sibling;
        }
        else
        {
            h3->sibling = h1;
            h1->parent = h3;

            h1 = h1->sibling;
            h3 = h3->sibling;
        }
    }
    if (h1 == NULL)
        h3->sibling = h2;
    else
        h3->sibling = h1;
    return temp->sibling;
}

Node *BHUnion(Node *h1, Node *h2)
{
    if (h1 == NULL && h2 == NULL)
        return NULL;
    Node *res = BHMerge(h1, h2);

    if (res == NULL)
    {
        return res;
    }

    Node *prev = NULL, *curr = res, *next = curr->sibling;
    while (next != NULL)
    {
        if ((curr->degree != next->degree) || ((next->sibling != NULL) && (next->sibling)->degree == curr->degree))
        {
            prev = curr;
            curr = next;
        }
        else
        {
            if (curr->key <= next->key)
            {
                curr->sibling = next->sibling;
                BHLinkNodes(next, curr);
            }
            else
            {
                if (prev == NULL)
                    res = next;
                else
                    prev->sibling = next;
                BHLinkNodes(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return res;
}

Node *BHInsert(Node *h1, int x)
{
    Node *newNode = new Node;
    newNode->key = x;
    newNode->degree = 0;
    newNode->parent = NULL;
    newNode->sibling = NULL;
    return BHUnion(h1, newNode);
}

Node *remainingTree(Node *h1, Node *extracted)
{
    Node *temp = h1;
    if (h1 == extracted)
        return h1->sibling;
    while (h1 != NULL)
    {

        if (h1->sibling == extracted)
        {
            h1->sibling = extracted->sibling;
            return temp;
        }
        h1 = h1->sibling;
    }
}

Node *BHExtractMin(Node *h1)
{
    Node *h2 = BHMinimum(h1);

    h1 = remainingTree(h1, h2);

    h2 = h2->child;
    Node *prev = NULL;
    Node *next = h2->sibling;

    while (h2->sibling != NULL)
    {
        h2->sibling = prev;
        prev = h2;
        h2 = next;
        next = next->sibling;
    }
    h2->sibling = prev;

    h1 = BHUnion(h1, h2);
    return h1;
}

void display(Node *h1)
{
    if (h1 != NULL)
    {
        cout << h1->key << "  ";
        display(h1->sibling);
        cout << endl;

        display(h1->child);
    }
}

Node *BHFindNode(Node *h, int key)
{
    if (h == NULL)
        return NULL;

    if (h->key == key)
        return h;

    Node *res = BHFindNode(h->child, key);
    if (res != NULL)
        return res;

    return BHFindNode(h->sibling, key);
}

void BHDecreaseKey(Node *H, int old_key, int new_key)
{
    Node *node = BHFindNode(H, old_key);

    if (node == NULL)
        return;

    node->key = new_key;
    Node *parent = node->parent;

    while (parent != NULL && node->key < parent->key)
    {
        swap(node->key, parent->key);
        node = parent;
        parent = parent->parent;
    }
}

Node *BHDelete(Node *h, int key)
{
    if (h == NULL)
        return NULL;
    BHDecreaseKey(h, key, INT_MIN);

    return BHExtractMin(h);
}

int main()
{

    Node *head1 = new Node;
    Node *temp = head1;
    // manually making heap entries
    head1->key = 1;
    head1->degree = 0;
    head1->parent = NULL;
    head1->child = NULL;

    // for 1st order heap
    head1->sibling = new Node;

    head1 = head1->sibling;
    head1->key = 5;
    head1->degree = 1;
    // creating a child of 4
    head1->child = new Node;
    head1->child->parent = head1;
    head1->child->key = 6;
    head1->child->degree = 0;
    head1->child->sibling = NULL;
    head1->child->child = NULL;

    // for second order heap with root node 7
    head1->sibling = new Node;
    head1 = head1->sibling;
    head1->key = 8;
    head1->degree = 1;
    head1->sibling = NULL;
    // creating a child for the node 7
    head1->child = new Node;
    head1->child->parent = head1;
    head1->child->key = 10;
    head1->child->degree = 0;
    head1->child->sibling = NULL;
    head1->child->child = NULL;

    cout << "Heap:" << endl;
    display(temp);
    cout << "Inserting 5 in the binomial heap" << endl;
    display(BHInsert(temp, 5));
    Node *minimum = BHMinimum(temp);
    cout << "Minimum root: ";
    cout << minimum->key << endl;

    cout << "Extract Minimum operation:" << endl;
    display(BHExtractMin(temp));

    return 0;
}