#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(){
  char words[][8] = {"this", "is", "a", "test"};
  size_t i = 0;
  Trie t = NULL;
  t = MakeEmptyTrie(t);

  for(i = 0; i < 8; i++){
    t = Insert(t, words[i]);
  }

  for(i = 0; i < sizeof(words) / sizeof(words[0]); i++){
    fprintf(stdout, "\"%s\" %s\n", words[i], Search(t, words[i]) ? "found" : "not found");
  }

  // Free trie
  t = MakeEmptyTrie(t);

  return EXIT_SUCCESS;
}
