//
// Created by orphee on 04/06/16.
//

#include "messageTreeView.h"

messageTreeView::messageTreeView(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder) : Gtk::TreeView(treeview), builder(builder) {
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    this->append_column( "message", columns.col_message);
    nbAff=0;

}

void messageTreeView::update(string message)
{
    if(nbAff==8) {
        refTreeModel->clear();
        nbAff=0;
    }
    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[columns.col_message] = message;
    nbAff++;
}
