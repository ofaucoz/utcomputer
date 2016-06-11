#include "keyboard_widget.h"

KeyboardWidget::KeyboardWidget(BaseObjectType *box, const Glib::RefPtr<Gtk::Builder> &builder)
    : Gtk::Box(box), builder(builder) {
    builder->get_widget("button_0", button[0]);
    builder->get_widget("button_1", button[1]);
    builder->get_widget("button_2", button[2]);
    builder->get_widget("button_3", button[3]);
    builder->get_widget("button_4", button[4]);
    builder->get_widget("button_5", button[5]);
    builder->get_widget("button_6", button[6]);
    builder->get_widget("button_7", button[7]);
    builder->get_widget("button_8", button[8]);
    builder->get_widget("button_9", button[9]);
    builder->get_widget("button_plus", button[10]);
    builder->get_widget("button_minus", button[11]);
    builder->get_widget("button_div", button[12]);
    builder->get_widget("button_mult", button[13]);
    builder->get_widget("button_opCro", button[14]);
    builder->get_widget("button_equal", button[15]);
    builder->get_widget("button_cloCro", button[16]);
    builder->get_widget("button_undo", button[17]);
    builder->get_widget("button_redo", button[18]);
}
