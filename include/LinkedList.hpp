/**
 * @file LinkedList.hpp
 * @author Jake Lane <me@jakelane.me>
 *
 * Declaration of a Single-Linked list
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
	/**
	 * Constructor that initialises to NULL
	 */
	LinkedList();
	/**
	 * Destructor that frees up allocated space
	 */
	~LinkedList();

	/**
	 * Get the first object in the List
	 * O(1)
	 * @return The first object in the LinkedList
	 */
	T getFirst();
	/**
	 * Get the last object in the List
	 * O(1)
	 * @return The last object in the LinkedList
	 */
	T getLast();
	/**
	 * Get the object in the List at the chosen index
	 * O(n)
	 * @return The i th object in the LinkedList
	 */
	T get(int i);

	/**
	 * Set the first object in the List
	 * O(1)
	 * @param object Object to replace the start of the LinkedList
	 */
	void setFirst(T object);
	/**
	 * Set the last object in the List
	 * O(1)
	 * @param object Object to replace the end of the LinkedList
	 */
	void setLast(T object);
	/**
	 * Set the object at the index in the List
	 * O(n)
	 * @param i Index that the object will replace
	 * @param Object to be set in LinkedList
	 */
	void set(int i, T object);

	/**
	 * Push to the back of the list
	 * O(1)
	 * @param object Object to add to the end of the LinkedList
	 */
	void push(T object);
	/**
	 * Add to the start of the list
	 * O(1)
	 * @param object Object to add to the start of the LinkedList
	 */
	void addFirst(T object);
	/**
	 * Add the object at the index in the List
	 * O(n)
	 * @param i Index that the object will sit
	 * @param object Object to be added in LinkedList
	 */
	void add(int i, T object);

	/**
	 * Pop the object from start of the list
	 * O(1)
	 * @return The (previously) first object in the LinkedList
	 */
	T pop();
	/**
	 * Remove the object from end of the list
	 * O(n)
	 * @return The (previously) last object in the LinkedList
	 */
	T removeLast();
	/**
	 * Remove the object from the chosen index
	 * O(n)
	 * @return The (previously) i th object in the LinkedList
	 */
	T remove(int i);

	/**
	 * Test whether the list is empty
	 * O(1)
	 * @return True if there is no objects in the LinkedList
	 */
	bool empty();
	/**
	 * The length of the list
	 * O(n)
	 * @return The number of objects in the LinkedList
	 */
	int size();

private:
	// Pointer to head node
	Node<T>* _head;
	// Pointer to tail node
	Node<T>* _tail;

	// Get node from i
	Node<T>* getNode(int i);
};

// Template implementation file
#include "../lib/LinkedList.tpp"

#endif // LINKEDLIST_H_
