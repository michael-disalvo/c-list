#include "list_int.h"


list_int create_list_int(int initialCapacity)
{
  list_int list = 
  {
    create_list(sizeof (int), initialCapacity)
  };
  return list; 
}

int list_int_get(list_int *list, int index)
{
  char object[sizeof (int)];
  list_get((generic_list *)list, index, object); 
  return *(int *)object; 
}

int list_int_count(list_int *list)
{
  return list->internal_list.count; 
}
void list_int_append(list_int *list, int number)
{
  list_append( (generic_list *)list, (char *)&number);
}
void list_int_set(list_int *list, int index, int number)
{
  list_set( (generic_list *)list, index, (char *)&number);
}
void list_int_insert(list_int *list, int index, int number)
{
  list_insert( (generic_list *)list, index, (char *) &number); 
}
int list_int_remove(list_int *list, int index)
{
  int number; 
  list_remove( (generic_list *)list, index, (char *) &number); 
  return number; 
}
int list_int_pop(list_int *list)
{
  return list_int_remove(list, list_int_count(list) - 1); 
}
void list_int_clear(list_int *list)
{
  list_clear((generic_list *)list); 
}

void print_list_int(list_int *list)
{
  if (list->internal_list.count == 0)
  {
    printf("[]\n"); 
    return; 
  }

  int i;
  printf("[");
  for (i = 0; i < list_int_count(list) - 1; i++)
  {
    printf("%d, ", list_int_get(list, i)); 
  }
  printf("%d]\n", list_int_get(list, i));
}


