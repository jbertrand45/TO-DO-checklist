#ifndef LINKED_LIST
#define LINKED_LIST

#include "listinterface.h"
#include "node.h"

template <class ItemType>
class LinkedList : public ListInterface<Itemtype>
{
    private:
    Node<ItemType>* headptr;

    int itemCount;

    Node<ItemType>* getNodeAt (int position) const;

    public:

    LinkedList();
    LinkedList (const LinkedList<ItemType>& aList);
    virtual ~LinkedList ();
    bool isEmpty() const;
    int getLength() const;
    bool remove (int position);
    void clear();

    ItemType getEntry (int position) const
        throw(PrecondViolatedExcept);

    ItemType replace (int postion, const ItemType& newEntry)
        throw(PrecondViolatedExcept);
};

#endif



