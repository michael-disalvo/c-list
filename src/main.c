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

  int nums[21]; 
  int i;
  for (i = 0; i < 21; i++)
  {
    nums[i] = i;
  }
  list_int_append_many(&myIntList, nums, 21); 
  print_list_int(&myIntList);

  char *string2 = "hello world from main";
  char *string3 = "I went to the zoo today"; 
  list_char *strings[3]; 
  list_char holder = create_list_char(10); 
  list_char holder2 = create_list_char(10); 
  list_char_append_many(&holder, string2, strlen(string2));
  list_char_append_many(&holder2, string3, strlen(string3)); 

  strings[0] = &holder;
  strings[1] = &holder2; 
  strings[2] = &myCharList; 

  list_string_append_many(&myStringList, strings, 3); 

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
