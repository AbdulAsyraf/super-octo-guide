#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "prob.h"

using namespace std;

Whaa::Whaa(){
    numItem = 10;
    pHead = 0;
    pTail = 0;
}
Whaa::~Whaa(){}

void Whaa::addToFront()
{
    int item1, item2, item3;
    ifstream inFile("data.txt");
    inFile >> item1 >> item2 >> item3;
    Node *pNew = new Node;
    pNew->data1 = item1;
    pNew->data2 = item2;
    pNew->data3 = item3;
    pHead = pNew;
    pHead->link = NULL;
    pTail = pNew;
    pTail->link = NULL;
    
    for (int i = 1; i < numItem; i++)
    {
        inFile >> item1 >> item2 >> item3;
        Node *pNew = new Node;
        pNew->data1 = item1;
        pNew->data2 = item2;
        pNew->data3 = item3;
        pNew->link = pHead;
        pHead = pNew;
    }
}

void Whaa::add()
{
    int item1, item2, item3;
    ifstream inFile("data.txt");
    inFile >> item1 >> item2 >> item3;
    Node *pNew = new Node;
    pNew->data1 = item1;
    pNew->data2 = item2;
    pNew->data3 = item3;
    pHead = pNew;
    pHead->link = NULL;
    pTail = pNew;
    pTail->link = NULL;

    for (int i = 1; i < numItem; i++)
    {
        inFile >> item1 >> item2 >> item3;
        Node *pNew = new Node;
        pNew->data1 = item1;
        pNew->data2 = item2;
        pNew->data3 = item3;
        pTail->link = pNew;
        pTail = pNew;
    }
}

void Whaa::printData()
{
    pCurr = pHead;
    while(pCurr != pTail->link)
    {
        cout << pCurr->data1 << " " << pCurr->data2 << " " << pCurr->data3 <<endl;
        pCurr = pCurr->link;
    }
}

void Whaa::search(int target)
{
    int iter = 0;
    pCurr = pHead;
    pBefore = pHead;
    pBeforeBefore = pHead;
    if(pCurr->data1 == target || pCurr->data2 == target || pCurr->data3 == target)
        cout << "Target is found in the first entry" << endl;
    else
    {
        while(pCurr != pTail->link && pCurr->data1 != target && pCurr->data2 != target && pCurr->data3 != target)
        {
            pBeforeBefore = pBefore;
            pBefore = pCurr;
            pCurr = pCurr->link;
            iter++;
        }
        if (pCurr->data1 == target)
            cout << "Target is a data1 type found after "<< iter << " iterations" <<endl;
        else if (pCurr->data2 == target)
            cout << "Target is a data2 type found after "<< iter << " iterations" <<endl;
        else if (pCurr->data3 == target)
            cout << "Target is a data3 type found after "<< iter << " iterations" <<endl;
        else
            cout << "Target is not found" << endl;

        if(pBefore == pHead)
        {
            pBefore->link = pCurr->link;
            pCurr->link = pBefore;
            pHead = pCurr;
        }
        else if (pBeforeBefore == pHead)
        {
            pBeforeBefore->link = pCurr;
            pBefore->link = pCurr->link;
            pCurr->link = pBefore;
            pHead = pBeforeBefore;
        }
        else if (pCurr != pHead)
        {
            pBeforeBefore->link = pCurr;
            pBefore->link = pCurr->link;
            pCurr->link = pBefore;
        }

        ofstream outFile("data.txt");
        pCurr = pHead;
        while(pCurr != pTail->link)
        {
            outFile << pCurr->data1 << "\t" << pCurr->data2 << "\t" << pCurr->data3 << endl;
            pCurr = pCurr->link;
        }
    }
}