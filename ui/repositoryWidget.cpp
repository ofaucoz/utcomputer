#include "repositoryWidget.h"


repositoryWidget::repositoryWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder) : Gtk::TreeView(
    treeview), builder(builder) {
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    nbAff = 5;
    this->append_column("ID", columns.col_id);
    this->append_column("value", columns.col_value);
}

void repositoryWidget::update(Repository *repository) {
    Glib::RefPtr<Gtk::ListStore> refTreeModel2 = Gtk::ListStore::create(columns);
    set_model(refTreeModel2);
    if (LiteralsStack *ObservableStackPointer = static_cast<LiteralsStack *>(repository)) {
        vector<LiteralPointer>::const_iterator it = ObservableStackPointer->begin();
        for (unsigned int i = 0; it != ObservableStackPointer->end() && i < nbAff; i++, ++it) {
            Gtk::TreeModel::Row row = *(refTreeModel2->append());
            row[columns.col_id] = i;
            row[columns.col_value] = (*it)->toString();

        }
    }
}
