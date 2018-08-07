// Class to build Stack Data Structures
template <class ItemType>
struct Node;

template<class ItemType>
class StackType
{
public:
	StackType();
	~StackType();
	void MakeEmpty();
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ItemType item);
	void Pop(ItemType& item);

private:
	Node<ItemType>* topPtr;
};

template <class ItemType>
struct Node
{
	ItemType info;
	Node<ItemType>* next;
};

template<class ItemType>
StackType<ItemType>::StackType()
{
	topPtr = NULL;
}

template <class ItemType>
StackType<ItemType>::~StackType()
{
	Node<ItemType>* tempPtr;
	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

template<class ItemType>
void StackType<ItemType>::Pop(ItemType& item)
{
	Node<ItemType>* tempPtr;
	item = topPtr->info;
	tempPtr = topPtr;
	topPtr = topPtr->next;
	delete tempPtr;
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
	Node<ItemType>* location;
	location = new Node<ItemType>;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
	Node<ItemType>* ptr;
	ptr = new Node<ItemType>;
	if (ptr == NULL)
		return true;
	else
	{
		delete ptr;
		return false;
	}
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	return (topPtr == NULL);
}


template <class ItemType>
void StackType<ItemType>::MakeEmpty()
{
	Node<ItemType>* tempPtr;

	while (topPtr != NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}
