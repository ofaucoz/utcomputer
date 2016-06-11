#include "programWidget.h"

ProgramWidget::ProgramWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder) : Gtk::TreeView(
    treeview), builder(builder) {
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    nbAff = 20;
    this->append_column("name", columns.col_id);
    this->append_column("program", columns.col_value);
    for (unsigned int i = 0; i< nbAff; i++) {
        Gtk::TreeModel::Row row = *(refTreeModel->append());
        row[columns.col_id] = "";
        row[columns.col_value] = "";

    }
}

void ProgramWidget::update(Repository *repository) {
    refTreeModel.clear();
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    if (ProgramMap *ObservableMapPointer = static_cast<ProgramMap *>(repository)) {
        std::unordered_map<string, LiteralVector>::const_iterator it = ObservableMapPointer->begin();
        for (unsigned int i = 0; it != ObservableMapPointer->end() && i < nbAff; i++, ++it) {
            Gtk::TreeModel::Row row = *(refTreeModel->append());
            row[columns.col_id] = it->first;
            string value="";
            for(LiteralVector::const_iterator it2 = it->second.begin();it2!=it->second.end();++it2)
            {
              value += (*it2)->toString() + " ";
            }
            row[columns.col_value] = value;

        }
    }
}
