#include <iostream>

//////////////////////////////////////////////////////////////NODE CLASS//////////////////////////////////////////////////////////////
template<typename X>
class Node
{
	X data;
	Node *next_element = nullptr, *previous_element = nullptr;

public:
	Node() {};
	Node(X value)
	{
		data = value;
	}
	~Node() 
	{
		delete next_element, previous_element;
	}

	void set_value(X value);
	X get_value();

	void set_next(Node *next);
	Node *get_next();

	void set_previous(Node *previous);
	Node *get_previous();

};

template<typename X>
void Node<X>::set_value(X value)
{
	data = value;
	return;
}

template<typename X>
X Node<X>::get_value()
{
	return data;
}

template<typename X>
void Node<X>::set_next(Node<X> *next)
{
	next_element = next;
	return;
}

template<typename X>
Node<X> *Node<X>::get_next()
{
	return next_element;
}

template<typename X>
void Node<X>::set_previous(Node<X> *previous)
{
	previous_element = previous;
	return;
}

template<typename X>
Node<X> *Node<X>::get_previous()
{
	return previous_element;
}

//////////////////////////////////////////////////////////////LIST CLASS//////////////////////////////////////////////////////////////
template<typename X>
class Linked_list
{
	size_t size = 0;
	Node<X> *first_element = nullptr, *last_element = nullptr;

public:
	Linked_list(X value)
	{
		Node<X> *element = new Node<X>(value);
		first_element = element;
		last_element = element;
		++size;
	}
	Linked_list() {};
	~Linked_list() {};

	void insert(X value, size_t n_pos);

	void print();

	void push_back(X value);
	void push(X value);

	X pop_back();
	X pop();

	//friend ostream &operator<<(ostream &os, const Linked_list<typename X> &List);
};

template<typename X>
void Linked_list<X>::push_back(X value)
{
	if (!size)
	{
		Node<X> *new_element = new Node<X>(value);
		first_element = new_element;
		last_element = new_element;
		++size;
		return;
	};

	Node<X> *new_element = new Node<X>(value);
	last_element->set_next(new_element);
	new_element->set_previous(last_element);
	last_element = new_element;
	++size;
	return;
}
template<class X>
void Linked_list<X>::push(X value)
{
	Node<X> *new_element = new Node<X>(value);
	new_element->set_next(first_element);
	first_element = new_element;
	++size;
}

template<typename X>
X Linked_list<X>::pop()
{
	X value = first_element->get_value();
	first_element = first_element->get_next();
	first_element->set_previous(nullptr);
	--size;
	return value;
}
template<class X>
X Linked_list<X>::pop_back()
{
	X value = last_element->get_value();
	last_element = last_element->get_previous();
	last_element->set_next(nullptr);
	--size;
	return value;
}

template<typename X>
void Linked_list<X>::insert(X value, size_t n_pos)
{
	if (n_pos > size)
	{
		std::cout << "Index " << n_pos << " out of bounds!( " << size << " elements total)\n";
		return;
	}

	size_t sw = 0;
	n_pos < size / 2 ? sw = 0 : sw = 1;

	Node<X> *tmp;
	size_t curr_pos;
	Node<X> *new_element = new Node<X>(value);

	switch (sw)
	{
	case 0:
		tmp = first_element;
		curr_pos = 0;

		while (curr_pos < n_pos)
		{
			tmp = tmp->get_next();
			++curr_pos;
		}

		new_element->set_next(tmp->get_next());
		tmp->set_next(new_element);
		new_element->set_previous(tmp);
		++size;
		break;

	case 1:
		tmp = last_element;
		curr_pos = size;

		while (curr_pos >= n_pos - 1)
		{
			tmp = tmp->get_previous();
			--curr_pos;
		}

		new_element->set_next(tmp->get_next());
		tmp->set_next(new_element);
		new_element->set_previous(tmp);
		++size;
		break;
	}

	return;
}

template<typename X>
void Linked_list<X>::print()
{
	Node<X> *current_element = first_element;
	while (current_element)
	{
		std::cout << current_element->get_value() << " ";
		current_element = current_element->get_next();
	}
	std::cout << "\n";
	return;
}



