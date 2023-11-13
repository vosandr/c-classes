#include <stdlib.h>
#include <stdio.h>

#include "myclass.h"

//Подключаем при необходимости другие классы
#include "class1.h"
#include "class2.h"

//Определение основной структуры класса с приватными полями
struct myclass {
    t_my_class_events* listener;
    void* parent;

    //Различные переменные, относящиеся к объекту класса
    int value;

    //Дочерние классы (если нужны их свойства)
    t_class1* object1;
    t_class2* object2;

    t_class1_events* listener_1;
    t_class2_events* listener_2;
};

//Обработчики событий объектов дочерних классов
void class1_handler_event(t_class1* class1_object) {
    t_myclass* parent = 
        (t_myclass*) class1_get_parent(class1_object);
}
void class2_handler_event(t_class2* class1_object) {
    t_myclass* parent = 
        (t_myclass*) class2_get_parent(class1_object);
}

//Конструктор
t_myclass* myclass_create(int* exception) {
    int error;

    //Выделение памяти под основную структуру класса
    t_myclass* new_object = malloc(sizeof(t_myclass));
    if(new_object==NULL) {
        *exception = errno;
        return NULL;
    }

    //Инициализация переменных
    //new_object->value= ;
    
    //Инициализация дочерних объектов
    new_object->object1=class1_create(&error);
    if(new_object->object1 == NULL) {
        *exception = error;
        free(new_object);
        return NULL;
    }

    new_object->object2 = class2_create(&error);

    //В конструкторе у потомков прописываем родителя
    class1_set_parent(new_object->object1, (void*)new_object);
    class2_set_parent(new_object->object2, (void*)new_object);

    return new_object;
}

//Деструктор
void myclass_destroy(t_myclass* object) {
    //Все в обратном порядке
    class2_destroy(object->object2);
    class1_destroy(object->object1);

    //free(object->);
    free(object);
    object = NULL;
}

void myclass_set_listener(t_myclass* object, t_my_class_events* listener) 
{
    object->listener=listener;
}

void myclass_set_parent(t_myclass* object, void* parent) 
{
    object->parent=parent;
}

void myclass_get_parent(t_myclass* object) 
{
    return object->parent;
}

void myclass_set_value(t_myclass* object, int value) 
{
    object->value=value;
}

void myclass_get_value(t_myclass* object) 
{
    return object->value;
}