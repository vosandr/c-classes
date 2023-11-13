typedef struct mynewclass_events {
    void(*on_event)(t_mynewclass)
} t_mynewclass_events;

typedef struct mynewclass {
    t_mynewclass_events* listener;
} t_mynewclass;