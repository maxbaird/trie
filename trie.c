#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"

struct TrieNode{
  struct TrieNode* children[ALPHABET_SIZE];
  bool isEndOfWord;
};

static size_t char_to_index(char c){
  return (size_t)c - (size_t)'a';
}

static bool isEmpty(Trie t){
  return t == NULL;
}

static Trie makeTrie(){
  Trie trie = NULL;

  trie = malloc(sizeof(struct TrieNode));

  if(trie == NULL){
    fprintf(stderr, "Out of memory for trie!\n");
    exit(EXIT_FAILURE);
  }

  trie->isEndOfWord = false;
  memset(trie->children, 0, sizeof(Trie) * ALPHABET_SIZE);

  return trie;
}

Trie MakeEmptyTrie(Trie t){
	if(t != NULL){
		size_t i = 0;
		for(i = 0; i < ALPHABET_SIZE; i++){
			MakeEmptyTrie(t->children[i]);
		}
	}

	free(t);
	return NULL;
}

Trie Insert(Trie t, const char *key){
  size_t level = 0;
  size_t length = 0;
  size_t index = 0;

  if(t == NULL){
    t = makeTrie();
  }

  length = strlen(key);
  Trie trie = t;

  for(level = 0; level < length; level++){
    index = char_to_index(key[level]);

    if(trie->children[index] == NULL){
      trie->children[index] = makeTrie();
    }
    trie = trie->children[index];
  }

  // Mark last node as leaf
  trie->isEndOfWord = true;
  return t;
}

bool Search(Trie t, const char *key){
  if(isEmpty(t)){
    fprintf(stderr, "Trie is empty\n");
    return false;
  }

  size_t level = 0;
  size_t length = 0;
  size_t index = 0;

	length = strlen(key);
  Trie trie = t;

  for(level = 0; level < length; level++){
    index = char_to_index(key[level]);

    if(trie->children[index] == NULL){
      return false;
    }

    trie = trie->children[index];
  }

  return (trie != NULL && trie->isEndOfWord);
}
