//Вместо операторов ++ -- используем итератор 
#ifndef LINKEDLIST_H 
#define LINKEDLIST_H
namespace MyLinkedList {
	class Node {
	private:
		int val;
		Node* next;
		Node* prev;
	public:
		Node();
		Node(int);
		Node(int, Node*, Node*);
		int getValue();
		

		friend class LinkedList;
		friend class LinkedListIterator;
	};

	class LinkedListIterator {
		Node* ptr;
	public:
		LinkedListIterator();
		LinkedListIterator(Node*);
		int operator*();
		void operator ++();
		void operator --();
		bool operator ==(int);
		bool operator ==(const LinkedListIterator&);
		bool operator !=(int);
		bool operator !=(const LinkedListIterator&);
		friend class LinkedList;
		friend bool operator ==(int, const LinkedListIterator&);
		friend bool operator ==(const LinkedListIterator&, const LinkedListIterator&);
		friend bool operator !=(int, const LinkedListIterator&);
		friend bool operator !=(const LinkedListIterator&, const LinkedListIterator&);
	};
	bool operator ==(int,const LinkedListIterator&);
	bool operator ==(const LinkedListIterator&, const LinkedListIterator&);
	bool operator !=(int, const LinkedListIterator&);
	bool operator !=(const LinkedListIterator&, const LinkedListIterator&);
	class LinkedListException : std::exception{
	public:
		virtual const char* what() const throw();
	};

	class LinkedList {
		Node* first;
		Node* last;
		int count;
	public:
		LinkedList();
		virtual ~LinkedList();
		LinkedListIterator insert(int, const LinkedListIterator&);
		LinkedListIterator insert(int, int);
		void addFirst(int);
		void addLast(int);
		void removeAt(int);
		void remove(const LinkedListIterator&);
		void removeFirst();
		void removeLast();
		LinkedListIterator find(int);
		static LinkedListIterator find(int, const LinkedListIterator&);
		int size() { return count; }
		LinkedListIterator begin() { return LinkedListIterator(first); }
		LinkedListIterator end() { return LinkedListIterator(); }
	};
};



#endif


