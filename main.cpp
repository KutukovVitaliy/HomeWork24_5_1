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
        std::getline(std::cin,command);
        if(command == "begin"){
            if(!currentTask.empty()){
                currentTask.at(0).endTime = std::time(nullptr);
                completedTask.push_back(currentTask.at(0));
                currentTask.erase(currentTask.begin());
            }
            std::cout << "Enter the name of the new task: ";
            std::getline(std::cin,tmpTask.name);
            tmpTask.beginTime = std::time(nullptr);
            if(currentTask.empty()){
                currentTask.push_back(tmpTask);
                std::cout << "The new task: " << tmpTask.name << " was successfully added!" << std::endl;

            }
            else{
                std::cout << "An error occurred when adding a new task!" << std::endl;
            }
        }
        else if(command == "end"){
            if(!currentTask.empty()){
                currentTask.at(0).endTime = std::time(nullptr);
                completedTask.push_back(currentTask.at(0));
                std::cout << "The current task " << currentTask.at(0).name << " was successfully completed!" << std::endl;
                currentTask.erase(currentTask.begin());
            }
            else std::cout << "An error occurred when completing a task!" << std::endl;
        }
        else if(command == "status"){
            std::cout << "Completed tasks: " << std::endl;
            for(auto const it : completedTask){
                std::cout << "Name: " << it.name << "   time: " << std::difftime(it.endTime, it.beginTime) / 3600 << std::endl;
            }
            if(!currentTask.empty()){
                std::cout << "Current task:" << std::endl;
                std::cout << "Name: " << currentTask.at(0).name << std::endl;
            }
        }
        else {
            std::cout << "Bad command. Try again!" << std::endl;
        }
    }while(command != "exit");


    return 0;
}
