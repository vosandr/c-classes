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
    
}