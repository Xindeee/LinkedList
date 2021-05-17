#include "test.h"
using namespace MyLinkedList;
void test() {
	LinkedList l;
	l.addFirst(1);
	l.removeFirst();
	l.addFirst(1);
	l.removeLast();
	l.addFirst(1);
	l.remove(l.find(1));
	l.addFirst(1);
	l.removeAt(1);

	l.addLast(1);
	l.removeFirst();
	l.addLast(1);
	l.removeLast();
	l.addLast(1);
	l.remove(l.find(1));
	l.addLast(1);
	l.removeAt(1);
	
	l.insert(1, 0);
	l.insert(2, 1);
	l.insert(3, 2);
	for (auto iter = l.begin();iter != l.end();++iter) {
		std::cout << (*iter) << std::endl;
	}
	l.removeAt(2);
	l.insert(2, 1);
	l.remove(l.find(2));
	for (auto iter = l.begin();iter != l.end();++iter) {
		std::cout << (*iter) << std::endl;
	}
	l.insert(2, 1);
	l.removeLast();
	l.removeLast();
	l.removeLast();
	l.insert(1, 0);
	l.insert(2, 1);
	l.insert(3, 2);
	l.removeFirst();
	l.removeFirst();
	l.removeFirst();
	l.insert(1, 0);
	l.insert(2, 1);
	l.insert(3, 2);
	for (auto iter = l.begin();iter != l.end();++iter) {
		std::cout << (*iter) << std::endl;
	}
	l.removeAt(3);
	l.removeAt(1);
	l.removeAt(1);
	for (auto iter = l.begin();iter != l.end();++iter) {
		std::cout << (*iter) << std::endl;
	}
}