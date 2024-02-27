
#ifndef MMN23_2024_LINKED_LIST_H
#define MMN23_2024_LINKED_LIST_H
#include "list.h"
#include "node.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 20
#define SPACE 30

/*A pointer to a  list*/
typedef struct linked_list *list;

/*
 * This function creates a new list node containing a single node with the
 * specified name and data, and returns a pointer to it.
 */

list createList(char *name, int data) ;
/*
 * This function inserts a new list into the beginning of the linked list. If the linked list is not empty,
 * it sets the next pointer of the new list to point to the current head of the
 * linked list and updates the head pointer to point to the new list.
 * If the linked list is empty, it simply sets the head pointer to the new list.
 */
void insert(list *headList, list newList) ;
/*
 *This function searches for a node with a specific name within a linked list of lists.
 * It iterates through each list in the linked list until finding a node with a
 * matching name or reaching the end of the linked list. If a matching node is found,
 * it returns a pointer to that node; otherwise, it returns NULL.
 */
node SearchLink(list headList, char *name) ;
/*
 * This function reads words from a file stream until it encounters a newline character.
 * It then checks if each word exists in a linked list of lists.
 * If a word doesn't exist, it creates a new list node with the word and the current line number.
 * If the word already exists, it adds the current line number to the existing node's data.
 * It also increments the line number counter if it encounters a newline character.
 */
void readWordAndAdd(FILE *fileN, char Line[MAX_LINE_LENGTH], int *numOfLine, list *headList);
/*
 * This function prints the contents of a linked list of lists in ascending order based on
 * the names of the first nodes in each list.
 * It starts by finding the list with the minimum name that has not been used yet.
 * Then, it prints the name and associated data of that list node,
 * marks it as used, and recursively calls itself to print the remaining nodes.
 * The 'flag' parameter controls whether the function continues
 * printing or stops when all nodes have been used.
 */
void printList(list headList,int flag) ;
/*
 * This function frees the memory allocated for all nodes in a linked list of lists,
 * including their associated data, and then frees the memory occupied by each list node itself.
 */
void freelist(list headList);



#endif
