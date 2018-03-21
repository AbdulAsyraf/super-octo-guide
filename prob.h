#ifndef PROB_H
#define PROB_H

class Whaa
{
    private:
        struct Node
        {    
            int data1, data2, data3;
            Node *link;
        };
        Node *pHead;
        Node *pTail;
        Node *pCurr;
        Node *pBefore;
        Node *pBeforeBefore;
        int numItem;

    public:
        Whaa();
        ~Whaa();
        void add();
        void addToFront();
        void printData();
        void search(int);
};

#endif



