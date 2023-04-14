#include "generic_list.h"


typedef struct list_char 
{
    generic_list internal_list; 
} list_char; 

list_char create_list_char(int initialCapacity); 
char list_char_get(list_char *list, int index); 
int list_char_count(list_char *list); 
void list_char_append(list_char *list, char character); 
void list_char_set(list_char *list, int index, char character); 
void list_char_insert(list_char *list, int index, char character); 
char list_char_remove(list_char *list, int index); 
char list_char_pop(list_char *list); 
void list_char_clear(list_char *list); 
int list_char_contains(list_char *list, char character); 
void print_list_char(list_char *list); 
char *list_char_to_string(list_char *list);
