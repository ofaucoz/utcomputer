#ifndef LO21_HISTORYTREEVIEW_H
#define LO21_HISTORYTREEVIEW_H

#include <gtkmm.h>
#include <queue>

using namespace std;


class historyTreeView : public Gtk::TreeView {
protected:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() { add(col_command); }

        Gtk::TreeModelColumn<Glib::ustring> col_command;
    };

    ModelColumns columns;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    Glib::RefPtr<Gtk::Builder> builder;
    unsigned int nbAff;
public:
    historyTreeView(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);

    void update(string command);

    virtual ~historyTreeView() { }
};

#endif //LO21_HISTORYTREEVIEW_H
