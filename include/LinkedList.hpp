/**
 * @file LinkedList.hpp
 * @author Jake Lane <me@jakelane.me>
 *
 * @section DESCRIPTION
 *
 * Declaration of a Linked list
 * See Wikipedia for more details at https://en.wikipedia.org/wiki/Linked_list
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <class T>
struct Node {
	T data;
	Node<T>* next;
};

template<class T>
class LinkedList {
public:
	// Constructor
	LinkedList();
	// Destructor
	~LinkedList();

	// Get the first object
	T getFirst();
	// Get the last object
	T getLast();
	// Get the nth object
	T get(int index);

	// Set the first object
	void setFirst(T object);
	// Set the last object
	void setLast(T object);
	// Set the nth object
	void set(int index, T object);

	// Push object to the tail
	void push(T object);
	// Add object to the head
	void addFirst(T object);
	// Add object to index
	void add(int index, T object);

	// Pop element from the head
	T pop();
	// Remove last object
	T removeLast();
	// Remove object from index
	T remove(int index);

	// Retrieve the size LinkedList
	int size();

private:
	// Pointer to head node
	Node<T>* _head;
	// Pointer to tail node
	Node<T>* _tail;

	// Get node from index
	Node<T>* getNode(int index);
};

// Template implementation file
#include "../lib/LinkedList.tpp"

#endif // LINKEDLIST_H_
