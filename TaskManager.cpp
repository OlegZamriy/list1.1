#include "TaskManager.h"
#include <iostream>
#include <algorithm>

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::removeTask(const std::string& title) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [title](const Task& task) {
        return task.getTitle() == title;
        }), tasks.end());
}

void TaskManager::editTask(const std::string& title, const Task& updatedTask) {
    for (auto& task : tasks) {
        if (task.getTitle() == title) {
            task = updatedTask;
            break;
        }
    }
}

std::vector<Task> TaskManager::searchByTitle(const std::string& title) const {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (task.getTitle() == title) {
            result.push_back(task);
        }
    }
    return result;
}

std::vector<Task> TaskManager::searchByPriority(int priority) const {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (task.getPriority() == priority) {
            result.push_back(task);
        }
    }
    return result;
}

std::vector<Task> TaskManager::searchByDescription(const std::string& description) const {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (task.getDescription() == description) {
            result.push_back(task);
        }
    }
    return result;
}

std::vector<Task> TaskManager::searchByDeadline(const std::chrono::system_clock::time_point& deadline) const {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (task.getDeadline() == deadline) {
            result.push_back(task);
        }
    }
    return result;
}

void TaskManager::displayTasksForDay(const std::chrono::system_clock::time_point& day) const {
    std::cout << "Список справ на день:\n";
    for (const auto& task : tasks) {
        if (task.getDeadline() >= day && task.getDeadline() < day + std::chrono::hours(24)) {
            task.displayTask();
        }
    }
}

void TaskManager::displayTasksForWeek(const std::chrono::system_clock::time_point& week) const {
    std::cout << "Список справ на тиждень:\n";
    for (const auto& task : tasks) {
        if (task.getDeadline() >= week && task.getDeadline() < week + std::chrono::hours(24 * 7)) {
            task.displayTask();
        }
    }
}

void TaskManager::displayTasksForMonth(const std::chrono::system_clock::time_point& month) const {
    std::cout << "Список справ на місяць:\n";
    for (const auto& task : tasks) {
        if (task.getDeadline() >= month && task.getDeadline() < month + std::chrono::hours(24 * 30)) {
            task.displayTask();
        }
    }
}

void TaskManager::sortByPriority() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
        });
}

void TaskManager::sortByDeadline() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getDeadline() < b.getDeadline();
        });
}
