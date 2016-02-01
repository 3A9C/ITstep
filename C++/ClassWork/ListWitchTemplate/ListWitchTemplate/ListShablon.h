#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;




template < class T>
class List { //data structure
private:
	struct Node { //container
		int  data;
		Node *next;
	};

	Node *first;
	size_t size;
public:
	class Iterator {
	private:
		Node *current;
	public:
		Iterator() : current(nullptr) {};
		Iterator(Node *current) { this->current = current; };
		Iterator& operator++() { current = current->next; return *this; };
		int& operator*() { return current->data; };
		bool operator==(const Iterator& what) { return current == what.current; };
		bool operator!=(const Iterator& what) { return !(*this == what); };
	};


	List() : first(nullptr), size(0) {}; //initialization list (now we can initialize constants and call different constructors)
	List(const List& orig) {
		first = nullptr;
		Node* temp = orig.first;
		for (size_t i = 0; i < orig.size; ++i, temp = temp->next)
			pushBack(temp->data);
		size = orig.size;
	}

	~List() {
		while (size > 0)
			popFront();
	}

	Iterator begin() { return Iterator(first); };
	Iterator end() { return Iterator(nullptr); };

	List& pushFront(int data) {
		Node *temp = new Node;
		temp->data = data;
		temp->next = first;
		first = temp;
		++size;

		return *this;
	}

	List& pushBack(int data) {
		if (first == nullptr)
			pushFront(data);
		else {
			Node *temp = new Node;
			temp->data = data;
			temp->next = nullptr;

			Node *temp2 = first;
			while (temp2->next != nullptr)
				temp2 = temp2->next;
			temp2->next = temp;

			++size;
		}
		return *this;
	}

	List& pushInIndex(int data, size_t index) {
		if (index >= 0 && index < size) {
			if (index == 0)
				pushFront(data);
			else if (index == size - 1)
				pushBack(data);
			else {
				Node *temp = new Node;
				temp->data = data;

				Node *temp2 = first;
				for (size_t i = 0; i < index - 1; ++i)
					temp2 = temp2->next;

				temp->next = temp2->next;
				temp2->next = temp;

				++size;
			}
		}
		return *this;
	}

	List& popFront() {
		if (first == nullptr)
		{
			throw 1;
		}
		Node *temp = first;
		first = first->next;
		delete temp;
		--size;
		return *this;
	}

	List& popBack() {
		if (first != nullptr) {
			if (first->next == nullptr)
				popFront();
			else {
				Node *temp = first;
				while (temp->next->next != nullptr)
					temp = temp->next;
				free(temp->next);
				temp->next = nullptr;
				--size;
			}
		}
		return *this;
	}

	List& popFromIndex(size_t index) {
		if (index >= 0 && index < size) {
			if (index == 0)
				popFront();
			else if (index == size - 1)
				popBack();
			else {
				Node *temp = first;
				for (size_t i = 0; i < index - 1; ++i)
					temp = temp->next;

				Node *nodeToDelete = temp->next;

				temp->next = temp->next->next;
				delete nodeToDelete;

				--size;
			}
		}
		return *this;
	}

	size_t getSize() { //getter method
		return size;
	}

	void printAll() {
		Node *temp = first;
		cout << "{";
		for (size_t i = 0; i < size; ++i, temp = temp->next) {
			cout << temp->data;
			if (i != size - 1)
				cout << ", ";
		}
		cout << "}" << endl;
	}

	int& operator[](size_t index) {
		if (index < size) {
			Node *temp = first;
			for (size_t i = 0; i < index; ++i)
				temp = temp->next;
			return temp->data;
		}
		cout << "Error." << endl;
		return junk;
	}

	List& operator=(const List& orig) {
		while (size > 0)
			popFront();
		Node* temp = orig.first;
		for (size_t i = 0; i < orig.size; ++i, temp = temp->next)
			pushBack(temp->data);
		size = orig.size;
		return *this;
	}
};
