#include <new>
#include "DirectList.h"



// standart
List &List::PushFront(void *element)
{
	Node *new_element = new Node;
	new_element->data = new char[element_size];
	new_element->data = element;

	// connect
	new_element->previous = nullptr;
	new_element->next = Begin;
	if (Begin != nullptr)
		Begin->previous = new_element; //ïðèâÿçûâàåì ïåðâûé ýëåìåíò ê íîâîìó

	Begin = new_element; //ïåðåìåøàåì Begin íà íà÷àëî
	if (End == nullptr)
		End = new_element; //ñòàâèì êîíåö íà íîâûé ýëåìåíò
	++element_count;
	return *this;
}
List &List::PopFront()
{
	if (element_count == 0)
		throw 0;
	Node *temp = Begin;
	Begin = temp->next;
	//delete temp->data;????????
	delete temp;
	if (element_count == 1)
		End = nullptr;
	else
		Begin->previous = nullptr;
	--element_count;
	return *this;
}
List &List::PushEnd(void *element)
{
	Node *new_element = new Node;
	new_element->data = new char[element_size];
	new_element->data = element;
	new_element->next = nullptr;
	new_element->previous = End;
	End->next = new_element;
	End = new_element;
	if (element_count == 0)
		Begin = new_element;
	++element_count;
	return *this;
}
List &List::PopEnd()
{
	if (element_count == 0)
		throw 0;
	Node *temp = End;
	End->next = nullptr;
	if (element_count = 1)
	{
		Begin = nullptr;
		End = nullptr;
	}
	else
		End = End->previous;
	//delete temp->data;???????
	delete temp;
	--element_count;
	return *this;
}

List::Node *List::operator[](int index)
{
	if (index >= element_count)
		throw 1;
	Node *temp;
	if (index <= element_count / 2)
	{
		temp = End;
		for (int i = 0; i < index; i++)
			temp = temp->previous;
	}
	else
	{
		temp = Begin;
		for (int i = element_count - 1; i > index; i--)
			temp = temp->next;
	}
	return temp;

}
List &List::operator=(const List &source)
{
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

List &List::Delete(int index)
{
	if (index >= element_count || index < 0)
		throw 1;
	if (index == 0)
		PopFront();
	else if (index == element_count - 1)
		PopEnd();
	else
	{
		Node *temp = this->operator[](index);
		Node *help_next = temp->next;
		(temp->next)->previous = temp->previous;
		(temp->previous)->next = help_next;
		delete temp;
	}
	return *this;
}
List &List::Reverse()
{
	Node *temp = this->Begin, *temp_previous;
	this->Begin = this->End;
	this->End = temp;
	for (int i = 0; i < element_count; i++, temp = temp->next)
	{
		temp_previous = this->Begin->previous;
		this->Begin->previous = this->Begin->next;
		this->Begin->next = temp_previous;
	}
	return *this;
}


// ctor
List::List(const List &orig)
{
	element_size = orig.element_size;
	element_count = orig.element_count;
	Node *temp = Begin;
	for (int i = 0; i < element_count; i++, temp = temp->next)
	{
		PushEnd(temp->data);
	}
}

// dtor
List::~List()
{
	while (element_count)
		PopFront();
}
