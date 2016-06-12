#ifndef LO21_PROGRAMWIDGET_H
#define LO21_PROGRAMWIDGET_H

#include <gtkmm.h>
#include "../lib/repository/observable.h"
#include "../lib/literal/interface.h"

class ProgramWidget : public RepositoryObserver, public Gtk::TreeView {
protected:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() {
            add(col_id);
            add(col_value);
        }

        Gtk::TreeModelColumn<Glib::ustring> col_id;
        Gtk::TreeModelColumn<Glib::ustring> col_value;
    };

    ModelColumns columns;
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    unsigned int nbAff;
public:
    ProgramWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);

    //repositoryWidget(unsigned int nb) : nbAff(nb){}
    void setNb(unsigned int nbAff) { this->nbAff = nbAff; }

    virtual void update(Repository* repository);
};

#endif //LO21_PROGRAMWIDGET_H
