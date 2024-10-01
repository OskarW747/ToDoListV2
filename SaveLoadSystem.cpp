#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "SaveLoadSystem.h"
#include "Task.h"


void SaveLoadSystem::save(std::vector<Task> tasks) {

	std::ofstream saveFile;
	saveFile.open("tasks.txt");
	
	for (int i = 0; i < tasks.size(); i++) {
		saveFile << tasks[i].id << "\n" << tasks[i].title << "\n" << tasks[i].description << "\n";
	}
	saveFile.close();

	std::cout << "Tasks saved" << std::endl;
}

