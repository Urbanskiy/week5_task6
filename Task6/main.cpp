#include <iostream>
#include "TList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


int main()
{
    TList * list;
    TStack * stack  = new TStack();
    TNode * node;
    try{
     list = new TList();
        TNode * node = new TNode(new TDate(16,6,1991,"awdad awd"));
        list->PushBack(node);
        node = new TNode(new TDate(10,6,1991,"awdad awd"));
        list->PushBack(node);
        list->PushBack(new TNode(new TDate(5,6,1991,"awdad awd")));
        list->PushBack(new TNode(new TDate(5,2,1991,"awdad awd")));
        list->PushBack(new TNode(new TDate(4,10,1991,"awdad awd")));
        list->SortByDate();

        while(!list->Empty())
        {
            stack->Push(new TNode(list->PopFront()));
        }
        while(!stack->Empty())
        {
            node->value = stack->PopFront();
            cout << node->value->DateToStr() << " : " << node->value->GetEvent() << endl;
        }
        stack->PrintNodes();

}catch(const char * exc)
{
    cout << exc << endl;
}

//    delete list;
//    list = NULL;
    return 0;
}
