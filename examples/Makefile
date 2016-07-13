# COMPILER
CC = g++
VERSION = -std=c++11
CC_OPTIONS = -pedantic -Wall -Wextra

all: Trie

Trie.o: ../include/Trie.hpp ../lib/Trie.cpp
	$(CC) $(VERSION) $(CC_OPTIONS) -c ../lib/Trie.cpp

Trie: Trie.o Trie.cpp
	$(CC) $(VERSION) $(CC_OPTIONS) Trie.o Trie.cpp -o Trie

# Clean
.PHONY: clean
clean:
	rm -f Trie *.o
