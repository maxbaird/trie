#ifndef __TRIE_H__
#define __TRIE_H__

#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode;
typedef struct TrieNode* Trie;

Trie MakeEmptyTrie(Trie t);
Trie Insert(Trie t, const char *key);
bool Search(Trie t, const char *key);

#endif /* __TRIE_H__ */
