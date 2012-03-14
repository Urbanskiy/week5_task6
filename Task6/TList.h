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
    protected:

        size_t size;
        TNode * head;
        TNode * tail;

        bool CheckThisNull();
    public:
        TList();
        TList(TNode *);
        TList(TList &);
        ~TList();

        void PushBack(TNode*);
        void SortByDate();
        TDate* PopFront();
        TNode * GetHead();
        TNode * GetTail();
        void Clear();
        bool Empty();
        void PrintNodes();
};
class TStack : public TList
{
//    friend TNode* TList::PopFront();
   public:
    TStack():TList(){};
    TStack(TNode* node):TList(node){};
    TStack(TStack& stc):TList(stc){};
    ~TStack() { Clear();}

    void Push(TNode*);

};



#endif // TLIST_H_INCLUDED
