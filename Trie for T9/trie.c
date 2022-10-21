// Author: Arif Chu, Marco Mak, Tommyhil Doan
// UWNetID: achu123 marcomak
// HW5
// Copyright [2021] <Arif Chu, Marco Mak, Tommyhil Doan>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

Trie* trie;
TrieNode* curr;

TrieNode* makeNode() {
  TrieNode* t = (TrieNode*) malloc(sizeof(TrieNode));
  if (t == NULL) {
    return NULL;
  }
  for (int i = 0; i < 10; i++) {
    t->children[i] = NULL;
  }
  t->word = NULL;
  return t;
}

TrieNode* makeNode11() {
  TrieNode* t = (TrieNode*) malloc(sizeof(TrieNode));
  if (t == NULL) {
    return NULL;
  }
  for (int i = 0; i < 11; i++) {
    t->children[i] = NULL;
  }
  t->word = NULL;
  return t;
}

//fill in Trie with file values
Trie* populateTrie(FILE * file) {
  char line[MAX_LINE_LENGTH+2];
  Trie* node = makeNode();
  while (fgets(line, MAX_LINE_LENGTH+2, file)) {
    node_insert(node, line, 0);
  }
  return node; 
}

/*
Recursively follows or inserts nodes starting from previous_node until the location for word is found, at which point it is inserted. Current_letter is the index of word where the recursive algorithm is currently at.
*/

int node_insert(TrieNode *previous_node, char word[], int current_letter) {
   if (word[current_letter] == '\0') { // word is empty
       // word is empty
       return 0;
   }
   int digit = letter_to_digit(word[current_letter]);

   if (previous_node->children[digit] == NULL) { 
       previous_node = makeNode(); // node doesn't exist, create it
   } else { // node already exists
       current_node = children[digit];//next unexamined child of previous node
   }
   if (word[current_letter + 1] == '\0') { // at the end of the word     
       if (curr->word == NULL) { // current node doesn’t have a word yet
       // save word here
          // allocate memory for the string
          // strcpy the string we malloc'ed
          curr->word = (char *) malloc(strlen(word)*sizeof(char *));
          strcpy(curr->word, previous_node->word);
       } else {  
           // current node already has a word, add it as an additional completion
            // making node for # (same word sequence)
            TrieNode* extraNode = makeNode11();
            // pointing the node to the # node
            current_node->children[digit] = extraNode[11];
            return 0;
       }
   } else { // not at the end of the string, so continue to the next letter
       return node_insert(current_node, word, current_letter + 1);
   }
}

char* search_word(char* sequence) {
    if (number[0] == '#') {
        if (curr->next[10] == NULL) {
            return "There are no more T9nonyms\n";
        }
        curr = curr->next[10];
        return curr->word;
    } else {
        curr = trie->root;
        int len = strlen(sequence);
        for (int i = 0; i < len; i++) {
            if (sequence[i] == '#') {
               curr = curr->next[10] 
            } else {
                int index = sequence[i] - '0';
                if (curr->next[index] == NULL) {
                    return "Not found in the current dictionary.\n";
                } else {
                    curr = curr->next[index];
                }
            }
        }
        if (curr == NULL) {
            return "There are no more T9nonyms.\n";
        } else if (curr->word == NULL) {
            return "Not found in the current dictionary.\n";
        } else {
            return curr->word;
        }
    }
}

// searches and returns a word from trie given an input sequence of numbers
//free memory from node
void free_node(Node* node) {
    for (int i = 0; i < 11; i++) {
    if (node->next[i] != NULL) {
      free_node(node->next[i]);
    }
  }
  free(node->word);
  free(node);
}

//letter_to_digit (Undebug)
int letter_to_digit(char letter) {
    char s = letter;
    int r;
    
    if ((s == 'a') || (s == 'b') || (s == 'c')) {
        r = 2;
    } else if ((s == 'd') || (s == 'e') || (s == 'f')) {
        r = 3; 
    } else if ((s == 'g') || (s == 'h') || (s == 'i')) {
        r = 4; 
    } else if ((s == 'j') || (s == 'k') || (s == 'l')) {
        r = 5; 
    } else if ((s == 'm') || (s == 'n') || (s == 'o')) {
        r = 6; 
    } else if ((s == 'p') || (s == 'q') || (s == 'r') || (s == 's')) {
        r = 7; 
    } else if ((s == 't') || (s == 'u') || (s == 'v')) {
        r = 8; 
    } else if ((s == 'w') || (s == 'x') || (s == 'y') || (s == 'z')) {
        r = 9; 
    }
    
    return r;
}

//possibly if else if statements, if not hexcode char
