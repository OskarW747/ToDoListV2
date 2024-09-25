#include "Menus.h"
#include "Definitions.h"

//Base class constructors and methods
Menu::Menu() {
	this->title = "Menu";
	this->optionCount = 0; 
	this->options = nullptr;
	cout << "Menu default construktor" << endl;
}

Menu::Menu(string title, string options[], int optionCount) {
	this->title = title;
	this->optionCount = optionCount;
	this->options = new string[optionCount];
	for (int i = 0; i < optionCount; i++) {
		this->options[i] = options[i];
	}
	cout << "Menu parameterized constructor" << endl;
}

Menu::~Menu() {
	cout << "Menu destructor" << endl;
	delete[] this->options;
}

void Menu::displayMenu() const {
	cout << endl;
	
	// Print the top line
	for (int i = 0; i < MENU_WIDTH; i++) {
		cout << '-';
	}
	cout << endl;

	// Check if the title length is greater than the menu width
	if (title.length() >= MENU_WIDTH) {
		cout << title << endl;
	}
	else {
		int padding = (MENU_WIDTH - title.length()) / 2;

		// Print the spaces
		for (int i = 0; i < padding; i++) {
			cout << ' ';
		}

		cout << title << endl;
	}

	// Print bottom line
	for (int i = 0; i < MENU_WIDTH; i++) {
		cout << '-';
	}
	cout << endl;

	// Print the menu options
	for (int i = 0; i < optionCount; i++) {
		cout << (i + 1) << ") " << options[i] << endl;
	}
}

// MainMenu class constructors
MainMenu::MainMenu() : Menu("Main Menu", new string[3]{ "Add task", "View tasks", "Quit" }, 3) { cout << "MainMenu default constructor" << endl; }

MainMenu::MainMenu(string title, string options[], int optionCount) : Menu(title, options, optionCount) { cout << "MainMenu parameterized constructor" << endl; }

AddTaskTitleMenu::AddTaskTitleMenu() : Menu("Add Task", new string[1]{"Please enter title of new task!"}, 1) { cout << "AddTaskTitleMenu default constructor" << endl; }

AddTaskTitleMenu::AddTaskTitleMenu(string title, string options[], int optionCount) : Menu(title, options, optionCount) { cout << "AddTaskTitleMenu parameterized constructor" << endl; }

AddTaskDescriptionMenu::AddTaskDescriptionMenu() : Menu("Add Task", new string[1]{ "Please enter description of new task!" }, 1) {}

AddTaskDescriptionMenu::AddTaskDescriptionMenu(string title, string options[], int optionCount) : Menu(title, options, optionCount) {}

TaskList::TaskList() : Menu("Task list", new string[1]{ "" }, 0) {}

TaskList::TaskList(string title, string options[], int optionCount) : Menu(title, options, optionCount) {}
