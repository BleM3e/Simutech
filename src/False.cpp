#include "False.h"


False::False()
{
    //ctor
    //It is something like its component id
    set_logic_type(0);
    set_logic_type_name("Input");
    set_component_id(1);
    set_component_name("False");

    set_exit(0);
}

False::~False()
{
    //dtor
}