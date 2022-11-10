#include <Component.hpp>

//
// Input's child classes
//

/* Logical True */

True::True(std::string _name) : Input(_name)
{
    exit = 1;
}

True::~True()
{
}

/* Logical False */

False::False(std::string _name) : Input(_name)
{
    exit = 0;
}

False::~False()
{
}



//
// Output's child classes
//

/* Logical Led Output */

Led::Led(std::string _name) : Output(_name)
{
    exit = 0;
}

Led::~Led()
{
}


//
// Gate's child classes
//

Not::Not(std::string _name) : Gate(_name)
{
}

Not::~Not()
{
}

int Not::calculate()
{
    int result;

    size_t src_arr_size = get_size_src();

    if (src_arr_size < 1 || src_arr_size > 1)
    {
        std::cout << "Debug : Calculating an Not gate without sources or more than one\n";
        std::cerr << "Warning : Calculating an Not gate without sources or more than one\n";

        // Failure exit value
        return -1;
    }

    result = !result;

    exit = result;

    return result;
}


And::And(std::string _name) : Gate(_name)
{
}

And::~And()
{
}

int And::calculate()
{
    int result;

    size_t src_arr_size = get_size_src();

    if (src_arr_size <= 1)
    {
        std::cout << "Debug : Calculating an And gate without sources or only one\n";
        std::cerr << "Warning : Calculating an And gate without sources or only one\n";

        // Failure exit value
        return -1;
    }

    for (int i = 0; i < src_arr_size - 1; i++)
    {
        result = get_src_exit(i) && get_src_exit(i + 1);
    }
    exit = result;

    return result;
}


Or::Or(std::string _name) : Gate(_name)
{
}

Or::~Or()
{
}

int Or::calculate()
{
    int result;

    size_t src_arr_size = get_size_src();

    if (src_arr_size <= 1)
    {
        std::cout << "Debug : Calculating an Or gate without sources or only one\n";
        std::cerr << "Warning : Calculating an Or gate without sources or only one\n";

        // Failure exit value
        return -1;
    }

    for (int i = 0; i < src_arr_size - 1; i++)
    {
        result = get_src_exit(i) || get_src_exit(i + 1);
    }
    exit = result;

    return result;
}