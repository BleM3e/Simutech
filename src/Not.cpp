#include "Not.h"

Not::Not()
{
    //ctor
    //It is something like its component id
    set_logic_type(1);
    set_logic_type_name("Gate");
    set_component_id(4);
    set_component_name("Not");
}

Not::~Not()
{
    //dtor
}

int Not::calculate()
{

//    std::cout << "I'm in " << this->get_logic_uid() << " a logic type " << this->get_component_name() << std::endl;

    if (sources_t.size() > 1)
    {
        #if DEBUG
        std::cout << "Error : too much sources (only 1 sources)" << std::endl;
        std::cout << "Hint : add only 1 sources" << std::endl;
        #endif // DEBUG
        return -1;
    }

    // Don't modify this part of code
    // It is used to counter the recursive call of the same component
    if (get_ttl() == 1)
    {
        #if DEBUG
        std::cout << "I got a ttl >= 1" << std::endl;
        #endif
        reset_ttl();
        return -1;
    }

    int _exit = !(sources_t.at(0)->get_exit());

    set_exit(_exit);
    // Don't modify this part of code
    // It is used to counter the recursive call of the same component
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

