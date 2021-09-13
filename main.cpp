#include <iostream>
#include <ctime>
#include <vector>

int main() {
    struct task{
        std::string name;
        std::time_t beginTime = 0;
        std::time_t endTime = 0;
    };
    std::vector<task> currentTask, completedTask;
    std::string command;
    task tmpTask;
    do{
        std::cout << "Enter command: ";
        std::cin >> command;
        if(command == "begin"){
            if(!currentTask.empty()){
                currentTask.at(0).endTime = std::time(nullptr);
                completedTask.push_back(currentTask.at(0));
                currentTask.erase(currentTask.begin());
            }
            std::cout << "Enter the name of the new task: ";
            std::cin >> tmpTask.name;
            tmpTask.beginTime = std::time(nullptr);
            if(currentTask.empty()){
                currentTask.push_back(tmpTask);
                std::cout << "An error occurred when adding a new task!" << std::endl;
            }
            else{
                std::cout << "The new task: " << tmpTask.name << " was successfully added!" << std::endl;
            }
        }
        else if(command == "end"){
            if(!currentTask.empty()){
                currentTask.at(0).endTime = std::time(nullptr);
                completedTask.push_back(currentTask.at(0));
                std::cout << "The current task " << currentTask.at(0).name << " was successfully completed!" << std::endl;
                currentTask.erase(currentTask.begin());
            }
            std::cout << "An error occurred when completing a task!" << std::endl;
        }
        else if(command == "status"){
            std::cout << "" << std::endl;
        }
        else {
            std::cout << "Bad command. Try again!" << std::endl;
        }
    }while(command != "exit");
    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t);
    std::cout << local->tm_hour << ":" << local->tm_min << "  " << local->tm_year <<  std::endl;
    std::cout << std::asctime(local) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
