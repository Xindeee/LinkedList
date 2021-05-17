#include <exception>
#include "linkedlist.h"
namespace MyLinkedList {
	Node::Node() {
		val = 0;
		prev = nullptr;
		next = nullptr;
	}
	Node::Node(int valIn) {
		val = valIn;
		prev = nullptr;
		next = nullptr;
	}
	Node::Node(int valIn,Node* prevIn, Node* nextIn) {
		val = valIn;
		prev = prevIn;
		next = nextIn;
	}

	int Node::getValue() {
		return val;
	}
	LinkedList::LinkedList() {
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	LinkedList::~LinkedList() {
		Node* rm;
		while (last != nullptr) {
			rm = last;
			last = last->prev;
			delete rm;
		}
		first = nullptr;
	}
	LinkedListIterator LinkedList::insert(int val,const LinkedListIterator& nodeIter) {
		Node* nodeIn = nodeIter.ptr;
		if (nodeIn == nullptr) {
			/*Node* a = new Node(val);
			return LinkedListIterator(a);*/
			throw LinkedListException();
		}
		else{
			Node* a = new Node(val, nodeIn, nodeIn->next);
			if (nodeIn->next != nullptr) {
				nodeIn->next->prev = a;
			}
			nodeIn->next = a;
			if (nodeIn==last){
				last = a;
			}
			++count;
			return LinkedListIterator(a);
		}
	}
	LinkedListIterator LinkedList::insert(int val, int posIn) {
		if (posIn<0 || posIn>count) {
			throw LinkedListException();
		}
		else if (posIn == 0) {
			if (first != nullptr ) {
				Node* a = new Node(val, nullptr, first);
				first->prev = a;
				first = a;
				++count;
				return LinkedListIterator(a);
			}
			else {
				addFirst(val);
			}
		}
		else {
			if(first==nullptr){
				/*Node* a = new Node(val, nullptr, nullptr);
				return insert(val, a);*/
				throw LinkedListException();
			}
			else {
				Node* searchNode = first;
				for (int i = 1;i < posIn;i++) {
					if (searchNode->next != nullptr) {
						searchNode = searchNode->next;
					}
					else {
						throw LinkedListException();
					}
				}
				return insert(val, searchNode);
			}
		}
	}

	LinkedListIterator::LinkedListIterator() {
		ptr = nullptr;
	}
	LinkedListIterator::LinkedListIterator(Node* nodeIn) {
		ptr = nodeIn;
	}
	int LinkedListIterator::operator*() {
		if (ptr == nullptr) {
			throw LinkedListException();
		}
		else {
			return ptr->getValue();
		}
	}
	void LinkedListIterator::operator++() {
		if (ptr != nullptr) {
			ptr = ptr->next;
		}
		else {
			throw LinkedListException();
		}
	}
	void LinkedListIterator::operator--() {
		if (ptr != nullptr) {
			ptr = ptr->prev;
		}
		else {
			throw LinkedListException();
		}
	}
	bool LinkedListIterator::operator==(int valIn) {
		if (ptr == (Node*)valIn) {
			return true;
		}
		else {
			return false;
		}
	}
	bool LinkedListIterator::operator==(const LinkedListIterator& iterIn) {
		if (ptr == iterIn.ptr) {
			return true;
		}
		else {
			return false;
		}
	}
	bool LinkedListIterator::operator!=(int valIn) {
		return!((*this) == valIn);
	}
	bool LinkedListIterator::operator!=(const LinkedListIterator& iterIn) {
		return!((*this) == iterIn);
	}
	bool operator ==(int valIn, const LinkedListIterator& iterIn) {
		if (iterIn.ptr == (Node*)valIn) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator ==(const LinkedListIterator& iter1In, const LinkedListIterator& iter2In) {
		if (iter1In.ptr == iter2In.ptr) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator !=(int valIn, const LinkedListIterator& iterIn) {
		return!(valIn == iterIn);
	}
	bool operator !=(const LinkedListIterator& iter1In, const LinkedListIterator& iter2In) {
		return!(iter1In == iter2In);
	}
	const char* LinkedListException::what() const throw() {
		return "LinkedListException";
	}

	void LinkedList::addFirst(int valIn) {
		if (first == nullptr) {
			first = new Node(valIn);
			last = first;
			++count;
		}
		else {
			Node* a = new Node(valIn, nullptr, first);
			first->prev = a;
			first = a;
			++count;
		}
	}
	void LinkedList::addLast(int valIn) {
		if (first == nullptr) {
			first = new Node(valIn);
			last = first;
			++count;
		}
		else {
			Node* a = new Node(valIn, last, nullptr);
			last->next = a;
			last = a;
			++count;
		}
	}
	void LinkedList::removeAt(int posIn) {
		if (posIn<1 || posIn>count) {
			throw LinkedListException();
		}
		else {
			if (posIn == 1) {
				removeFirst();
			}
			else if(posIn==count) {
				removeLast();
			}
			else {
				Node* search = first;
				for (int i = 1;i < count;i++) {
					if(i<posIn){
						search = search->next;
					}					
				}
				search->prev->next = search->next;
				search->next->prev = search->prev;
				delete search;
				--count;
			}
		}
	}
	void LinkedList::remove(const LinkedListIterator& nodeIter){
		Node* nodeIn = nodeIter.ptr;
		if (nodeIn!=nullptr) {
			if (nodeIn == first) {
				first = first->next;
			}
			if (nodeIn == last) {
				last = last->prev;
			}
			if (nodeIn->prev != nullptr) {
				nodeIn->prev->next = nodeIn->next;
			}
			if (nodeIn->next != nullptr) {
				nodeIn->next->prev = nodeIn->prev;
			}
			delete nodeIn;
			--count;
		}
		else {
			throw LinkedListException();
		}
	}
	void LinkedList::removeFirst() {
		if (first != nullptr) {
			if (first->next != nullptr) {
				Node* a = first;
				first = first->next;
				first->prev = nullptr;
				delete a;
				--count;
			}
			else {
				delete first;
				first = nullptr;
				last = nullptr;
				--count;

			}
		}
		else {
			throw LinkedListException();
		}
	}
	void LinkedList::removeLast() {
		if (last != nullptr) {
			if (last->prev != nullptr) {
				Node* a = last;
				last = last->prev;
				last->next = nullptr;
				delete a;
				--count;
			}
			else {
				delete last;
				first = nullptr;
				last = nullptr;
				--count;

			}
		}
		else {
			throw LinkedListException();
		}
	}
	LinkedListIterator LinkedList::find(int valIn) {
		Node* searchNode = first;
		while (searchNode != nullptr) {
			if (searchNode->val == valIn) {
				return LinkedListIterator(searchNode);
			}
			searchNode = searchNode->next;
		}
		return LinkedListIterator();
	}
	LinkedListIterator LinkedList::find(int valIn, const LinkedListIterator& iterIn) {
		Node* searchNode = iterIn.ptr;
		while (searchNode != nullptr) {
			if (searchNode->val == valIn) {
				return LinkedListIterator(searchNode);
			}
			searchNode = searchNode->next;
		}
		return LinkedListIterator();
	}
}