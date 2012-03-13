#include <iostream>
#include "TList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


int main()
{
    TList * list;
    try{
     list = new TList();
        TNode * node = new TNode(new TDate(16,6,1991));
        list->PushBack(node);
        node = new TNode(new TDate(10,6,1991));
        list->PushBack(node);
        list->PushBack(new TNode(new TDate(5,6,1991)));
        list->PushBack(new TNode(new TDate(5,2,1991)));
        list->PushBack(new TNode(new TDate(4,10,1991)));
        list->SortByDate();

    cout << list->PopFront()->value->DateToStr() << endl;
    cout << list->PopFront()->value->DateToStr() << endl;
    cout << list->PopFront()->value->DateToStr() << endl;
    cout << list->PopFront()->value->DateToStr() << endl;
    cout << list->PopFront()->value->DateToStr() << endl;

}catch(const char * exc)
{
    cout << exc << endl;
}

//    delete list;
//    list = NULL;
    return 0;
}
