#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Definitions.h"
#include "Menus.h"
#include "Task.h"

using namespace std;

int menuIndex = MAIN_MENU_INDEX;
bool mainLoop = true;

MainMenu mainMenu;
AddTaskTitleMenu addTaskTitleMenu;
AddTaskDescriptionMenu addTaskDescriptionMenu;
TaskList taskList;

vector<Task> Tasks;

void initialize() {

}

void printMenu(Menu* _menu) {
	_menu->displayMenu();
}

bool checkMatch(int target, const std::vector<int>& arr) {
	for (int num : arr) {
		if (num == target) {
			return true;
		}
	}
	return false;
}

// Function to get integer input and check if input is valid
int getIntInput(const std::vector<int> _validInputs) {

	string _input;
	int _inputInt = 0;

	while (true)
	{
		cout << "> ";

		getline(cin, _input);

		try {
			_inputInt = stoi(_input);
		}
		catch (invalid_argument e) {
			cout << "Invalid input! Input must be of integer type!" << endl;
			continue;
		}

		if (checkMatch(_inputInt, _validInputs) == false) {
			cout << "Invalid input! Input must correspond with given alternatives!" << endl;
		}
		else {
			cout << "Input is valid!" << endl;
			return _inputInt;
		}
	}

}

/*
* A function for generating random numbers
* Not working for the moment
*/
int randomInt(int start, int range) {
	return (start + rand() % range);
}

// Function to get string input and check if input is valid
//string getStringInput(string _validKeyWords) {
//	return 0;
//}

void menuController() {
	switch (menuIndex) {
	case(MAIN_MENU_INDEX): {
		printMenu(&mainMenu);

		std::vector<int> validInputs = { MAIN_ADD_TASK, MAIN_VIEW_TASKS, MAIN_EXIT };
		int _input = getIntInput(validInputs);

		switch (_input) {
		case(MAIN_ADD_TASK):
			menuIndex = ADD_TASK_TITLE_INDEX;
			break;
		case(MAIN_VIEW_TASKS):
			menuIndex = VIEW_TASKS_INDEX;
			break;
		case(MAIN_EXIT):
			mainLoop = false;
			break;
		}
		break;
	}
	case (ADD_TASK_TITLE_INDEX): {
		printMenu(&addTaskTitleMenu);

		std::string _input;
		getline(cin, _input);

		Task tempTask(false, randomInt(100000, 999999), _input, "");

		// Continue with adding notedescription after title have been added
		printMenu(&addTaskDescriptionMenu);

		std::string input;
		getline(cin, input);

		tempTask.description = input;

		Tasks.push_back(tempTask);

		Tasks[0].display();

		menuIndex = MAIN_MENU_INDEX;
		break;
	}
	case (VIEW_TASKS_INDEX): {

		printMenu(&taskList);


		for (int i = 0; i < Tasks.size(); i++) {
			Tasks[i].display();
		}

		break;
	}
	}
}

int main() {
	cout << "Hello World" << std::endl;

	srand(time(0));

	static int lastMenuIndex = 0;

	//printMenu(&mainMenu);

	while (mainLoop == true) {

		if (menuIndex != lastMenuIndex)
		{
			lastMenuIndex = menuIndex;
			cout << "Menu controller updating" << endl;
			menuController();

		}

	}
	return 0;


}