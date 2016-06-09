#include "main.h"

MainWindow::MainWindow(BaseObjectType *window, const RefPtr<Gtk::Builder> &glade) : Gtk::Window(window), builder(glade),
                                                                                    computer(nullptr),
                                                                                    literalStack(nullptr) {
    /*
     * Load view file
     */

    /*
     * Lexer
     */
    lexer = new Lexer();
    lexer->addDefinition(new WhitespaceLiteralDefinition());
    lexer->addDefinition(new NumericLiteralDefinition);
    lexer->addDefinition(new OperatorNumericLiteralDefinition);
    lexer->addDefinition(new OperatorEqualComparisonLiteralDefinition);
    lexer->addDefinition(new OperatorStrictComparisonLiteralDefinition);
    lexer->addDefinition(new ExpressionLiteralDefinition);
    lexer->addDefinition(new ProgramLiteralDefinition);
    lexer->addDefinition(new AtomLiteralDefinition);

    /*
     * Resolver
     */
    resolver = new Resolver(operatorsMap, programsMap, variablesMap,
                            LiteralDefinitionPointer(new OperatorAtomLiteralDefinition));

    /*
     * Runner
     */
    runner = new Runner(operatorsMap, stack);

    /*
     * Application
     */
    computer = new UTComputer(*lexer, *resolver, *runner);

    // Operators

    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("ADD", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));
    operatorsMap.set("DIV", OperatorPointer(new EuclidianDivisionOperator));
    operatorsMap.set("MOD", OperatorPointer(new ModuloOperator));
    operatorsMap.set("NEG", OperatorPointer(new OppositeOperator));
    operatorsMap.set("NUM", OperatorPointer(new NumeratorOperator));
    operatorsMap.set("DEN", OperatorPointer(new DenominatorOperator));
    operatorsMap.set("EVAL", OperatorPointer(new EvalOperator(*computer)));
    operatorsMap.set("AND", OperatorPointer(new LogicAndOperator));
    operatorsMap.set("NOT", OperatorPointer(new LogicNotOperator));
    operatorsMap.set("OR", OperatorPointer(new LogicOrOperator));
    operatorsMap.set("!=", OperatorPointer(new LogicDifferentOperator));
    operatorsMap.set("=", OperatorPointer(new LogicEqualsOperator));
    operatorsMap.set(">", OperatorPointer(new LogicGreaterOperator));
    operatorsMap.set(">=", OperatorPointer(new LogicGreaterEqualsOperator));
    operatorsMap.set("<", OperatorPointer(new LogicLesserOperator));
    operatorsMap.set("<=", OperatorPointer(new LogicLesserEqualsOperator));
    operatorsMap.set("$", OperatorPointer(new NumericComplexBuildOperator));
    operatorsMap.set("IM", OperatorPointer(new NumericComplexImaginaryOperator));
    operatorsMap.set("RE", OperatorPointer(new NumericComplexRealOperator));
    operatorsMap.set("CLEAR", OperatorPointer(new StackClearOperator));
    operatorsMap.set("DROP", OperatorPointer(new StackDropOperator));

    /*
     * Create main window
     */

    // Load non-derived widgets

    builder->get_widget("commandEntry", command);
    builder->get_widget("nbStackEntry", nbStack);
    builder->get_widget("variableToggleButton", variableButton);
    builder->get_widget("programToggleButton", programButton);
    builder->get_widget("keyboardToggleButton", keyboardSwitch);
    builder->get_widget("variableWindow", variableWindow);
    builder->get_widget("programWindow", programWindow);
    builder->get_widget("checkButtonBip", bip);
    builder->get_widget("programText",programEditionTextView);
    builder->get_widget("variableText",variableEditionTextView);

    // Load derived widgets

    builder->get_widget_derived("stackTreeView", literalStack);
    builder->get_widget_derived("messageTreeView", messageTree);
    builder->get_widget_derived("historyTreeView", historyTree);
    builder->get_widget_derived("keyboardBox", keyboard);
    builder->get_widget_derived("variableTreeView", variableTree);
    builder->get_widget_derived("programTreeView", programTree);

    // Attach observers

    stack.attach(literalStack);
    variablesMap.attach(variableTree);

    // Make TextView editable
    programEditionTextView->set_editable(true);
    variableEditionTextView->set_editable(true);

    // Connect signals
    programEditionTextView->signal_key_release_event().connect(sigc::mem_fun(*this, &MainWindow::on_program_text_view_enter));
    variableEditionTextView->signal_key_release_event().connect(sigc::mem_fun(*this, &MainWindow::on_variable_text_view_enter));
    command->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_entry_command_activated));
    command->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_entry_command_changed));
    command->signal_focus_in_event().connect(sigc::mem_fun(*this, &MainWindow::on_entry_command_focused));
    nbStack->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_entry_nbStack_activated));
    keyboardSwitch->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_toggle_button_keyboard_clicked));
    variableButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_variable_clicked));
    programButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_program_clicked));
    add_events(Gdk::KEY_PRESS_MASK);
    add_events(Gdk::FOCUS_CHANGE_MASK);
    for (unsigned int i = 0; i < 19; i++) {
        keyboard->getButton(i).signal_clicked().connect(
            sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &MainWindow::on_button_keyboard_clicked),
                                      keyboard->getButton(i).get_label()));
    }
}

bool MainWindow::on_program_text_view_enter(GdkEventKey *key_event) {
    if (key_event->keyval == 0xFF0D) { //catch enter key

        return true;
    }
    return true;
}

bool MainWindow::on_variable_text_view_enter(GdkEventKey *key_event) {
    if (key_event->keyval == 0xFF0D) { //catch enter key
        return true;
    }
    return true;
}

void MainWindow::on_button_keyboard_clicked(string label) {
    if (label == "=") {
        computer->execute(commandInput);
        cout << stack.top()->toString() << endl;
        historyTree->update(commandInput);
        commandInput = "";
    }else {
        commandInput += label;
        command->set_text(commandInput);
    }
}

void MainWindow::on_entry_command_changed() {
    string input = command->get_text();
    if(input=="+"||input=="-"||input=="*"||input=="/"){
        try {
            computer->execute(input);
            historyTree->update(input);
        }
        catch (const InvalidOperandException &exception1) {
            messageTree->update(exception1.getValue());
            if (bip->get_active()) {
                cout << '\a' << endl;
            }
        }
        catch (const InvalidSyntaxException &exception2) {
            messageTree->update("Undefined literal :" + exception2.getValue());
            if (bip->get_active()) {
                cout << '\a' << endl;
            }
        }
        catch (const UndefinedAtomException &exception3) {
            messageTree->update("Undefined atom :" + exception3.getValue());
            if (bip->get_active()) {
                cout << '\a' << endl;
            }
        }
        catch (const UnsupportedLiteralException &exception4) {
            messageTree->update("Unsupported literal :" + exception4.getValue());
            if (bip->get_active()) {
                cout << '\a' << endl;
            }
        }
        command->set_text("");
    }
}

bool MainWindow::on_entry_command_focused(GdkEventFocus *event)
{
    if(command->get_text()=="Type your command here ..."){
        command->set_text("");
    }
}

void MainWindow::on_entry_command_activated() {
    try {
        commandInput = command->get_text();
        computer->execute(commandInput);
        historyTree->update(commandInput);
    }
    catch (const InvalidOperandException &exception1) {
        messageTree->update(exception1.getValue());
        if (bip->get_active()) {
            cout << '\a' << endl;
        }
    }
    catch (const InvalidSyntaxException &exception2) {
        messageTree->update("Unknown literal :" + exception2.getValue());
        if (bip->get_active()) {
            cout << '\a' << endl;
        }
    }
    catch (const UndefinedAtomException &exception3) {
        messageTree->update("Undefined atom : " + exception3.getValue());
        if (bip->get_active()) {
            cout << '\a' << endl;
        }
    }
    catch (const UnsupportedLiteralException &exception4) {
        messageTree->update(exception4.getValue());
        if (bip->get_active()) {
            cout << '\a' << endl;
        }
    }
    command->set_text("");
    commandInput="";
}


void MainWindow::on_entry_nbStack_activated() {
    std::stringstream s;
    unsigned int result;

    s << nbStack->get_text().raw();
    s >> result;
    literalStack->setNb(result);
    literalStack->update(&stack);
}

bool MainWindow::on_key_press_event(GdkEventKey *key_event) {
    //GDK_CONTROL_MASK -> the 'Ctrl' key(mask)
    //GDK_KEY_z -> the 'z' key
    //GDK_KEY_y -> the 'y' key

    //case ctrl+z is pressed
    if ((key_event->keyval == GDK_KEY_z) &&
        (key_event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_CONTROL_MASK) {

        //returning true, cancels the propagation of the event
        return true;
    }//case ctrl+y is pressed
    else if ((key_event->keyval == GDK_KEY_y) &&
             (key_event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_CONTROL_MASK) {

        return true;
    }
    else if (key_event->keyval == GDK_KEY_Escape) {
        //close the window, when the 'esc' key is pressed
        hide();
        return true;
    }
    //if the event has not been handled, call the base class
    return Gtk::Window::on_key_press_event(key_event);
}
