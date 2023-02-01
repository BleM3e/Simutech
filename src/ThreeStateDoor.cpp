#include "ThreeStateDoor.h"

ThreeStateDoor::ThreeStateDoor()
{
    //ctor
    //It is something like its component id
    set_logic_type(1);
    set_logic_type_name("Gate");
    set_component_id(10);
    set_component_name("ThreeStateDoor");
}

ThreeStateDoor::~ThreeStateDoor()
{
    //dtor
}

int ThreeStateDoor::calculate()
{
    if (sources_t.size() <= 1)
    {
        #if DEBUG
        std::cout << "Error : not enough sources (0 or 1 sources)" << std::endl;
        std::cout << "Hint : add two sources" << std::endl;
        #endif // DEBUG
        return -1;
    }

    if (get_ttl() == 1)
    {
        #if DEBUG
        std::cout << "I got a ttl >= 1" << std::endl;
        #endif
        reset_ttl();
        return -1;
    }

    int _exit;

    if (sources_t.at(1)->get_exit() == 1) _exit = sources_t.at(0)->get_exit();
    else _exit = 2;

    set_exit(_exit);
    if (get_ttl() == 0)
    {
        #if DEBUG
        std::cout << "I got a ttl <= 0" << std::endl;
        #endif
        update_ttl();
        update_exit();
    }
    reset_ttl();
    return _exit;
}

