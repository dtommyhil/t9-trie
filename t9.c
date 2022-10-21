// Author: Arif Chu, Marco Mak, Tommyhil Doan
// UWNetID: achu123 marcomak
// HW5
// Copyright [2021] <Arif Chu, Marco Mak, Tommyhil Doan>

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "trie.h"

void interactive()  {

  char input[10];

  printf("Enter \"exit\" to quit.\n");
  printf("Enter Key Sequence \"(\"or \"#\" for next word\")\":\n");

  while(fgets(input, 10, stdin)) {
    if (strcmp(input, "exit") == 0) {
      break;
    }
    printf("%p", search_word(input));
    printf("Enter Key Sequence \"(\"or \"#\" for next word\")\":\n");
  }
}

int main(int argc, char * argv[]) {
  // still need to check for arguments
  if (argc < 2) {
    printf("Need file argument\n");
    return 1;
  }
    
  FILE * file = fopen(argv[1], "r");
   
  if (!file) {
    printf("File not found.");
    return 1;
  }
  
  TpopulateTrie(file);
  fclose(file);
  
  Trie* trie = (Trie*)malloc(sizeof(Trie));
  
  // add method to populate the trie once completed
  interactive();
  free_node(trie->root);
  free(trie);
  return 0;
}
