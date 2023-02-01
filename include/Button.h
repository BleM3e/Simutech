#ifndef BUTTON_H
#define BUTTON_H

#include <Logic.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/grid.h>


class Button : public Logic, public Gtk::ToggleButton
{
    public:
        //Button(Gtk::Grid _grid, int _posx, int _posy);
        Button();
        virtual ~Button();
//        Gtk::ToggleButton get_btn();
        void add_input(Gtk::Grid *_mainGrid, int _x, int _y);

    protected:
        void on_action();

    private:
        Gtk::ToggleButton btn;
};

#endif // BUTTON_H
