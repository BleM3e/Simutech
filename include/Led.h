#ifndef LED_H
#define LED_H

#include <Logic.h>
#include <gtkmm/label.h>
#include <gtkmm/grid.h>


class Led : public Logic, public Gtk::Label
{
    public:
        //Led(Gtk::Grid _grid, int _posx, int _posy);
        Led();
        virtual ~Led();
        void add_input(Gtk::Grid *_mainGrid, int _x, int _y);

        void update_led();

    protected:

    private:
        Gtk::Label led;
};

#endif // LED_H
