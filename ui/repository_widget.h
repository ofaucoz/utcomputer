#ifndef LO21_REPOSITORY_H
#define LO21_REPOSITORY_H


#include <gtkmm.h>
#include "../lib/repository/observable.h"
#include "../lib/literal/interface.h"

class RepositoryWidget: public RepositoryObserver, public Gtk::TreeView {
protected:
    class ModelColumns: public Gtk::TreeModel::ColumnRecord {
    public:
        Gtk::TreeModelColumn<int> col_id;
        Gtk::TreeModelColumn<Glib::ustring> col_value;

        ModelColumns() {
            add(col_id);
            add(col_value);
        }
    };

    ModelColumns columns;
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    unsigned int nbAff;

public:
    RepositoryWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);

    void setNb(unsigned int nbAff) {
        this->nbAff = nbAff;
    }

    virtual void update(Repository *repository);

    virtual ~RepositoryWidget() { }
};


#endif //LO21_REPOSITORY_H
