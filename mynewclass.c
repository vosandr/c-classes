#include "mynewclass.h"

struct mynewclass{
    int value;
}

t_mynewclass mynewclass_create(int exception) {
    t_mynewclass* new_object = malloc( sizeof(t_mynewclass));
    if(new_object==NULL) {
        *exception = errno;
        return NULL;
    }
    new_object->buffer = malloc(bsize*sizeof(t_buffer));
    if(new_object -> buffer == NULL) {
        free(object);
        *exception = errno;
        return NULL;
    }
    return new_object;
}

int mynewclass_destroy(t_mynewclass* object) {
    free(object->buffer);
    free(object);
    object=NULL;
    return 0;
}

void mynewclass_set_listener(t_mynewclass* object, t_mynewclass_events* listener)
{
    object->listener=listener;
}

void mynewclass_set_value(t_mynewclass* mynewclassobject, int value)
{
    mynewclassobject->value=value;
}

int mynewclass_get_value(t_mynewclass* mynewclassobject) {
    return mynewclassobject->value;
}

void call_function(t_mytypes types, void* data) {
    int value1;
    double value2;

    switch(types) {
        case TYPE_INT: {
            value1 = *(int*)data;
            printf("value_1 %d\n", value1);
        } break;
        case TYPE_DOUBLE: {
            value2=*(double*)data;
            printf("value_2 %f\n", value2);
        } break;
        case TYPE_STR: {
            printf("value_str %s\n", (char*) data);
        }
    }
}