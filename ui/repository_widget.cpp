#include "repository_widget.h"
#include "../lib/literal/stack.h"

RepositoryWidget::RepositoryWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder) :
    Gtk::TreeView(treeview), builder(builder) {
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    nbAff = 5;
    this->append_column("ID", columns.col_id);
    this->append_column("value", columns.col_value);

    for (unsigned int i = 0; i < nbAff; i++) {
        Gtk::TreeModel::Row row = *(refTreeModel->append());
        row[columns.col_id] = i;
        row[columns.col_value] = "";
    }
}

void RepositoryWidget::update(Repository *repository) {
    Glib::RefPtr<Gtk::ListStore> refTreeModel2 = Gtk::ListStore::create(columns);
    set_model(refTreeModel2);

    if (LiteralsStack *stack = static_cast<LiteralsStack *>(repository)) {
        vector<LiteralPointer>::const_iterator it = stack->begin();

        for (unsigned int i = 0; it != stack->end() && i < nbAff; i++, ++it) {
            Gtk::TreeModel::Row row = *(refTreeModel2->append());
            row[columns.col_id] = i;
            row[columns.col_value] = (*it)->toString();
        }
    }
}
