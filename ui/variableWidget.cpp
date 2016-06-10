#include "variableWidget.h"

VariableWidget::VariableWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder) : Gtk::TreeView(
    treeview), builder(builder) {
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    nbAff = 10;
    this->append_column("name", columns.col_id);
    this->append_column("value", columns.col_value);
    for (unsigned int i = 0; i< nbAff; i++) {
        Gtk::TreeModel::Row row = *(refTreeModel->append());
        row[columns.col_id] = "";
        row[columns.col_value] = "";

    }
}

void VariableWidget::update(Repository *repository) {
    refTreeModel.clear();
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    if (VariableMap *ObservableMapPointer = static_cast<VariableMap *>(repository)) {
        std::unordered_map<string, LiteralPointer>::const_iterator it = ObservableMapPointer->begin();
        for (unsigned int i = 0; it != ObservableMapPointer->end() && i < nbAff; i++, ++it) {
            Gtk::TreeModel::Row row = *(refTreeModel->append());
            row[columns.col_id] = it->first;
            row[columns.col_value] = it->second->toString();

        }
    }
}
