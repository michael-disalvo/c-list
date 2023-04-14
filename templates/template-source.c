#include "list_/*LIST-NAME*/.h"

/*
 * list-name: the name attacted to list type
 * type-name: the type of the obejct 
 * */


list_/*LIST-NAME*/ create_list_/*LIST-NAME*/(int initialCapacity)
{
  list_/*LIST-NAME*/ list = 
  {
    create_list(sizeof (int), initialCapacity)
  };
  return list; 
}

/*TYPE-NAME*/ list_/*LIST-NAME*/_get(list_/*LIST-NAME*/ *list, int index)
{
  char object[sizeof (/*TYPE-NAME*/)];
  list_get((generic_list *)list, index, object); 
  return *(/*TYPE-NAME*/ *)object; 
}

int list_/*LIST-NAME*/_count(list_/*LIST-NAME*/ *list)
{
  return list->internal_list.count; 
}
void list_/*LIST-NAME*/_append(list_/*LIST-NAME*/ *list, /*TYPE-NAME*/ object)
{
  list_append( (generic_list *)list, (char *)&object);
}
void list_/*LIST-NAME*/_set(list_/*LIST-NAME*/ *list, int index, /*TYPE-NAME*/ object)
{
  list_set( (generic_list *)list, index, (char *)&object);
}
void list_/*LIST-NAME*/_insert(list_/*LIST-NAME*/ *list, int index, /*TYPE-NAME*/ object)
{
  list_insert( (generic_list *)list, index, (char *) &object); 
}
/*TYPE-NAME*/ list_/*LIST-NAME*/_remove(list_/*LIST-NAME*/ *list, int index)
{
  /*TYPE-NAME*/ object; 
  list_remove( (generic_list *)list, index, (char *) &object); 
  return object; 
}
/*TYPE-NAME*/ list_/*LIST-NAME*/_pop(list_/*LIST-NAME*/ *list)
{
  return list_/*LIST-NAME*/_remove(list, list_/*LIST-NAME*/_count(list) - 1); 
}
void list_/*LIST-NAME*/_clear(list_/*LIST-NAME*/ *list)
{
  list_clear((generic_list *)list); 
}

