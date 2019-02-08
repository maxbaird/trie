#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(){
	char keys[][8] = {"the", "a", "there", "answer", "any",
		"by", "bye", "their"};

	size_t i = 0;
	Trie t = NULL;
	t = MakeEmptyTrie(t);

	for(i = 0; i < 8; i++){
		t = Insert(t, keys[i]);
	}

	MakeEmptyTrie(t);
	return EXIT_SUCCESS;
}
