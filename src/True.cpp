#include "True.h"


True::True()
{
    //ctor
    //It is something like its component id
    set_logic_type(0);
    set_logic_type_name("Input");
    set_component_id(0);
    set_component_name("True");

    set_exit(1);
}

True::~True()
{
    //dtor
}