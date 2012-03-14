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
TNode::TNode(TNode& node)
{
    if(&node)
    {
        this->value = node.value;
        this->next = node.next;
        this->prev = node.prev;
    }
    else
    {
        throw "\n Cannot call TNode(NULL) - copy constructor";
    }
}
//------------------------------------------------------------------
TNode::~TNode()
{
    if(this == NULL)
    {
        throw "\nCannot delete NODE couse it is NULL";
    }

    delete value; value = NULL;
    delete next; next = NULL;
    delete prev; prev = NULL;
}
//------------------------------------------------------------------
TNode& TNode::operator=(TNode& node)
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
   try
   {
        if( node )
        {
            head = new TNode(*node);
            tail = head;
            ++size;
        }
        else
        {
            throw "\nCannot call TList(NULL)";
        }
   }
   catch(std::bad_alloc)
   {
       cout << "\nCannot allocate memory for TList(TNode*)"<< endl;
   }
   catch(const char* exc)
   {
       cout << exc << endl;
   }
}
//------------------------------------------------------------------
TList::TList(TList& list)
{
    if(&list)
    {
        this->head = new TNode(*(list.head));
        this->tail = new TNode(*(list.tail));
        this->size = list.size;
    }
    else
    {
        throw "\nCannot call TList(NULL) - copy constructor";
    }

}
//------------------------------------------------------------------
TList::~TList()
{
    Clear();
}
//------------------------------------------------------------------
inline bool TList::Empty()
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
void TList::PushBack(TNode * k)
{
    if(CheckThisNull())
    {
        throw "\nList is NULL cannot PushFront";
    }
    else if(k == NULL)
    {
        throw "\nArgument of PushFront is NULL";
    }

    TNode * temp = this->tail;

    try
    {
        if(Empty())
        {
            head = new TNode(*k);
            tail = head;
        }
        else
        {
            temp = tail;
            tail = new TNode(*k);
            temp->next = tail;
            tail->prev = temp;

            if(size == 1)
            {
                head->next = tail;
            }
        }
    }
    catch(bad_alloc)
    {
        cout << "Bad alloc in PUSH";
//        return 0;
    }
    size++;
}
//------------------------------------------------------------------
TDate* TList::PopFront()
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
    return temp_return->value;

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
        throw "\nList is NULL, cannot Clear list";
    }
    TNode * temp;
    while(head != NULL)
    {
        temp = head;
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
    TNode * swap1;
    TNode * swap2;
    TNode * curr;
    TNode * temp;
    size_t s = this->size;
    PrintNodes();
    cout << endl << endl;
    if(size > 1)
    while(s)
    {
        curr = head;
        swap1 = head;
        swap2 = head->next;

        while( curr->next != NULL)
        {
            if(strcmp( swap1->value->DateToStr(),swap2->value->DateToStr()) < 0)
            {
                if(swap1 == head)
                {
                    swap1->next = swap2->next;
                    swap2->next->prev = swap1;
                    swap2->next = swap1;

                    swap2->prev = swap1->prev;
                    swap1->prev = swap2;
                    head = swap2;
                }
                else if(swap2 == tail)
                {
                    swap1->next = swap2->next;
                    swap2->next = swap1;
                    swap1->prev->next = swap2;

                    swap2->prev = swap1->prev;
                    swap1->prev = swap2;
                    tail = swap1;
                }
                else
                {
                    swap1->next = swap2->next;
                    swap2->next->prev = swap1;
                    swap2->next = swap1;
                    swap1->prev->next = swap2;

                    swap2->prev = swap1->prev;
                    swap1->prev = swap2;

                }

                temp = swap1;
                swap1 = swap2;
                swap2 = temp;
//                curr = curr->prev;
            }
            if(curr == tail)
                break;
            //----------------
            curr = curr->next;
            swap1 = swap1->next;
            swap2 = swap2->next;
        }
        PrintNodes();
        cout << s;
        cout << endl;
        s--;
    }
}
void TList::PrintNodes()
{
    TNode * curr = head;
    while(curr)
    {
            printf("\n   <-%p  %p  %p->   ",curr->prev,curr,curr->next);
            curr = curr->next;
    }

}
void TStack::Push(TNode * k)
{
    if(CheckThisNull())
    {
        throw "\nList is NULL cannot PushFront";
    }
    else if(k == NULL)
    {
        throw "\nArgument of PushFront is NULL";
    }

    TNode * temp = this->head;

    try
    {
        if(Empty())
        {
            head = new TNode(*k);
            tail = head;
        }
        else
        {
            temp = head;
            head = new TNode(*k);
            head->next = temp;
            temp->prev = head;

            if(size == 1)
            {
                head->next = tail;
            }
        }
    }
    catch(bad_alloc)
    {
        cout << "Bad alloc in PUSH";
//        return 0;
    }
    size++;


}
