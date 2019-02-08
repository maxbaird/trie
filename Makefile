PROJECT       = trie.out
CC            = gcc
CFLAGS        = -c -g3 -Werror -Wextra

.PHONY : all clean

all : $(PROJECT)

$(PROJECT) : trie.o main.o
	$(CC) $^ -o $@

%.o : %.c %.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *.out $(PROJECT)
