#ifndef LO21_UI_MAIN_H
#define LO21_UI_MAIN_H


#include <gtkmm.h>
#include "keyboard_widget.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/kd.h>
#include "keyboard_widget.h"
#include "repository_widget.h"
#include "stack_widget.h"
#include "keyboard_widget.h"
#include "message_tree_view.h"
#include "history_tree_view.h"
#include "variable_widget.h"
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
#include "../lib/operator/program_if.h"
#include "../lib/operator/stack_dup.h"
#include "../lib/operator/numeric_greater.h"
#include "../lib/operator/numeric_greater_equals.h"
#include "../lib/operator/numeric_lesser.h"
#include "../lib/operator/numeric_lesser_equals.h"
#include "../lib/operator/logic_not.h"
#include "../lib/operator/logic_or.h"
#include "../lib/operator/numeric_complex_build.h"
#include "../lib/operator/numeric_complex_imaginary.h"
#include "../lib/operator/numeric_complex_real.h"
#include "../lib/operator/stack_clear.h"
#include "../lib/operator/stack_drop.h"
#include "../lib/operator/stack_undo.h"
#include "../lib/operator/stack_redo.h"
#include "../lib/lexer.h"
#include "../lib/literal_definition/whitespace.h"
#include "../lib/literal_definition/numeric.h"
#include "../lib/literal_definition/operator_numeric.h"
#include "../lib/literal_definition/operator_atom_literal.h"
#include "../lib/literal_definition/operator_strict_comparison.h"
#include "../lib/literal_definition/operator_equal_comparison.h"
#include "../lib/literal_definition/expression.h"
#include "../lib/literal_definition/program.h"
#include "../lib/literal_definition/atom.h"
#include "../lib/utcomputer.h"
#include "../lib/resolver.h"
#include "../lib/runner.h"
#include "message_tree_view.h"
#include "programWidget.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/kd.h>

using namespace std;
using namespace Gtk;
using namespace Glib;

class MainWindow: public Gtk::Window {
protected:
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
    StackWidget *literalStack; //GtkTreeView
    MessageTreeView *messageTree; //GtkTreeView
    HistoryTreeView *historyTree; //GtkTreeView
    RepositoryWidget *variableTree;
    RepositoryWidget *programTree;
    ToggleButton *variableButton;
    ToggleButton *programButton;
    Entry *nbStack;
    Entry *command;
    KeyboardWidget *keyboard; //GtkBox
    TextView *variableEditionTextView;
    TextView *programEditionTextView;
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
    void on_button_keyboard_clicked(string label);
    bool on_key_press_event(GdkEventKey *event) override;
    bool on_program_text_view_enter(GdkEventKey *event);
    bool on_variable_text_view_enter(GdkEventKey *event);

    void on_button_variable_clicked() {
        if (variableButton->get_active()) {
            variableWindow->show();
        } else {
            variableWindow->hide();
        }
    }

    void on_button_program_clicked() {
        if (programButton->get_active()) {
            programWindow->show();
        } else {
            programWindow->hide();
        }
    }

    void on_toggle_button_keyboard_clicked() {
        if (keyboardSwitch->get_active()) {
            keyboard->hide();
        } else {
            keyboard->show();
        }
    }
};


#endif //LO21_UI_MAIN_H
