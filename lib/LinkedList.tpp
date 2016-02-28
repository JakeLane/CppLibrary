/**
 * @file LinkedList.tpp
 * @author Jake Lane <me@jakelane.me>
 *
 * @section DESCRIPTION
 *
 * Template implementation of a Linked list
 * See Wikipedia for more details at https://en.wikipedia.org/wiki/Linked_list
 */

#include <iostream>
#include <sstream>
#include <stdexcept>

// Constructor
template<class T>
LinkedList<T>::LinkedList(): _head(NULL), _tail(NULL) {}

// Destructor
template<class T>
LinkedList<T>::~LinkedList() {
	// O(n)
	Node<T>* ptr = _head;
	Node<T>* temp = NULL;
	// Free up memory from each node
	while (ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}

// Return the node at index i
template<typename T>
Node<T>* LinkedList<T>::getNode(int i){
	// O(n)
	int j = 0;
	Node<T>* temp = _head;

	while (j < i) {
		temp = temp->next;
		if (temp == NULL) {
			return temp;
		}
		j++;
	}
	return temp;
}

// Get the first object in list
template <typename T>
T LinkedList<T>::getFirst() {
	// O(1)
	// Undefined behaviour if _head is nullptr
	return _head->data;
}

// Get the last object in list
template<class T>
T LinkedList<T>::getLast() {
	// O(1)
	// Undefined behaviour if _head is nullptr
	return _tail->data;
}

// Get the object at index i
template<class T>
T LinkedList<T>::get(int i) {
	// O(n)
	return getNode(i)->data;
}

// Set the first object in list
template <typename T>
void LinkedList<T>::setFirst(T object) {
	// O(1)
	return getFirst() = object;
}

// Set the last object in list
template<class T>
void LinkedList<T>::setLast(T object) {
	// O(1)
	return getLast() = object;
}

// Set the object at index i
template<class T>
void LinkedList<T>::set(int i, T object) {
	// O(n)
	return get(i) = object;
}

// Push to the tail
template<class T>
void LinkedList<T>::push(T object) {
	// O(1)
	if (_tail != NULL) {
		_tail->next = new Node<T>();
		_tail->next->data = object;
		_tail = _tail->next;
	} else {
		_head = new Node<T>();
		_head->data = object;
		_tail = _head;
	}
}

// Add object to the head
template<class T>
void LinkedList<T>::addFirst(T object) {
	// O(1)
	if (_head != NULL) {
		// There is a head, make a new node in front of it
		Node<T>* new_head = new Node<T>();
		new_head->data = object;
		new_head->next = _head;
		_head = new_head;
	} else {
		// No head, set the head and tail to the new node
		_head = new Node<T>();
		_head->data = object;
		_tail = _head;
	}
}

// Add object to index
template<class T>
void LinkedList<T>::add(int i, T object) {
	// O(n)
	if (_head != NULL) {
		Node<T>* new_node = new Node<T>();
		new_node->data = object;

		if (_head->next != NULL) {
			// There are at least 2 nodes
			Node<T>* previous_node = getNode(i - 1);
			new_node->next = previous_node->next;
			previous_node->next = new_node;
		} else {
			// There is only one node, the head
			new_node->next = _head;
			_tail = _head;
			_head = new_node;
		}
	} else {
		// No head, set the head and tail to the new node
		_head = new Node<T>();
		_head->data = object;
		_tail = _head;
	}
}

// Pop from the head
template<class T>
T LinkedList<T>::pop() {
	// O(1)
	// Undefined behaviour if _head is nullptr
	Node<T>* temp = _head;
	_head = _head->next;
	T temp_data = temp->data;
	delete temp;
	return temp_data;
}

// Remove last object
template<class T>
T LinkedList<T>::removeLast() {
	// O(n)
	// Undefined behaviour if _tail is nullptr
	Node<T>* temp = _tail;

	if (_head != _tail) {
		Node<T>* ptr = _head;
		while (ptr->next != _tail) {
			ptr = ptr->next;
		}
		ptr->next = NULL;
		ptr = _tail;
	} else {
		_head = NULL;
		_tail = NULL;
	}

	T temp_data = temp->data;
	delete temp;
	return temp_data;
}

// Remove object from index
template<class T>
T LinkedList<T>::remove(int i) {
	// O(n)
	// Undefined behaviour if head is nullptr
	if (i > 0) {
		// There is at least 1 previous node
		Node<T>* previous_node = getNode(i - 1);
		Node<T>* temp = previous_node->next;
		if (temp == _tail) {
			_tail = previous_node;
		}
		if (temp != NULL) {
			previous_node->next = temp->next;
		} else {
			previous_node->next = NULL;
		}
		T temp_data = temp->data;
		delete temp;
		return temp_data;
	} else {
		// We are at the head
		Node<T>* temp = _head;
		if (_head->next != NULL) {
			// There are at least two nodes
			_head = _head->next;
		} else {
			// There is only one node, the head
			_head = NULL;
			_tail = NULL;
		}

		T temp_data = temp->data;
		delete temp;
		return temp_data;
	}
}

// Return true if empty
template<class T>
bool LinkedList<T>::empty() {
	return _head == NULL;
}

// Pop from the head
template<class T>
int LinkedList<T>::size() {
	if (_head != NULL) {
		int i = 1;
		Node<T>* ptr = _head->next;
		while (ptr != NULL){
			i++;
			ptr = ptr->next;
		}
		return i;
	} else {
		// List is empty, return 0
		return 0;
	}
}
