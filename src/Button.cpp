#include "Button.h"

Button::Button()
{
    //ctor
    //It is something like its component id
    set_logic_type(0);
    set_logic_type_name("Input");
    set_component_id(2);
    set_component_name("Button");

    btn.signal_clicked().connect(sigc::mem_fun(*this, &on_action));

    set_exit(btn.get_active());
}

Button::~Button()
{
    //dtor
}

void Button::add_input(Gtk::Grid *_mainGrid, int _x, int _y)
{
    _mainGrid->attach(btn, _x, _y);
}

void Button::on_action()
{
    set_exit(btn.get_active());

    std::cout << "Button : " << this->get_logic_uid() << " with exit : " << this->get_exit() << std::endl;
    update_exit();
}
