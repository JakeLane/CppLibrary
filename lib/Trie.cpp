/**
 * Jake Lane <me@jakelane.me>
 *
 * Implementation of a Trie
 * See Wikipedia for more details at https://en.wikipedia.org/wiki/Trie
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "../include/Trie.hpp"

// Constructor
Trie::Trie() {
	root = new Node();
}

// Destructor
Trie::~Trie() {
	destroy(root);
}

// Recursively free the memory
void Trie::destroy(Node* ptr) {
	if (ptr->isLeaf) {
		return;
	}
	for (std::size_t i = 0; i < kAlphabetSize; ++i) {
		if (ptr->children[i]) {
			destroy(ptr->children[i]);
			delete ptr->children[i];
		}
	}
}

// Insert a word into Trie
void Trie::insert(std::string word) {
	Node* ptr = root;
	for (auto it = word.begin(); it != word.end(); ++it) {
		// Last char in word is a leaf
		bool leaf = std::next(it) == word.end();
		if (ptr->children[*it - offset] == nullptr) {
			// Node for char doesn't exist, make it
			ptr->children[*it - offset] = new Node(leaf);
		} else if (leaf) {
			// Last char in word is a leaf
			ptr->children[*it - offset]->isLeaf = true;
		}
		// Move the pointer to the next char
		ptr = ptr->children[*it - offset];
	}
}

// Search the Trie for the word
bool Trie::search(std::string word) {
	Node* ptr = root;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (ptr->children[*it - offset] == nullptr) {
			// Character was not found, hence prefix is not in Trie
			return false;
		}
		// Move the pointer to the next char
		ptr = ptr->children[*it - offset];
	}

	// The word is found if the final node is a leaf
	return ptr->isLeaf;
}

// Search the Trie for the prefix
bool Trie::startsWith(std::string prefix) {
	Node* ptr = root;
	for (auto it = prefix.begin(); it != prefix.end(); ++it) {
		if (ptr->children[*it - offset] == nullptr) {
			// Character was not found, hence prefix is not in Trie
			return false;
		}
		// Move the pointer to the next char
		ptr = ptr->children[*it - offset];
	}
	return true;
}
