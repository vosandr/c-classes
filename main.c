#include "mynewclass.h"

t_mynewclass* object;
t_mynewclass_events listener;

void handler_on_event(t_mynewclass* object) {

}

int main(int argc, char** argv) {
    int num_error;

    listener.on_event = handler_on_event;

    object = mynewclass_create)(&num_error);

    mynewclass_set_listener(object, &listener);
    call_function(TYPE_INT, (void*)(&val_1));
    call_function(TYPE_DOUBLE, (void*)(&val_1));
    call_function(TYPE_STR, (void*)(&val_1));
    return 0;
}