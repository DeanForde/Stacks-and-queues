// Class to build Queue Data Structures
#include "stdafx.h"
#include <iostream>
template <class ItemType>
struct NodeType;
                                             
template<class ItemType>
class QueType
{
public:
	QueType();
	~QueType();
	void MakeEmpty();
	bool QueType<ItemType>::IsEmpty() const;
	void QueType<ItemType>::PrintQueue();
	void QueType<ItemType>::Dequeue(ItemType& item);
	void QueType<ItemType>::Enqueue(ItemType newItem);
	void QueType<ItemType>::DeleteRear();

private:
	NodeType<ItemType>* qFront;
	NodeType<ItemType>* qRear;
};

template <class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>* next;
};

template<class ItemType>
QueType<ItemType>::QueType()
{
	qFront = NULL;
	qRear = NULL;
}

template<class ItemType>
QueType<ItemType>::~QueType()
{
	MakeEmpty();
}

template<class ItemType>
void QueType<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempPtr;

	while (qFront != NULL)
	{
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qRear = NULL;
}



template<class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
	return (qFront == NULL);
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item) 
{
	NodeType<ItemType>* tempPtr;
	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;
	if (qFront == NULL)
		qRear = NULL;
	delete tempPtr;
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
	NodeType<ItemType>* newNode;

	newNode = new NodeType<ItemType>;
	newNode->info = newItem;
	newNode->next = NULL;
	if (qRear == NULL)
		qFront = newNode;
	else
		qRear->next = newNode;
	qRear = newNode;
}

template<class ItemType>
void QueType<ItemType>::PrintQueue()
{
	NodeType<ItemType>* tempPtr;
	tempPtr = qFront;
	while (tempPtr != NULL)
	{
		cout << tempPtr->info << "\n";
		tempPtr = tempPtr->next;
	}
}
