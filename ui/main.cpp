#include "main.h"
#include "../lib/exception/unspported_literal.h"


MainWindow::MainWindow(BaseObjectType *window, const RefPtr<Gtk::Builder> &glade) : Gtk::Window(window), builder(glade),
                                                                                    computer(nullptr),
                                                                                    literalStack(nullptr) {
    /*
     * Load view file
     */
    // Operators

    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));
    operatorsMap.set("DIV", OperatorPointer(new EuclidianDivisionOperator));
    operatorsMap.set("MOD", OperatorPointer(new ModuloOperator));
    operatorsMap.set("NEG", OperatorPointer(new OppositeOperator));
    operatorsMap.set("NUM", OperatorPointer(new NumeratorOperator));
    operatorsMap.set("DEN", OperatorPointer(new DenominatorOperator));


    /*
     * Lexer
     */
    lexer = new Lexer();
    lexer->addDefinition(new WhitespaceLiteralDefinition());
    lexer->addDefinition(new NumericLiteralDefinition);
    lexer->addDefinition(new OperatorLiteralDefinition);
    lexer->addDefinition(new ExpressionLiteralDefinition);
    lexer->addDefinition(new ProgramLiteralDefinition);
    lexer->addDefinition(new AtomLiteralDefinition);

    /*
     * Resolver
     */
    resolver = new Resolver(operatorsMap, programsMap, variablesMap,
                            LiteralDefinitionPointer(new OperatorLiteralDefinition));

    /*
     * Runner
     */
    runner = new Runner(operatorsMap, stack);

    /*
     * Application
     */
    computer = new UTComputer(*lexer, *resolver, *runner);

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

    // Load derived widgets

    builder->get_widget_derived("stackTreeView", literalStack);
    builder->get_widget_derived("messageTreeView", messageTree);
    builder->get_widget_derived("historyTreeView", historyTree);
    builder->get_widget_derived("keyboardBox", keyboard);
    builder->get_widget_derived("variableTreeView", variableTree);
    builder->get_widget_derived("programTreeView", programTree);

    // Attach observers

    stack.attach(literalStack);


    // Connect signals
    command->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_entry_command_activated));
    nbStack->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_entry_nbStack_activated));
    keyboardSwitch->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_toggle_button_keyboard_clicked));
    variableButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_variable_clicked));
    programButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_program_clicked));
    add_events(Gdk::KEY_PRESS_MASK);
    for (unsigned int i = 0; i < 19; i++) {
        keyboard->getButton(i).signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &MainWindow::on_button_keyboard_clicked), keyboard->getButton(i).get_label()));
    }

    iterCommand=historyTree->getIterCommand();


}

void MainWindow::on_button_keyboard_clicked(string label) {
    if (label == "=") {
        computer->execute(commandInput);
        cout << stack.top()->toString() << endl;
        historyTree->update(commandInput);
        commandInput = "";
    }
    else commandInput += label;

}

void MainWindow::on_entry_command_activated() {
    try {
        commandInput = command->get_text();
        computer->execute(commandInput);
        historyTree->update(commandInput);
        iterCommand=historyTree->getIterCommand();
    }
    catch (const InvalidOperandException &exception1) {
        messageTree->update(exception1.getValue());
        if(bip->get_active()){
            cout << '\a' << endl;
        }
    }
    catch (const InvalidSyntaxException &exception2) {
        messageTree->update(exception2.getValue());
        if(bip->get_active()){
            cout << '\a' << endl;
        }
    }
    catch (const UndefinedAtomException &exception3) {
        messageTree->update(exception3.getValue());
        if(bip->get_active()){
            cout << '\a' << endl;
        }
    }
    catch (const UnsupportedLiteralException &exception4) {
        messageTree->update(exception4.getValue());
        if(bip->get_active()){
            cout << '\a' << endl;
        }
    }


}


void MainWindow::on_entry_nbStack_activated() {
    std::stringstream s;
    unsigned int result;

    s << nbStack->get_text().raw();
    s >> result;
    literalStack->setNb(result);
    literalStack->update(&stack);
}

bool MainWindow::on_key_press_event(GdkEventKey* key_event)
{
    //GDK_CONTROL_MASK -> the 'Ctrl' key(mask)
    //GDK_KEY_Z -> the 'Z' key
    //GDK_KEY_Y -> the 'Y' key

    //select the first radio button, when we press alt + 1
    if((key_event->keyval == GDK_KEY_z)&&(key_event->state &(GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_CONTROL_MASK)
    {
        cout << "ctrl + Z was pressed" << endl;
        if(iterCommand!=0){
            iterCommand--;
        }
        command->set_text(historyTree->getTabCommand(iterCommand));
        //returning true, cancels the propagation of the event
        return true;
    }
    else if((key_event->keyval == GDK_KEY_y) &&
            (key_event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_CONTROL_MASK)
    {
        if(iterCommand < historyTree->getIterCommand()){
            iterCommand++;
        }
        command->set_text(historyTree->getTabCommand(iterCommand));
        //and the second radio button, when we press alt + 2
        cout << "ctrl + Y was pressed" << endl;
        return true;
    }
    else if(key_event->keyval == GDK_KEY_Escape)
    {
        //close the window, when the 'esc' key is pressed
        hide();
        return true;
    }

    //if the event has not been handled, call the base class
    return Gtk::Window::on_key_press_event(key_event);
}