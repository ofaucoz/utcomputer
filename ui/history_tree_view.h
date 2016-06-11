#ifndef LO21_UI_HISTORY_H
#define LO21_UI_HISTORY_H


#include <gtkmm.h>
#include <queue>

using namespace std;

class HistoryTreeView: public Gtk::TreeView {
protected:
    class ModelColumns: public Gtk::TreeModel::ColumnRecord {
    public:
        Gtk::TreeModelColumn<Glib::ustring> col_command;

        ModelColumns() {
            add(col_command);
        }
    };

    ModelColumns columns;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    Glib::RefPtr<Gtk::Builder> builder;
    unsigned int nbAff;

public:
    HistoryTreeView(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);

    void update(string command);

    virtual ~HistoryTreeView() { }
};

#endif // LO21_UI_HISTORY_H
