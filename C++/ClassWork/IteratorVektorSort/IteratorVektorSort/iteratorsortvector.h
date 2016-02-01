#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
#include "sort.h"

using namespace std;

template <class T>
class Vector
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
	};
public:

	class iterator {
	private:
		Vector* host;
		Node* current;
	public:
		iterator(Node* arg, Vector* host_) : current(arg), host(host_) {};
		iterator() :current(nullptr), host(nullptr) {};
		T& operator*() {
			if (current == nullptr) {
				throw invalid_argument(
					"In Vector::iterator::operator*() : invalid iterator");
			}
			return current->data;
		}
		iterator& operator++() { // префиксный ++
			if (current == nullptr) {
				throw invalid_argument(
					"In Vector::iterator::operator++() : invalid iterator");
			}
			current = current->next;
			return (*this);
		}

		iterator& operator++(int) { // постфиксный
			if (current == nullptr) {
				throw invalid_argument(
					"In Vector::iterator::operator++(int) : invalid iterator");
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

		friend class Vector;
	};  // end of Vector::iterator

	iterator begin() {
		return iterator(Begin, this);
	}
	iterator end() {
		return iterator(nullptr, this);
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
	Vector &PushFront(const T& element)
	{
		Node *new_element = new Node;
		new_element->data = element;

		// connect
		new_element->prev = nullptr;
		new_element->next = Begin;
		if (Begin != nullptr)
			Begin->prev = new_element; //ïðèâÿçûâàåì ïåðâûé ýëåìåíò ê íîâîìó

		Begin = new_element; //ïåðåìåøàåì Begin íà íà÷àëî
		if (End == nullptr)
			End = new_element; //ñòàâèì êîíåö íà íîâûé ýëåìåíò
		++element_count;
		return *this;
	}

	Vector &PopFront(){
		if (element_count == 0)
			throw 0;
		Node *temp = Begin;
		Begin = temp->next;
		//delete temp->data;????????
		delete temp;
		if (element_count == 1)
			End = nullptr;
		else
			Begin->prev = nullptr;
		--element_count;
		return *this;
	}

	T &operator[](int index)
	{
		if (index >= element_count)
			throw 1;
		Node *temp;
		if (index <= element_count / 2)
		{
			temp = End;
			for (int i = 0; i < index; i++)
				temp = temp->prev;
		}
		else
		{
			temp = Begin;
			for (int i = element_count - 1; i > index; i--)
				temp = temp->next;
		}
		return temp;

	}
	Vector &operator=(const Vector &source){
		while (element_count--)
			PopFront();
		element_count = source.element_count;
		element_size = source.element_size;
		Node *temp = source.Begin;
		for (int i = 0; i < element_count; i++, temp = temp->next)
		{
			PushEnd(temp->data);
		}
		return *this;
	}


	// ctor
	Vector() : element_count(0), Begin(nullptr), End(nullptr) {};
	Vector(const Vector &orig){
		element_size = orig.element_size;
		element_count = orig.element_count;
		Node *temp = Begin;
		for (int i = 0; i < element_count; i++, temp = temp->next)
		{
			PushEnd(temp->data);
		}
	}

	iterator find(const T& value) {
		Node* current;
		current = Begin;
		while (current != nullptr) {
			if (current->data == value) {
				return iterator(current, this);
			}
			current = current->next;
		}
		return iterator(nullptr, this);
	}



	Vector& erase(iterator &it) {
		// удаляемый элемент последний
		if (it.current->next == nullptr) {
			End = it.current->prev;
		}
		else {
			it.current->next->prev = it.current->prev;
		}

		// удаляемый элемент первый
		if (it.current->prev == nullptr) {
			Begin = it.current->next;
		}
		else {
			it.current->prev->next = it.current->next;
		}

		delete it.current;
		it.current = nullptr;
		element_count--;

		return (*this);
	}

	// dtor
	~Vector(){
		while (element_count)
			PopFront();
	}


};
