#include "Task.h"
#include <iostream>

Task::Task(const std::string& title, int priority, const std::string& description, const std::chrono::system_clock::time_point& deadline)
    : title(title), priority(priority), description(description), deadline(deadline) {}

std::string Task::getTitle() const {
    return title;
}

int Task::getPriority() const {
    return priority;
}

std::string Task::getDescription() const {
    return description;
}

std::chrono::system_clock::time_point Task::getDeadline() const {
    return deadline;
}

void Task::displayTask() const {
    std::cout << "Title: " << title << "\nPriority: " << priority << "\nDescription: " << description
        << "\nDeadline: " << std::chrono::system_clock::to_time_t(deadline) << std::endl;
}
