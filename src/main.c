#include <stdio.h>
#include <string.h>

#include "list_char.h"
#include "list_int.h"
#include "list_string.h"

int main()
{
  
  list_char myCharList = create_list_char(10); 
  list_int myIntList = create_list_int(10);
  list_string myStringList = create_list_string(10);

  char *string = "This is just a basic string";
  list_char_append_many(&myCharList, string, strlen(string)); 
  print_list_char(&myCharList);

  int i;
  for (i = 0; i < 100; i++)
  {
    list_int_append(&myIntList, i);
  }
  print_list_int(&myIntList);

  for (i = 0; i < 3; i++)
  {
    list_string_append(&myStringList, &myCharList);
  }
  print_list_string(&myStringList);

  printf("myCharList contains j? %d\n", list_char_contains(&myCharList, 'j'));
  printf("myCharList contains x? %d\n", list_char_contains(&myCharList, 'x'));
  printf("myIntList contains -1? %d\n", list_int_contains(&myIntList, -1));
  printf("myIntList contains 94? %d\n", list_int_contains(&myIntList, 94));

  printf("myStringList contains string %d\n", list_string_contains(&myStringList, &myCharList));


  free(myIntList.internal_list.arr);
  free(myCharList.internal_list.arr);
  free(myStringList.internal_list.arr);




  return 0; 
}
