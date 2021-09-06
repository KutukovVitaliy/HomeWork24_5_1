#include <iostream>
#include <ctime>

int main() {
    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t);
    std::cout << local->tm_hour << ":" << local->tm_min << "  " << local->tm_year <<  std::endl;
    std::cout << std::asctime(local) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
