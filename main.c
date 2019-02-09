#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(){
  char words[][32] = {"this", "is", "a", "test", "pencil", "ball"};
  size_t arrSize = sizeof(words) / sizeof(words[0]);
  size_t i = 0;

  Trie t = NULL;
  t = TrieMakeEmpty(t);

  for(i = 0; i < arrSize; i++){
    TrieInsert(t, words[i]);
  }

  for(i = 0; i < arrSize; i++){
    fprintf(stdout, "\"%s\" %s\n", words[i], TrieSearch(t, words[i]) ? "found" : "not found");
  }

  // Free trie
  t = TrieFree(t);

  return EXIT_SUCCESS;
}
