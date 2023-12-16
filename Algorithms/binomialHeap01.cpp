#include <bits/stdc++.h>
using namespace std;

#define nullptr NULL

class heapNode
{

public:
    int data, degree;
    heapNode *lchild, *sibling, *parent;

    heapNode(int data)
    {
        this->data = data;
        this->degree = 0;
        lchild = sibling = parent = nullptr;
    }
};

void printTree(heapNode *head)
{

    while (head != nullptr)
    {
        cout << head->data << " ";
        printTree(head->lchild);
        head = head->sibling;
    }
}

void printHeap(vector<heapNode *> BinomialHeap)
{

    for (int i = 0; i < BinomialHeap.size(); i++)
    {
        printTree(BinomialHeap[i]);
        cout << "\n";
    }
}

heapNode *getMin(vector<heapNode *> BinomialHeap)
{

    heapNode *mn = BinomialHeap[0];

    for (int i = 1; i < BinomialHeap.size(); i++)
    {
        if (BinomialHeap[i]->data < mn->data)
            mn = BinomialHeap[i];
    }

    return mn;
}

vector<heapNode *> removeMinReturn_Heap(vector<heapNode *> BinomialHeap, heapNode *tmp)
{

    vector<heapNode *> heap;
    tmp = tmp->lchild;

    heapNode *nxt;

    while (tmp != nullptr)
    {
        nxt = tmp;
        tmp = tmp->sibling;
        nxt->sibling = nullptr;
        heap.push_back(nxt);
    }

    return heap;
}

heapNode *mergeBinomialTrees(heapNode *b1, heapNode *b2)
{
    if (b1->data > b2->data)
        swap(b1, b2);

    b2->parent = b1;
    b2->sibling = b1->lchild;
    b1->lchild = b2;
    b1->degree++;

    return b1;
}

vector<heapNode *> adjust(vector<heapNode *> _heap)
{

    int i1 = 0, i2 = 1, i3 = 2;

    if (_heap.size() <= 1)
        return _heap;

    vector<heapNode *>::iterator it1, it2, it3;
    it1 = it2 = it3 = _heap.begin();

    if (_heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = _heap.end();
    }
    else
    {
        it2++;
        it3 = it2;
        it3++;
    }

    while (it1 != _heap.end())
    {
        // if only one element remains to be processed
        if (it2 == _heap.end())
            it1++;

        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if (it3 != _heap.end())
                it3++;
        }
        else if (it3 != _heap.end() && (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }
        else if ((*it1)->degree == (*it2)->degree)
        {
            *it1 = mergeBinomialTrees(*it1, *it2);
            it2 = _heap.erase(it2);
            if (it3 != _heap.end())
                it3++;
        }
    }
    return _heap;
}

vector<heapNode *> unionHeap(vector<heapNode *> h1, vector<heapNode *> h2)
{

    vector<heapNode *> new_heap;
    int l1 = 0, l2 = 0;

    while (l1 < h1.size() and l2 < h2.size())
    {

        if (h1[l1]->degree <= h2[l2]->degree)
        {
            new_heap.push_back(h1[l1++]);
        }
        else
        {
            new_heap.push_back(h2[l2++]);
        }
    }

    while (l1 < h1.size())
        new_heap.push_back(h1[l1++]);

    while (l2 < h2.size())
        new_heap.push_back(h2[l2++]);

    return adjust(new_heap);
}

vector<heapNode *> extractMin(vector<heapNode *> BinomialHeap)
{

    heapNode *tmp = getMin(BinomialHeap);
    vector<heapNode *> new_heap;

    for (int i = 0; i < BinomialHeap.size(); i++)
    {
        if (BinomialHeap[i] != tmp)
        {
            new_heap.push_back(BinomialHeap[i]);
        }
    }

    vector<heapNode *> removed_Heap = removeMinReturn_Heap(BinomialHeap, tmp);
    vector<heapNode *> final = unionHeap(removed_Heap, new_heap);

    return adjust(final);
}

vector<heapNode *> insert_A_Tree(vector<heapNode *> BinomialHeap, heapNode *tree)
{

    vector<heapNode *> tmp;
    tmp.push_back(tree);
    vector<heapNode *> final = unionHeap(BinomialHeap, tmp);
    return adjust(final);
}

vector<heapNode *> insert(vector<heapNode *> BinomialHeap, int data)
{

    heapNode *tmp = new heapNode(data);
    return insert_A_Tree(BinomialHeap, tmp);
}

int main()
{

    vector<heapNode *> _heap;
    _heap = insert(_heap, 10);
    _heap = insert(_heap, 20);
    _heap = insert(_heap, 30);

    cout << "Heap elements after insertion:\n";
    printHeap(_heap);

    heapNode *temp = getMin(_heap);
    cout << "\nMinimum element of heap " << temp->data << "\n";

    _heap = extractMin(_heap);
    cout << "Heap after deletion of minimum element\n";
    printHeap(_heap);

    return 0;
}
