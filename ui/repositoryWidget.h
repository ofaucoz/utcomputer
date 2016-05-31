//
// Created by orphee on 02/06/16.
//

#ifndef LO21_REPOSITORYWIDGET_H
#define LO21_REPOSITORYWIDGET_H


#include <gtkmm.h>
#include "../lib/repository/observable.h"
#include "../lib/literal/interface.h"

class repositoryWidget : public RepositoryObserver,public Gtk::TreeView{
protected:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:

        ModelColumns()
        { add(col_id); add(col_value); }

        Gtk::TreeModelColumn<int> col_id;
        Gtk::TreeModelColumn<Glib::ustring> col_value;
    };
    ModelColumns columns;
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    unsigned int nbAff;
public:
    repositoryWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);
    //repositoryWidget(unsigned int nb) : nbAff(nb){}
    void setNb(unsigned int nbAff){this->nbAff=nbAff;}
    virtual void update(Repository* repository);
    virtual ~repositoryWidget(){}

};


#endif //LO21_REPOSITORYWIDGET_H
