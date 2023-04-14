#include "list_char.h"


void list_char_null_terminate(list_char *list);

list_char create_list_char(int initialCapacity)
{
  list_char list = 
  {
    create_list(sizeof (char), initialCapacity)
  };
  return list; 
}

char list_char_get(list_char *list, int index)
{
  char character[sizeof (char)];
  list_get((generic_list *)list, index, character);
  return *(char *)character;
}
int list_char_count(list_char *list)
{
  return list->internal_list.count;
}
void list_char_append(list_char *list, char character)
{
 list_append((generic_list *)list, (char *)&character);  
 list_char_null_terminate(list);
}
void list_char_set(list_char *list, int index, char character)
{
  list_set((generic_list *)list, index, (char *)(&character));
}
void list_char_insert(list_char *list, int index, char character)
{
  list_insert((generic_list *)list, index, (char *)(&character)); 
  list_char_null_terminate(list);
}
char list_char_remove(list_char *list, int index)
{
  char character; 
  list_remove((generic_list *)list, index, (char *)&character); 
  list_char_null_terminate(list);
  return character;
}
char list_char_pop(list_char *list)
{
  return list_char_remove(list, list_char_count(list) - 1); 
  list_char_null_terminate(list);
}
void list_char_clear(list_char *list)
{
  list_clear((generic_list *)list);
}
void print_list_char(list_char *list)
{
  if (list_char_count(list) == 0)
  {
    printf("[]\n"); 
    return;
  }
  printf("["); 
  int i; 
  for (i = 0; i < list_char_count(list) - 1; i++)
  {
    printf("%c, ", list_char_get(list, i)); 
  }
  printf("%c]\n", list_char_get(list, i)); 
}
char *list_char_to_string(list_char *list)
{
  return *(char **)list; 
}


void list_char_null_terminate(list_char *list)
{
  char character = '\0';
  list_append((generic_list *)list, (char *)&character);
  list->internal_list.count--; 
}

