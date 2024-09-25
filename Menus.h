#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include "Definitions.h"

using namespace std;

// Base class for a menu
class Menu {
public:
	Menu();
	Menu(string title, string options[], int optionCount);
	virtual ~Menu();

	virtual void displayMenu() const;
protected:
	string title;
	string* options;
	int optionCount;
};

class MainMenu: public Menu {
public:
	MainMenu();
	MainMenu(string title, string options[], int optionCount);

private:

};

class AddTaskTitleMenu : public Menu {
public:
	AddTaskTitleMenu();
	AddTaskTitleMenu(string title, string options[], int optionCount);

private:
};

class AddTaskDescriptionMenu : public Menu {
public:
	AddTaskDescriptionMenu();
	AddTaskDescriptionMenu(string title, string options[], int optionCount);
};

class TaskList : public Menu {
public:
	TaskList();
	TaskList(string title, string options[], int optionCount);
};

#endif