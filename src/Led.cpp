#include "Led.h"

//Led::Led(Gtk::Grid _grid, int _posx, int _posy)
Led::Led()
{
    //ctor
    //It is something like its component id
    set_logic_type(2);
    set_logic_type_name("Output");
    set_component_id(3);
    set_component_name("Led");

    led.set_text("N/A");
    //_grid.attach(led, _posx, _posy);
}

Led::~Led()
{
    //dtor
}

void Led::add_input(Gtk::Grid *_mainGrid, int _x, int _y)
{
    _mainGrid->attach(led, _x, _y);
}

void Led::update_led()
{
    switch (sources_t.at(0)->get_exit())
    {
    case 0:
        led.set_text("Led : 0");
//        led.set_label("Led : 0");
        break;
    case 1:
        led.set_text("Led : 1");
//        led.set_label("Led : 1");
        break;
    case 2:
        led.set_text("Led : Z");
//        led.set_label("Led : Z");
        break;
    default:
        led.set_text("Led : not defined");
//        led.set_label("Led : not defined");
        break;
    }
}
