#pragma once
#include <string>

template <class T>
class tree
{
	struct Node{
		Node(const std::string &key_, const T value_ = 0)
		:left(nullptr), right(nullptr), key(key_),
		value(value_){};
		Node *left;
		Node *right;
		T value;
		const std::string key;
	};

	Node *root;


public:
	tree() :root(nullptr){};
	~tree(){
		delete root->left;
		delete root->right;
	};

	T& operator[](const std::string &key)
	{
		Node *current = root;
		Node **pointer = &root;
		// pointer - указатель на место
		// в памяти, где лежит current
		while (current != nullptr){
			if (key < current->key)
			{	//left
				pointer = &(current->left);
				current = current->left;
			}
			else if (key == current->key)
			{	//found
				return current->value;
			}
			else {	//right
				pointer = &(current->right);
				current = current->right;
			}
		} // end of whlie
		// если ничего не найдено
		*pointer = new Node(key);
		return (*pointer)->value;
	}

};