#include <Logic.hpp>

//
/* Primary class of Logic Behaviour */
//

Logic::Logic(std::string _name)
{
    name = _name;
    sourcesNumber = 0;  //Init with 0 sourcesNumber
    exit = 0;           //Init with the false state
}

Logic::~Logic()
{
}

std::string Logic::get_name()
{
    return name;
}

int Logic::get_sourcesNumber()
{
    return sourcesNumber;
}

int Logic::get_exit()
{
    return exit;
}

//
/* Child class for specific Logic Behaviour */
//


//
/* Input class for Logical Input*/
//

Input::Input(std::string _name) : Logic(_name)
{
    // By definition an Input have no sources
    sourcesNumber = 0;
}

Input::~Input()
{
}

//
/* Output class for Logical Output*/
//

Output::Output(std::string _name) : Logic(_name)
{
    // By default an Output have no exit value
    // The -1 value is a special value to non-valuable exit value
    exit = -1;
}

Output::~Output()
{
}

//
/* Gate class for Logical Gate*/
//

Gate::Gate(std::string _name) : Logic(_name)
{
}

Gate::~Gate()
{
}

void Gate::add_source(Logic src)
{
    src_array.push_back(src);
}

int Gate::get_src_exit(int i)
{
    return src_array[i].get_exit();
}

int Gate::get_size_src()
{
    return src_array.size();
}