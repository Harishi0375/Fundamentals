/*
CH-230-A
a7_p2.c
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct List {
    char info;
    struct List* next1; //forward pointer
    struct List* next2; //backward pointer
};

struct List* createList(int info) 
{
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    newList->info = info;
    newList->next1 = NULL;
    newList
    return newList;
}
