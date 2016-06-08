//
// Created by orphee on 04/06/16.
//

#ifndef LO21_MESSAGETREEVIEW_H
#define LO21_MESSAGETREEVIEW_H


#include <gtkmm.h>
#include <iostream>

using namespace std;


class messageTreeView : public Gtk::TreeView {
protected:

    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() { add(col_message); }

        Gtk::TreeModelColumn<Glib::ustring> col_message;
    };

    ModelColumns columns;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    Glib::RefPtr<Gtk::Builder> builder;
    unsigned int nbAff;
public:

    messageTreeView(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);

    void update(string message);

    virtual ~messageTreeView() { }

};


#endif //LO21_MESSAGETREEVIEW_H
