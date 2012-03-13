#include "TList.h"
//------------------------------------------------------------------
TNode::TNode()
{
    try
    {
        value = new TDate();
    }
    catch(bad_alloc)
    {
        cout << "\n Cannot allocate memory for NODE";
    }

    next = NULL;
    prev = NULL;
}
//------------------------------------------------------------------
TNode::TNode(TDate * date)
{
     try
    {
        value = new TDate(*date);
    }
    catch(bad_alloc)
    {
        cout << "\n Cannot allocate memory for NODE";
    }
    next = NULL;
    prev = NULL;
}
//------------------------------------------------------------------
TNode::~TNode()
{
    if(this == NULL)
    {
        throw "\nCannot delete NODE couse it is NULL";
    }
//    if(! (value)
//    {
//        throw "\nCannot delete fields of NODE couse they are NULL";
//    }
    delete value;
    delete next;
    delete prev;
}
//------------------------------------------------------------------
TNode & TNode::operator=(TNode& node)
{
    if(this == &node)
        throw "\n Cannot use operation= to itself";
    this->value = node.value;
    this->next = node.next;
    this->prev = node.prev;

    return *this;
}
//------------------------------------------------------------------
TList::TList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}
//------------------------------------------------------------------
TList::TList(TNode * node)
{
    head = new TNode;

    head->value = node->value;
    head->prev = NULL;
    head->next = NULL;

    tail = head;
    ++size;
}
//------------------------------------------------------------------
TList::TList(TList & list)
{
    head = new TNode;
    tail = new TNode;

    head = list.head;
    tail = list.tail;
    size = list.size;
}
//------------------------------------------------------------------
TList::~TList()
{
    Clear();
}
//------------------------------------------------------------------
bool TList::Empty()
{
    return (head == NULL);
}
//------------------------------------------------------------------
bool TList::CheckThisNull()
{
    return (this == NULL);
}
//------------------------------------------------------------------

//------------------------------------------------------------------
void TList::PushFront(TNode * k)
{
    if(CheckThisNull())
    {
        throw "\nList is NULL cannot PushFront";
    }
    else if(k == NULL)
        throw "\nArgument of PushFront is NULL";

    TNode * temp = this->head;

    try
    {
        if(Empty())
        {
            head = new TNode();

            head->value = k->value;
            head->prev = NULL;
            tail = head;
            head->next = tail;
        }
        else
        {
            temp = tail;
            tail = new TNode(); // make alocator
            tail->next = NULL;
            tail->value = k->value;
            tail->prev = temp;
        }
    }
    catch(bad_alloc)
    {
        cout << "Bad alloc in PUSH";
    }
    size++;
}
//------------------------------------------------------------------
TNode* TList::PopFront()
{
    if(CheckThisNull())
    {
        throw "\nList is NULL cannot PopFront";
    }

    TNode* temp_return;

    if(!Empty())
    {
        TNode * temp = head;
        head = head->next;

        temp_return = temp;
//        delete temp;
        size--;

    }
    else
    {
        cout << "\nList is empty, cannot POP" << endl;
        return 0;
    }
    return temp_return;

}
//------------------------------------------------------------------
TNode * TList::GetHead()
{
    if(CheckThisNull())
    {
        throw "\nList is NULL cannot GetHead";
    }
    return this->head;
}
//------------------------------------------------------------------
TNode * TList::GetTail()
{
    if(CheckThisNull())
    {
        throw "\nList is NULL cannot GetTail";
    }
    return this->tail;
}
//------------------------------------------------------------------
void TList::Clear()
{
    if(CheckThisNull())
    {
        throw "\nList is NULL cannot Clear list";
    }
    TNode * temp = head;
    while(head != NULL)
    {
        head = head->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}
//------------------------------------------------------------------
void TList::SortByDate()
{
    TNode * temp = head;
    TNode * swap1,*swap2,*cu;
    while(temp->next != NULL)
    {
        swap2 = temp->next;
        if( strcmp(temp->value->DateToStr(),swap2->value->DateToStr()) < 0 )
        {
            if(temp == head)
            {
                swap2 = temp->next;
                swap2->prev = NULL;
                temp->next = swap2->next;
                swap2->next = temp;
            }
            else
            {
                swap1 = temp->prev;

                swap1->next = swap2;
                swap2->prev = swap1;
                temp->next = swap2->next;
                temp->prev = swap2;
                swap2->next = temp;

            }
        }
        tail = temp;
        temp = temp->next;
    }

}
