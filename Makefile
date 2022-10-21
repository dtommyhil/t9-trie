CC = gcc 
CFLAGS = -Wall -g -std=c11
t9: t9.o trie.o
	$(CC) $(CFLAGS) -o t9 t9.o trie.o
	
t9.o: t9.c trie.h 
	$(CC) $(CFLAGS) -c t9.c

trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c
