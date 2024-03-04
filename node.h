#ifndef NODE
#define NODE

template<class ItemType>
class Node{
	ItemType item; // A data item
	Node<ItemType>* next; // Points to next node
public:
	Node() : next(nullptr) {}
	Node(const ItemType& anItem) : item(anItem), next(nullptr) {}
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
		item(anItem), next(nextNodePtr) {}

	void setItem(const ItemType& anItem) {
		item = anItem;
	}

	void setNext(Node<ItemType>* nextNodePtr) {
		next = nextNodePtr;
	}

	ItemType getItem() const {
		return item;
	}

	Node<ItemType>* getNext() const {
		return next;
	}
}; 
#endif
