#ifndef TASK_H
#define TASK_H

#include <iostream>

class Task {
public:

	bool exists;
	int id;
	std::string title;
	std::string description;
	

	Task();
	Task(bool exists, int id, std::string title, std::string description);
	~Task();

	int getId() const { return id; }

	void display();

protected:
	void _save();
	void _load();
};

#endif