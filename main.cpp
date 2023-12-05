#include "Task.h"
#include "TaskManager.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "\n---------------------\n";
        std::cout << "������ �����\n";
        std::cout << "1. ������ ������\n";
        std::cout << "2. �������� ������\n";
        std::cout << "3. ���������� ������\n";
        std::cout << "4. ����� �����\n";
        std::cout << "5. ³��������� ������ �����\n";
        std::cout << "6. �����\n";
        std::cout << "��� ����: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "������� ���. ���� �����, ������ ���� �����.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
        case 1: {
            std::string title, description;
            int priority;
            std::chrono::system_clock::time_point deadline;

            std::cout << "������ ����� ������: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, title);

            std::cout << "������ �������� (���� �����): ";
            std::cin >> priority;

            if (std::cin.fail()) {
                std::cout << "������� ���. ���� �����, ������ ���� �����.\n";
                clearInputBuffer();
                continue;
            }

            std::cout << "������ ���� ������: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, description);

            std::cout << "������ ���� �� ��� ��������� (� ������ YYYY MM DD HH MM): ";
            int year, month, day, hour, minute;
            std::cin >> year >> month >> day >> hour >> minute;

            if (std::cin.fail()) {
                std::cout << "������� ���. ���� �����, ������ ���� �����.\n";
                clearInputBuffer();
                continue;
            }

            std::tm tm_deadline = { 0, minute, hour, day, month - 1, year - 1900 };
            deadline = std::chrono::system_clock::from_time_t(std::mktime(&tm_deadline));

            Task newTask(title, priority, description, deadline);
            taskManager.addTask(newTask);
            break;
        }
        case 2: {
            std::string title;
            std::cout << "������ ����� ������ ��� ���������: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, title);
            taskManager.removeTask(title);
            break;
        }
        case 3: {
            std::string title, description;
            int priority;
            std::chrono::system_clock::time_point deadline;

            std::cout << "������ ����� ������ ��� �����������: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, title);

            std::cout << "������ ���� ����� ������: ";
            std::getline(std::cin, title);

            std::cout << "������ ����� �������� (���� �����): ";
            std::cin >> priority;

            if (std::cin.fail()) {
                std::cout << "������� ���. ���� �����, ������ ���� �����.\n";
                clearInputBuffer();
                continue;
            }

            std::cout << "������ ����� ���� ������: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, description);

            std::cout << "������ ���� ���� �� ��� ��������� (� ������ YYYY MM DD HH MM): ";
            int year, month, day, hour, minute;
            std::cin >> year >> month >> day >> hour >> minute;

            if (std::cin.fail()) {
                std::cout << "������� ���. ���� �����, ������ ���� �����.\n";
                clearInputBuffer();
                continue;
            }

            std::tm tm_deadline = { 0, minute, hour, day, month - 1, year - 1900 };
            deadline = std::chrono::system_clock::from_time_t(std::mktime(&tm_deadline));

            Task updatedTask(title, priority, description, deadline);
            taskManager.editTask(title, updatedTask);
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            taskManager.displayTasksForDay(std::chrono::system_clock::now());
            break;
        }
        case 6: {
            std::cout << "����� �� ������������! �� ���������.\n";
            return 0;
        }
        default:
            std::cout << "������� ����. ���� �����, ������� �����.\n";
        }
    }

    return 0;
}
