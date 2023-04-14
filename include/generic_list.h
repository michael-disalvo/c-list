#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



typedef struct generic_list
{
    void *arr; 
    int count; 
    size_t elementSize; 
    int capacity; 
} generic_list;


generic_list create_list(size_t elementSize, int initialCapacity); 
void list_get(generic_list *list, int index, char *outputObject); 
void list_append(generic_list *list, char *object); 
void list_set(generic_list *list, int index, char *object); 
void list_insert(generic_list *list, int index, char *object); 
void list_remove(generic_list *list, int index, char *object); 
void list_pop(generic_list *list, char *object); 
void list_clear(generic_list *list); 
int list_contains(generic_list *list, char *object); 
void free_list(generic_list *list);

#endif 
