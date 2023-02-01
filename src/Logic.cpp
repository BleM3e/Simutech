#include "Logic.h"

Logic::Logic()
{
    //ctor
    reset_ttl();
}

Logic::~Logic()
{
    //dtor
}

int Logic::get_logic_type()
{
    return logic_type;
}

std::string Logic::get_logic_type_name()
{
    return logic_type_name;
}

int Logic::get_component_id()
{
    return component_id;
}

std::string Logic::get_component_name()
{
    return component_name;
}

void Logic::update_output()
{
    Logic *tmp_src;
    for (size_t i = 0; i < sources_t.size(); i++)
    {
        tmp_src = sources_t.at(i);
        if (tmp_src->output_t.size() == 0)
        {
            tmp_src->output_t.push_back(this);
        }
        else
        {
            for (size_t j = 0; j < tmp_src->output_t.size(); j++)
            {
                if (tmp_src->output_t.at(j) == this) { return; }
            }
            tmp_src->output_t.push_back(this);
        }
    }
}

void Logic::update_exit()
{
    for (size_t i = 0; i < output_t.size(); i++)
    {
        #ifdef DEBUG
        std::cout << "Component " << output_t.at(i)->get_component_name() << " pointer : " << output_t.at(i) << std::endl;
        #endif
        if (output_t.at(i) == this) continue;
        switch (output_t.at(i)->get_logic_type())
        {
        case 1:
            output_t.at(i)->calculate();
            break;
        case 2:
            output_t.at(i)->update_led();
            break;
        default:
            break;
        }
    }
}

void Logic::update_led()
{
}

void Logic::add_sources(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL)
{
    sources_t.push_back(src1);
    if (src2 != NULL) {sources_t.push_back(src2);}
    if (src3 != NULL) {sources_t.push_back(src3);}
    if (src4 != NULL) {sources_t.push_back(src4);}
    update_output();
}

void Logic::set_exit(int _exit)
{
    exit = _exit;
}

int Logic::get_exit()
{
    return exit;
}

void Logic::reset_ttl()
{
    ttl = 0;
}

void Logic::update_ttl()
{
    ttl++;
}

int Logic::get_ttl()
{
    return ttl;
}

int Logic::get_size_src()
{
    return sources_t.size();
}

int Logic::get_size_out()
{
    return output_t.size();
}

void Logic::set_logic_type(int _type)
{
    logic_type = _type;
}

void Logic::set_logic_type_name(std::string _name)
{
    logic_type_name = _name;
}

void Logic::set_component_id(int _component_id)
{
    component_id = _component_id;
}

void Logic::set_component_name(std::string _name)
{
    component_name = _name;
}
