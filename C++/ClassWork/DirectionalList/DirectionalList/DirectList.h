#pragma once
#include <iostream>
#include <exception>

using namespace std;

typedef void* INT;

class List
{
private:
	struct Node
	{
		void *data;
		Node *next;
		Node *previous;
	};
public:

	class iterator {
	private:
		Node* current;
	public:
		iterator(Node* arg) : current(arg) {};
		iterator() :iterator(nullptr) {};
		INT & operator*() {
			if (current == nullptr) {
				throw invalid_argument(
					"In List::iterator::operator*() : invalid iterator");
			}
			return current->data;
		}
		iterator& operator++() {
			if (current == nullptr) {
				throw invalid_argument(
					"In List::iterator::operator*() : invalid iterator");
			}
			current = current->next;
			return (*this);
		}

		bool operator==(const iterator &i) const{
			return current == i.current;
		}

		bool operator!=(const iterator &i) const{
			return current != i.current;
		}
	};  // end of List::iterator

	iterator begin() {
		return iterator(Begin);
	}
	iterator end() {
		return iterator(nullptr);
	}

	Node *Begin;
	Node *End;
	int element_count;
	int element_size;

public:

	size_t ElementCount()
	{
		return element_count;
	}

	// standart
	List &PushFront(void *element);
	List &PopFront();

	List &PushEnd(void *element);
	List &PopEnd();

	Node *operator[](int index);
	List &operator=(const List &source);

	List &Delete(int index);
	List &Reverse();

	// ctor
	List(int size_of_element) : element_size(size_of_element), element_count(0), Begin(nullptr), End(nullptr) {};
	List(const List &orig);

	iterator find(void* value) {
		Node* current;
		current = Begin;
		while (current != nullptr) {
			if (current->data == value) {
				return iterator(current);
			}
			current = current->next;
		}
		return iterator(current);
	}

	// dtor
	~List();


};