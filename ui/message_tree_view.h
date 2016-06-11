#ifndef LO21_UI_MESSAGES_H
#define LO21_UI_MESSAGES_H


#include <gtkmm.h>
#include <iostream>

using namespace std;

class MessageTreeView: public Gtk::TreeView {
protected:
    class ModelColumns: public Gtk::TreeModel::ColumnRecord {
    public:
        Gtk::TreeModelColumn<Glib::ustring> col_message;

        ModelColumns() {
            add(col_message);
        }
    };

    ModelColumns columns;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    Glib::RefPtr<Gtk::Builder> builder;
    unsigned int nbAff;

public:
    MessageTreeView(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);

    void update(string message);

    virtual ~MessageTreeView() { }
};


#endif // LO21_UI_MESSAGES_H
