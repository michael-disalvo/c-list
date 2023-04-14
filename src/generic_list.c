#include "generic_list.h"

void *resize_array(void *array, int *capacity, size_t elementSize);
void check_index(generic_list list, int index);
void print_list(generic_list list); 
int byte_array_equal(char *arr1, char *arr2, int numberOfBytes);

generic_list create_list(size_t elementSize, int initialCapacity)
{
    generic_list list = 
    {
       malloc(elementSize * initialCapacity),
       0,
       elementSize,
       initialCapacity
    };

    return list; 
}

void list_get(generic_list *list, int index, char *outputObject)
{
  check_index(*list, index);  
  int startByte = index * list->elementSize; 
  memcpy(outputObject, (char *)(list->arr + startByte), list->elementSize); 
  return; 
}

void list_append(generic_list *list, char *object)
{
   if (list->count == list->capacity)
      list->arr = resize_array(list->arr, &list->capacity, list->elementSize); 

   memcpy((char *)(list->arr + (list->count * list->elementSize)), object, list->elementSize); 
   list->count++; 
}

void list_insert(generic_list *list, int index, char *object)
{
   if (index == list->count)
   {
      list_append(list, object); 
      return; 
   }
   check_index(*list, index);

   char *curr = list->arr + (index * list->elementSize), tmp[list->elementSize], prev[list->elementSize]; 
   memcpy(prev, object, list->elementSize); 
   int i; 
   for (i = index; i < list->count; i++)
   {
      memcpy(tmp, curr, list->elementSize); 
      memcpy(curr, prev, list->elementSize); 
      memcpy(prev, tmp, list->elementSize); 
      curr += list->elementSize;
   }
   list_append(list, prev); 
}

void list_set(generic_list *list, int index, char *object)
{
   check_index(*list, index); 
   int startByte = index * list->elementSize; 
   memcpy((char *)(list->arr + startByte), object, list->elementSize); 
   return; 
}

void list_remove(generic_list *list, int index, char *object)
{
   check_index(*list, index); 
   char *curr = (list->arr + (list->elementSize*(list->count - 1))), prev[list->elementSize], tmp[list->elementSize]; 
   int counter;
   /* curr -> tmp, prev -> curr, tmp -> prev, move curr */
   for (counter = list->count - 1; counter >= index; counter--)
   {
      memcpy(tmp, curr, list->elementSize); 
      memcpy(curr, prev, list->elementSize); 
      memcpy(prev, tmp, list->elementSize); 
      curr -= (list->elementSize); 
   }
   memcpy(object, prev, list->elementSize); 
   list->count--; 
}

void list_pop(generic_list *list, char *object)
{
   list_remove(list, list->count - 1, object); 
}

void list_clear(generic_list *list)
{
   memset(list->arr, 0, list->count * list->elementSize); 
   list->count = 0; 
}

int list_contains(generic_list *list, char *object)
{
   int index = 0; 
   char *curr = list->arr + (index*list->elementSize);
   for (index = 0; index < list->count; index++)
   {
      if (byte_array_equal(curr, object, list->elementSize))
         return 1; 
      curr += (list->elementSize); 
   }
   return 0; 
}

void free_list(generic_list *list)
{
   free(list->arr); 
}

void *resize_array(void *array, int *capacity, size_t elementSize)
{
   size_t newLength = (*capacity) * elementSize * 2; 
   void *newArray = malloc(newLength);
   if (newArray == NULL || array == NULL)
   {
       perror("[ERR] error allocating memory"); 
       exit(1);
   }
   memcpy(newArray, array, (*capacity) * elementSize); 
   free(array); 
   (*capacity) += (*capacity); 

   return newArray;
}

void check_index(generic_list list, int index)
{

   if (index < 0)
   {
      printf("[ERR] List index cannot be less than 0\n");
      exit(1);
   }
   
   if (index >= list.count)
   {
      printf("[ERR] List index %d is out of range 0 to %d\n", index, list.count - 1);
      exit(1);
   }
}

void print_list(generic_list list)
{
   if (list.count == 0)
   {
      printf("[]\n");
      return; 
   }
   int i; 
   int element[1]; 
   printf("[");
   for (i = 0; i < list.count - 1; i++)
   {
      list_get(&list, i,(char *) element); 
      printf("%d, ", *element);
   }
   list_get(&list, i,(char *) element); 
   printf("%d]\n", *element);
}


int byte_array_equal(char *arr1, char *arr2, int numberOfBytes)
{
   int i; 
   for (i = 0; i < numberOfBytes; i++)
   {
      if (arr1[i] != arr2[i])
         return 0; 
   }
   return 1;
}
