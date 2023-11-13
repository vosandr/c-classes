struct mynewclass;
typedef struct mystruct t_mynewclass;

typedef struct mynewclass_events {
    void(*on_event)(t_mynewclass)
} t_mynewclass_events;

typedef struct mynewclass {
    t_mynewclass_events* listener;
} t_mynewclass;

void mynewclass_set_value(t_mynewclass* myclassObject, int value);
int mynewclass_get_value(t_mynewclass* myclassObject);
typedef enum mytypes {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_STR
} t_mytypes;