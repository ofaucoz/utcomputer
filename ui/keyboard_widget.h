#ifndef LO21_UI_KEYBOARD_H
#define LO21_UI_KEYBOARD_H


#include <gtkmm.h>


class KeyboardWidget: public Gtk::Box {
private:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Grid *keyboardGrid;
    Gtk::Button *button[19];

public:
    KeyboardWidget(BaseObjectType *box, const Glib::RefPtr<Gtk::Builder> &builder);

    Gtk::Grid &getGrid() {
        return *keyboardGrid;
    }

    Gtk::Button &getButton(unsigned int nb) {
        return *button[nb];
    }
};

#endif // LO21_UI_KEYBOARD_H
