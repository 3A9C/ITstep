#include "List.h"

// резервируем место под статическое поле
int List::junk;


List& List::push_front(int data) {
	Node *element;
	element = new Node;
	element->data = data;
	element->next = first;
	first = element;
	++size;
	return *this;
}


List &List::pop_front()
{
	if (first == nullptr)
		return *this;
	Node *temp = first;
	first = first->next;
	delete temp;
	--size;
	return *this;
}
int& List::operator[](size_t index){
	if (index < size){	//такой элемент есть
		Node* temp = first;
		for (size_t i = 0; i<index; i++){
			temp = temp->next;
		}
		return temp->data;
	}
	return junk;
}

List::~List() {
	while (size > 0) {
		pop_front();
	}
}