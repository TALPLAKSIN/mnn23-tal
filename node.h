
#ifndef MMN23_2024_INDEX_H
#define MMN23_2024_INDEX_H



#define FALSE 0
#define TRUE 1

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_DATA_LENGTH 100

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node *node;
/*
 * This function creates a new node with the given name and data,
 * initializes its 'use' flag to false,
 * and returns a pointer to the newly created node.
 */
node createNode(char *name,int data) ;
/*
 * This function retrieves the 'use' flag value
 * from the given node and returns it.
 */
char getUes(node ptr) ;
/*
 * This function returns the name stored in the given node.
 */
char* getName(node ptr) ;
/*
 * This function returns the data stored in the given node.
 */
char* getData(node ptr) ;
/*
 * This function appends a new data value to the existing
 *  data string stored in the given node.
 */
void AddToData(node ptr, int *data);
/*
 * This function sets the 'use' flag of the given node to the specified value.
 */
void setUes(node ptr, char use) ;
/*
 * This function deallocates the memory occupied by the given node,
 * including its name and data fields,
 * and then frees the node itself.
 */
void freeNode(node ptr) ;
void AddToData(node ptr, int* data);
int checkData(node ptr, int *data);

#endif

