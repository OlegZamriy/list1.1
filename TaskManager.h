#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Task.h"
#include <vector>

class TaskManager {
public:
    void addTask(const Task& task);
    void removeTask(const std::string& title);
    void editTask(const std::string& title, const Task& updatedTask);

    std::vector<Task> searchByTitle(const std::string& title) const;
    std::vector<Task> searchByPriority(int priority) const;
    std::vector<Task> searchByDescription(const std::string& description) const;
    std::vector<Task> searchByDeadline(const std::chrono::system_clock::time_point& deadline) const;

    void displayTasksForDay(const std::chrono::system_clock::time_point& day) const;
    void displayTasksForWeek(const std::chrono::system_clock::time_point& week) const;
    void displayTasksForMonth(const std::chrono::system_clock::time_point& month) const;

    void sortByPriority();
    void sortByDeadline();

private:
    std::vector<Task> tasks;
};

#endif 
