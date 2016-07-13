/**
 * Jake Lane <me@jakelane.me>
 *
 * Example use of the Trie class
 */

#include <cstdlib>
#include <iostream>
#include "../include/Trie.hpp"

int main() {
	Trie* trie = new Trie();
	trie->insert("HelloWorld");

	if (trie->search("HelloWorld")) {
		std::cout << "Found \"HelloWorld\" in the Trie" << std::endl;
	}

	if (trie->startsWith("Hello")) {
		std::cout << "Found \"Hello\" as a prefix in the Trie" << std::endl;
	}

	delete trie;
	return EXIT_SUCCESS;
}
