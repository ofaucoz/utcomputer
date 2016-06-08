#include <iostream>
#include <gtkmm.h>
#include <cstring>
#include "lib/utcomputer.h"
#include "lib/literal_definition/atom.h"
#include "lib/literal_definition/whitespace.h"
#include "lib/literal_definition/numeric.h"
#include "lib/literal_definition/expression.h"
#include "lib/literal_definition/operator.h"
#include "lib/literal_definition/program.h"
#include "lib/operator/addition.h"
#include "lib/operator/substraction.h"
#include "lib/operator/division.h"
#include "lib/operator/multiplication.h"
#include "lib/operator/denominator.h"
#include "lib/operator/numerator.h"
#include "lib/operator/modulo.h"
#include "lib/operator/euclidian_division.h"
#include "lib/operator/opposite.h"
#include "ui/main.h"

using namespace std;
using namespace Gtk;

int main(int argc, char* argv[]) {


    Glib::RefPtr<Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    RefPtr<Builder> builder = Builder::create();
    builder->add_from_file("ui/views/main.glade");
    MainWindow* window1 = nullptr;
    builder->get_widget_derived("window1", window1);
    app->run(*window1);

    delete window1;

    return 0;
}
