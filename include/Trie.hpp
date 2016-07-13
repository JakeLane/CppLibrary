/**
 * @file Trie.hpp
 * @author Jake Lane <me@jakelane.me>
 *
 * Declaration of a Trie
 * See Wikipedia for more details at https://en.wikipedia.org/wiki/Trie
 */

#ifndef TRIETREE_H_
#define TRIETREE_H_

#include <string>
#include <vector>

class Trie {
public:
	/**
	 * Constructor
	 */
	Trie();
	/**
	 * Destructor
	 */
	~Trie();

	/**
	 * Inserts a string into the Trie
	 * O(n)
	 * @param string String to be added
	 */
	void insert(std::string word);

	/**
	* Searches for a string in the Trie
	* O(n)
	* @param string String to search for
	* @return Returns true if the string is found
	*/
	bool search(std::string word);

	/**
	* Returns if there is any word in the trie that starts with the given prefix.
	* O(n)
	* @param prefix Prefix to search for
	* @return Returns true if the prefix is in the tree
	*/
	bool startsWith(std::string prefix);

private:
	static const std::size_t kAlphabetSize = 26;
	static const char offset = 'a';

	struct Node {
		Node* children[kAlphabetSize] = {nullptr};
		bool isLeaf;

		Node() : isLeaf(false) {}
		Node(bool leaf) : isLeaf(leaf) {}
	};

	// Root node
	Node* root;

	// Cleanup
	void destroy(Node* ptr);
};

#endif // TRIETREE_H_
