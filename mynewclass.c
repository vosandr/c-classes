#include "mynewclass.h"

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