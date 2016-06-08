//
// Created by orphee on 02/06/16.
//

#ifndef LO21_KEYBOARDWIDGET_H
#define LO21_KEYBOARDWIDGET_H


#include <gtkmm.h>


class keyboardWidget : public Gtk::Box {
public:
    keyboardWidget(BaseObjectType *box, const Glib::RefPtr<Gtk::Builder> &builder);

    Gtk::Grid &getGrid() { return *keyboardGrid; }

    Gtk::Button &getButton(unsigned int nb) { return *button[nb]; }

private:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Grid *keyboardGrid;
    Gtk::Button *button[19];


};

#endif //LO21_KEYBOARDWIDGET_H
