
#include "list.h"
#include "node.h"
#include <stdlib.h>
#include <string.h>


struct linked_list {
    node head;
    list next;
};

list createList(char *name, int data) {
    list ls = calloc(1, sizeof(struct linked_list));
    ls->head = createNode(name, data);
    ls->next = NULL;
    return ls;
}

void insert(list *headList, list newList) {
    if ((*headList) != NULL) {
        newList->next = *headList;
        *headList = newList;
    } else
        (*headList) = newList;
}

node SearchLink(list headList, char *name) {
    int i=0;
    list temp = headList;
    node check = NULL;
    while (temp != NULL && temp->head != NULL && getName(temp->head) != NULL && name != NULL) {
        i++;
        check = temp->head;
        if (strcmp(getName(check), name) == 0)
            return check;
        temp = temp->next;
    }
    return NULL;
}

void readWordAndAdd(FILE *fileN, char Line[MAX_LINE_LENGTH], int *numOfLine, list* headList) {
    int i = 0;
    int temp;
    list tempList = NULL;
    node tempNode = NULL;
    char *tempWord = NULL;
    int flag = 1;
    while ((temp = fgetc(fileN)) != EOF && (char) temp != '\n') {
        if ((isalpha((char)temp)==0) && flag)
            continue;
        else if((isalpha((char)temp)==0) && !flag)
            break;
        Line[i] = (char) temp;
        i++;
        flag = 0;
    }
    Line[i] = '\0';
    if(i!=0) {
        tempWord = strtok(Line, " \t\n\v\f\r,.");
        if (tempWord != NULL) {
            tempNode = SearchLink(*headList, tempWord);
            if (tempNode == NULL) {
                tempList = createList(tempWord, *numOfLine);
                insert(headList, tempList);
            } else {
                if (checkData(tempNode, numOfLine))
                    AddToData(tempNode, numOfLine);
            }
        }
        if ((char)temp == '\n')
            (*numOfLine)++;
    }
}

void printList(list headList,int flag) {
    unsigned long i;
    list tempList = headList;
    list minList = NULL;
    if (tempList != NULL&&flag) {
        while (tempList != NULL) {
            if ((minList == NULL && !getUes(tempList->head)) || ((minList != NULL&&!getUes(tempList->head) &&(strcmp(getName(minList->head),getName(tempList->head))>0)) ))
                minList = tempList;
            tempList = tempList->next;
        }
        if (minList != NULL) {
            printf("%s", getName(minList->head));
            for (i = strlen(getName(minList->head)); i < SPACE; i++)
                printf(" ");
            printf("appears in lines %s\n", getData(minList->head));
            setUes(minList->head, 1);
        }
        else
            flag=0;
        printList(headList,flag);
    }
}

void freelist(list headList) {
    list tempList;
    while (headList != NULL) {
        tempList = headList;
        headList = headList->next;
        freeNode(tempList->head);
        free(tempList);
    }
}


