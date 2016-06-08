#include <iostream>
#include <gtkmm.h>
#include "ui/main.h"

using namespace std;
using namespace Gtk;

int main(int argc, char *argv[]) {
    Glib::RefPtr<Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    RefPtr<Builder> builder = Builder::create();
    builder->add_from_file("ui/views/main.glade");
    MainWindow *window1 = nullptr;
    builder->get_widget_derived("window1", window1);
    app->run(*window1);

    delete window1;

    return 0;
}
