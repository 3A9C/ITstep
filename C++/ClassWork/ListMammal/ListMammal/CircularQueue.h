#include "List.h"

template <class T>
class CircularQueue : public List<T> {
public:
	CircularQueue() : List() {}
	//~CircularQueue() 
	class iterator : public List<T>::iterator {
	public:
		iterator() : List<T>::iterator() {};
		iterator( List<T>::Node* node, CircularQueue* host) : List<T>::iterator(node, host) {};

		iterator& operator++() { // префиксный ++
			if ((current == nullptr) && (host == nullptr)) {
				throw 1;
			}
			current = current->next;
			if (current == nullptr) {
				current = host->Begin;
			}
			return (*this);
		}

		

		iterator& operator++(int) { // постфиксный
			return ++(*this);
		}

	};


	iterator begin() {
		return iterator(Begin, this);
	}
	iterator end() {
		return iterator(nullptr, this);
	}


};