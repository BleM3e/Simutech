#include "Xor.h"

Xor::Xor()
{
    //ctor
    //It is something like its component id
    set_logic_type(1);
    set_logic_type_name("Gate");
    set_component_id(7);
    set_component_name("Xor");
}

Xor::~Xor()
{
    //dtor
}

int Xor::calculate()
{
    if (sources_t.size() <= 1)
    {
        #if DEBUG
        std::cout << "Error : not enough sources (0 or 1 sources)" << std::endl;
        std::cout << "Hint : add at least two sources" << std::endl;
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

    int _exit = sources_t.at(0)->get_exit();

    for (size_t i = 1; i < sources_t.size(); i++)
    {
        _exit = ((!_exit & sources_t.at(i)->get_exit()) | (_exit & !sources_t.at(i)->get_exit()));
    }

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

