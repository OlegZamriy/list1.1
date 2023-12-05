#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>

class Task {
public:
    Task(const std::string& title, int priority, const std::string& description, const std::chrono::system_clock::time_point& deadline);

    std::string getTitle() const;
    int getPriority() const;
    std::string getDescription() const;
    std::chrono::system_clock::time_point getDeadline() const;

    void displayTask() const;

private:
    std::string title;
    int priority;
    std::string description;
    std::chrono::system_clock::time_point deadline;
};

#endif 
