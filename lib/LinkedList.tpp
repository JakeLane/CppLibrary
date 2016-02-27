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

#include "../include/LinkedList.hpp"

template<class T>
LinkedList<T>::LinkedList(): _head(NULL), _tail(NULL) {}

template<class T>
LinkedList<T>::~LinkedList() {
	Node<T>* ptr = _head;
	Node<T>* temp = NULL;
	// Free up memory from each node
	while (ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}

template<typename T>
Node<T>* LinkedList<T>::getNode(int index){
	// O(n)
	int i = 0;
	Node<T>* temp = _head;

	while (i < index) {
		temp = temp->next;
		if (temp == NULL) {
			return temp;
		}
		i++;
	}
	return temp;
}

template <typename T>
T LinkedList<T>::getFirst() {
	// O(1)
	// TODO Throw exception on empty
	return _head->data;
}

template<class T>
T LinkedList<T>::getLast() {
	// O(1)
	// TODO Throw exception on empty
	return _tail->data;
}

template<class T>
T LinkedList<T>::get(int index) {
	// O(n)
	return getNode(index)->data;
}

template <typename T>
void LinkedList<T>::setFirst(T object) {
	// O(1)
	return getFirst() = object;
}

template<class T>
void LinkedList<T>::setLast(T object) {
	// O(1)
	return getLast() = object;
}

template<class T>
void LinkedList<T>::set(int index, T object) {
	// O(n)
	return get(index) = object;
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
void LinkedList<T>::add(int index, T object) {
	// O(n)
	if (_head != NULL) {
		Node<T>* new_node = new Node<T>();
		new_node->data = object;

		if (_head->next != NULL) {
			// There are at least 2 nodes
			Node<T>* previous_node = getNode(index - 1);
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
	if (_head != NULL) {
		Node<T>* temp = _head;
		_head = _head->next;
		T temp_data = temp->data;
		delete temp;
		return temp_data;
	} else {
		// List is empty
		// TODO Throw exception
		return NULL;
	}
}

// Remove last object
template<class T>
T LinkedList<T>::removeLast() {
	// O(n)
	if (_head != NULL) {
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
	} else {
		// List is empty
		// TODO Throw exception
		return 0;
	}
}

// Remove object from index
template<class T>
T LinkedList<T>::remove(int index) {
	// O(n)
	if (_head != NULL) {
		if (index > 0) {
			// There is at least 1 previous node
			Node<T>* previous_node = getNode(index - 1);
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
	} else {
		// No head, throw exception
		// TODO Throw exception
		return NULL;
	}
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
