#ifndef LO21_UI_MAIN_H
#define LO21_UI_MAIN_H


#include <gtkmm.h>
#include "keyboardWidget.h"
#include "repositoryWidget.h"
#include "../lib/operator/interface.h"
#include "../lib/operator/addition.h"
#include "../lib/operator/substraction.h"
#include "../lib/operator/division.h"
#include "../lib/operator/multiplication.h"
#include "../lib/operator/euclidian_division.h"
#include "../lib/operator/modulo.h"
#include "../lib/operator/opposite.h"
#include "../lib/operator/numerator.h"
#include "../lib/operator/denominator.h"
#include "../lib/exception/unspported_literal.h"
#include "../lib/operator/eval.h"
#include "../lib/operator/logic_and.h"
#include "../lib/operator/logic_different.h"
#include "../lib/operator/logic_equals.h"
#include "../lib/operator/logic_greater.h"
#include "../lib/operator/logic_greater_equals.h"
#include "../lib/operator/logic_lesser.h"
#include "../lib/operator/logic_lesser_equals.h"
#include "../lib/operator/logic_not.h"
#include "../lib/operator/logic_or.h"
#include "../lib/operator/numeric_complex_build.h"
#include "../lib/operator/numeric_complex_imaginary.h"
#include "../lib/operator/numeric_complex_real.h"
#include "../lib/operator/stack_clear.h"
#include "../lib/operator/stack_drop.h"
#include "../lib/lexer.h"
#include "../lib/literal_definition/whitespace.h"
#include "../lib/literal_definition/numeric.h"
#include "../lib/literal_definition/operator_numeric.h"
#include "../lib/literal_definition/operator_strict_comparison.h"
#include "../lib/literal_definition/operator_equal_comparison.h"
#include "../lib/literal_definition/expression.h"
#include "../lib/literal_definition/program.h"
#include "../lib/literal_definition/atom.h"
#include "../lib/utcomputer.h"
#include "../lib/resolver.h"
#include "../lib/runner.h"
#include "messageTreeView.h"
#include "historyTreeView.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/kd.h>

using namespace std;
using namespace Gtk;
using namespace Glib;

class MainWindow : public Gtk::Window {
protected:
    unsigned int iterCommand;
    Glib::RefPtr<Gtk::Builder> builder;
    Window *variableWindow;
    Window *programWindow;
    LiteralsStack stack;
    OperatorMap operatorsMap;
    VariableMap variablesMap;
    ProgramMap programsMap;
    Lexer *lexer;
    Resolver *resolver;
    Runner *runner;
    repositoryWidget *literalStack; //GtkTreeView
    messageTreeView *messageTree; //GtkTreeView
    historyTreeView *historyTree; //GtkTreeView
    repositoryWidget *variableTree;
    repositoryWidget *programTree;
    ToggleButton *variableButton;
    ToggleButton *programButton;
    Entry *nbStack;
    Entry *command;
    keyboardWidget *keyboard; //GtkBox
    ToggleButton *keyboardSwitch;
    std::string commandInput;
    UTComputer *computer;
    CheckButton *bip;

public:
    MainWindow(BaseObjectType *window, const Glib::RefPtr<Gtk::Builder> &glade);

    virtual ~MainWindow() { };

    void on_entry_command_activated();

    void on_entry_command_changed();

    bool on_entry_command_focused(GdkEventFocus *event);

    void on_entry_nbStack_activated();

    void on_button_variable_clicked() { if (variableButton->get_active())variableWindow->show(); else variableWindow->hide(); }

    void on_button_program_clicked() { if (programButton->get_active())programWindow->show(); else programWindow->hide(); }

    void on_button_keyboard_clicked(string label);

    void on_toggle_button_keyboard_clicked() { if (keyboardSwitch->get_active())keyboard->hide(); else keyboard->show(); }

    bool on_key_press_event(GdkEventKey *event) override;
};


#endif //LO21_UI_MAIN_H
