// Author: Arif Chu, Marco Mak, Tommyhil Doan
// UWNetID: achu123 marcomak
// HW5
// Copyright [2021] <Arif Chu, Marco Mak, Tommyhil Doan>

#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 100

typedef struct TrieNode {
  char* word;
  struct TrieNode* children[10];
} TrieNode;

typedef struct TrieNode11 {
  char* word;
  struct TrieNode* children[11];
} TrieNode11;

typedef struct Trie {
  TrieNode* root;
} Trie;

TrieNode* makeNode();

TrieNode* makeNode11();

TrieNode * populateTrie (FILE * file);

int node_insert(TrieNode *previous_node, char word[], int current_letter);

char* search_word(char* sequence);

void free_node(TrieNode* node);

int letter_to_digit(char letter);

#endif
