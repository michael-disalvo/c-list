#include "list_string.h"




list_string create_list_string(int initialCapacity)
{
  list_string list = 
  {
    create_list(sizeof (list_char *), initialCapacity)
  };
  return list;
}

list_char *list_string_get(list_string *list, int index)
{
  char string[sizeof (list_char *)]; 
  list_get((generic_list *)list, index, string);
  return *(list_char **)string; 
}

int list_string_count(list_string *list)
{
  return list->internal_list.count;
}
void list_string_append(list_string *list, list_char *string)
{
  list_append((generic_list *)list, (char *)&string);
}
void list_string_set(list_string *list, int index, list_char *string)
{
  list_set((generic_list *)list, index, (char *)&string);
}
void list_string_insert(list_string *list, int index, list_char *string)
{
  list_insert((generic_list *)list, index, (char *)&string);
}
list_char *list_string_remove(list_string *list, int index)
{
  list_char *string; 
  list_remove((generic_list *)list, index, (char *)&string);
  return string;
}
list_char *list_string_pop(list_string *list)
{
  return list_string_remove(list, list_string_count(list) - 1);
}
void list_string_clear(list_string *list)
{
  list_clear((generic_list *)list);
}
void print_list_string(list_string *list)
{
  if (list_string_count(list) == 0)
  {
    printf("[]\n");
    return;
  }
  printf("[");
  int i;
  list_char *string = NULL; 
  for (i = 0; i < list_string_count(list) - 1; i++)
  {
    string = list_string_get(list, i);
    if (string != NULL)
      printf("%s", list_char_to_string(string));
    else
      printf("[NULL]");
    printf(", ");
  }
  string = list_string_get(list, i); 
  if (string != NULL)
    printf("%s", list_char_to_string(string));
  else
    printf("[NULL]");
  printf("]\n");
}

/*
int main()
{
  list_string myList = create_list_string(1);
  list_string *list = &myList;

  list_char *str1 = malloc(sizeof (list_char));
  list_char *str2 = malloc(sizeof (list_char));
  *str1 = create_list_char(10);
  *str2 = create_list_char(2);

  list_string_append(list, str1);
  list_string_append(list, str2);

  list_char_append(str1, 'h');
  list_char_append(str1, 'i');
  
  char *s = "there"; 
  int i;
  for (i = 0; i < 5; i++)
  {
    list_char_append(str2, s[i]);
  }
  print_list_string(list);
  list_string_insert(list, 0, str2);
  print_list_string(list);

  list_char* third_string = list_string_remove(list, 2);
  print_list_string(list);
  printf("string remove: %s\n", list_char_to_string(third_string));

  free(str1->internal_list.arr);
  free(str1);
  free(list->internal_list.arr);
  return 0;
}
*/
