#include "listimplementation.h"
#include "node.h"
#include "listinterface.h"



template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
    assert((position >= 1) && (position <= itemCount));

    Node<ItemType>* curPtr = headPtr;
    for (int i = 1; i < position; ++i) {
        curPtr = curPtr->getNext();
    }

    return curPtr;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept) {
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet) {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    } else {
        std::string message = "getEntry() called with an empty list or invalid position.";
        throw(PrecondViolatedExcept(message));
    }
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

    if (ableToInsert) {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        if (newPosition == 1) {
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        } else {
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }

        itemCount++;
    }

    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= itemCount);

    if (ableToRemove) {
        Node<ItemType>* curPtr = nullptr;

        if (position == 1) {
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        } else {
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }

        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;
    }

    return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear()
 {
    while (!isEmpty()) {
        remove(1);
    }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() 
{
    clear();
}




