
#include "list.h"

int main(int argc, char *argv[]) {
    FILE *fptr=NULL;
    list headList=NULL;
    char Line[MAX_LINE_LENGTH] = {0};
    int numOfLine = 1;
    if (argc != 2) {
        fprintf(stderr, "Must be 2 operators \n");
        exit(0);
    }
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        fprintf(stderr, "Cannot open file \n");
        exit(0);
    }
    if (feof(fptr)) {
        fprintf(stderr, "The file is empty\n");
        fclose(fptr);
        exit(0);
    }
    while (!feof(fptr))
        readWordAndAdd(fptr, Line, &numOfLine, &headList);
    printList(headList,1);
    freelist(headList);
    fclose(fptr);
    return 0;
}

