#include "message_tree_view.h"

MessageTreeView::MessageTreeView(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder) :
    Gtk::TreeView(treeview), builder(builder) {
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    this->append_column("message", columns.col_message);
    nbAff = 0;

}

void MessageTreeView::update(string message) {
    if (nbAff == 8) {
        refTreeModel->clear();
        nbAff = 0;
    }
    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[columns.col_message] = message;
    nbAff++;
}
