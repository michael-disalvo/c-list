#include "list_char.h"


typedef struct list_string
{
    generic_list internal_list;
} list_string;

list_string create_list_string(int initialCapacity);
list_char *list_string_get(list_string *list, int index);
int list_string_count(list_string *list);
void list_string_append(list_string *list, list_char *string);
void list_string_set(list_string *list, int index, list_char *string);
void list_string_insert(list_string *list, int index, list_char *string);
list_char *list_string_remove(list_string *list, int index);
list_char *list_string_pop(list_string *list);
void list_string_clear(list_string *list);
int list_string_contains(list_string *list, list_char *string);
void print_list_string(list_string *list); 
