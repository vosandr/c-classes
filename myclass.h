#ifndef _MYCLASS_H_
#define _MYCLASS_H_

#include <stdlib.h>
#include "sfuns.h"

//Объявление класса
struct myclass;
typedef struct myclass t_myclass;

//События класса
typedef struct myclass_events {
    void (*on_event_1)(t_myclass* object);
    void (*on_event_2)(t_myclass* object);
    void (*on_event_n)(t_myclass* object);
} t_myclass_events;

//Конструктор и дескриптор
t_myclass* myclass_create(int* exception);
void myclass_destroy(t_myclass* object);

//Назначение слушателя событий
void myclass_set_listener(t_myclass* object, t_myclass_events* listener);

//Память о предках
void myclass_set_parent(t_myclass* object, void* parent);
void* myclass_get_parent(t_myclass* object);

//Различные методы класса, определяющие свойства
void myclass_set_value(t_myclass* object, int value);
int myclass_get_value(t_myclass* object);

#endif