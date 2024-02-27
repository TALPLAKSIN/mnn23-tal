#include "node.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
struct node {
    char *name;
    char *data;
    char use;/*Mark with 1 if this node was used and 0 if not */
};

node createNode(char *name,int data) {
    node ptr = calloc(1, sizeof(struct node));
    ptr->name = calloc(30, sizeof(char));
    ptr->data = calloc(50, sizeof(char));
    if(name==NULL || *name=='\0')
        strcpy(ptr->name," ");
    else
        strcpy(ptr->name,name);
    sprintf(ptr->data,"%d",data);
    ptr->use = FALSE;
    return ptr;
}
char getUes(node ptr) {
    return ptr->use;
}
char* getName(node ptr) {
    return ptr->name;
}
char* getData(node ptr) {
    return ptr->data;
}

int checkData(node ptr, int *data) {
    int number;
    int i,j;
    for(i=0;i<strlen(ptr->data);i++){
        number=0;
        j=0;
        while (i+j<strlen(ptr->data)&&ptr->data[i+j]!=',') {
            number = number * 10 + (atoi(&ptr->data[i+j])) ;
            j++;
        }
        if(number==*data)
            return FALSE;
        i+=j;
    }
    return TRUE;
}
void AddToData(node ptr, int* data) {
    char dataNew[50];
    sprintf(dataNew,"%d",*data);
    ptr->data=strcat(ptr->data,",");
    ptr->data=strcat(ptr->data,dataNew);
}
void setUes(node ptr, char use) {
    ptr->use = use;
}

void freeNode(node ptr) {
    free(ptr->name);
    free(ptr->data);
    free(ptr);
}

