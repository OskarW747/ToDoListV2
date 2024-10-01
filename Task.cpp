#include "Task.h"
#include <random>
#include <fstream>
#include <string>
#include <filesystem>

Task::Task() {
	this->exists = false;
	this->id = NULL;
	this->title = "";
	this->description = "";
	std::cout << "Task default constructor:\t" << this->id << std::endl;
}

Task::Task(bool exists, int id, std::string title, std::string description) {
	this->exists = exists;
	this->id = id;
	this->title = title;
	this->description = description;
	std::cout << "Task added! Values:\t" << this->exists << "\t" << this->id << "\t" << this->title << "\t" << this->description << std::endl;
}

void Task::_save() {
	std::ofstream saveFile;
	saveFile.open(std::to_string(this->id) + ".Task.txt");
	saveFile << this->title << "\n" << this->description;
	saveFile.close();
	std::cout << "Task saved:\t" << this->id << std::endl;
	//std::cout << "Savefile path:\t" << std::filesystem::current_path() << std::endl;
}

void Task::_load() {
	std::ifstream saveFile(this->id + "save.txt");

	if (saveFile.is_open() == false) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}
	
	int lineCount = 0;
	std::string line;
	while (std::getline(saveFile, line)) {
		lineCount++;
		std::cout << "Linecount: " << lineCount << std::endl;

		if (lineCount <= 1) {
			this->title = line;
		}
		else {
			this->description = line;
		}
	}

}

Task::~Task() {
	//this->_save();
}

void Task::display() {
	std::cout << "Task:\t" << this->id << "\t" << this->title << "\t" << this->description << std::endl;
}