#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED

#include "TDate.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
class TNode
{
    public:
        TDate * value;
        TNode * next;
        TNode * prev;

        TNode();
        TNode(TDate *);
        TNode(TNode&);
        ~TNode();
        TNode & operator=(TNode&);
};

class TList
{
    private:

        size_t size;
        TNode * head;
        TNode * tail;

    protected:
        bool CheckThisNull();
    public:
        TList();
        TList(TNode *);
        TList(TList &);
        ~TList();

        void PushBack(TNode*);
        void SortByDate();
        TNode* PopFront();
        TNode * GetHead();
        TNode * GetTail();
        void Clear();
        bool Empty();
//        int alocate()
//            dealoc


};



#endif // TLIST_H_INCLUDED
