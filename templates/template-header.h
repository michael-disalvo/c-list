#include "generic_list.h"


/* 
 * type-name: the actual type (like 'int' or 'char')
 * list-name: the name attached to list (list 'list_int')
 * */

typedef struct list_/*LIST-NAME*/
{
    generic_list internal_list;
} list_/*LIST-NAME*/;

list_/*LIST-NAME*/ create_list_(int initialCapacity);
/*TYPE-NAME*/ list_/*LIST-NAME*/_get(list_/*LIST-NAME*/ *list, int index);
int list_/*LIST-NAME*/_count(list_/*LIST-NAME*/ *list);
void list_/*LIST-NAME*/_append(list_/*LIST-NAME*/ *list, /*TYPE-NAME*/ object);
void list_/*LIST-NAME*/_set(list_/*LIST-NAME*/ *list, int index, /*TYPE-NAME*/ object);
void list_/*LIST-NAME*/_insert(list_/*LIST-NAME*/ *list, int index, /*TYPE-NAME*/ object);
/*TYPE-NAME*/ list_/*LIST-NAME*/_remove(list_/*LIST-NAME*/ *list, int index);
/*TYPE-NAME*/ list_/*LIST-NAME*/_pop(list_/*LIST-NAME*/ *list);
void list_/*LIST-NAME*/_clear(list_/*LIST-NAME*/ *list);



