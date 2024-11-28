#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <filesystem>

#include "Definitions.h"
#include "Menus.h"
#include "Task.h"
#include "SaveLoadSystem.h"

using namespace std;

int menuIndex = MAIN_MENU_INDEX;
bool mainLoop = true;

MainMenu mainMenu;
AddTaskTitleMenu addTaskTitleMenu;
AddTaskDescriptionMenu addTaskDescriptionMenu;
TaskList taskList;
SaveLoadSystem saveLoadSystem;

vector<Task> Tasks;

bool clearScr = false; // Clears screen before printing

void initialize() {
	int tempId;
	std::string tempTitle; 
	std::string tempDescription;

	std::ifstream saveFile("tasks.txt");
	if (saveFile.is_open() == false) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	std::string tempLine;

	while (getline(saveFile, tempLine)) {
		std::cout << tempLine << std::endl;
		std::cout << tempLine[0] << std::endl;


		// Check first character to determine which type
		if (tempLine[0] == 'i') {
			tempLine.erase(0, 1);
			tempId = std::stoi(tempLine);
			
		}
		else if (tempLine[0] == 't') {
			tempLine.erase(0, 1);
			tempTitle = tempLine;
		}
		else if (tempLine[0] == 'd') {
			tempLine.erase(0, 1); 
			tempDescription = tempLine;

			//Check if last tempId is erased to know if new task should be created 
			if (tempId != 0) {
				Task tempTask(false, tempId, tempTitle, tempDescription);
				Tasks.push_back(tempTask);

				tempId = 0;
				tempTitle = "";
				tempDescription = "";
			}
		}
	}

	std::cout << "Size of tasks vector: " << Tasks.size() << std::endl;

}

void printMenu(Menu* _menu) {
	if (clearScr == true) {
		system("cls");

	}

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

		if (Tasks.empty() == false) {
			for (int i = 1; i <= Tasks.size(); i++) {
				Tasks[i].display();
			}
		}
		else {
			std::cout << "No tasks available" << std::endl;
		}

		std::cout << "Type back to go back" << std::endl;

		std::string input;
		getline(cin, input);

		if (input == "back") {
			menuIndex = MAIN_MENU_INDEX;
		}

		

		break;
	}
	}
}

int main() {
	cout << "Hello World" << std::endl;

	//srand(time(0));

	static int lastMenuIndex = 0;

	initialize();

	//printMenu(&mainMenu);

	while (mainLoop == true) {

		if (menuIndex != lastMenuIndex)
		{
			lastMenuIndex = menuIndex;
			cout << "Menu controller updating" << endl;
			menuController();

		}

	}

	saveLoadSystem.save(Tasks);

	return 0;


}