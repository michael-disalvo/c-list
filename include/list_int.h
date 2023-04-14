#include "generic_list.h"


typedef struct list_int 
{
  generic_list internal_list; 
} list_int; 



list_int create_list_int(int initialCapacity); 
int list_int_get(list_int *list, int index); 
int list_int_count(list_int *list); 
void list_int_append(list_int *list, int number); 
void list_int_set(list_int *list, int index, int number); 
void list_int_insert(list_int *list, int index, int number); 
int list_int_remove(list_int *list, int index); 
int list_int_pop(list_int *list); 
void list_int_clear(list_int *list); 
int list_int_contains(list_int *list, int number); 
void print_list_int(list_int *list);
