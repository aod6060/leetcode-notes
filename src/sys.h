#ifndef SYS_H
#define SYS_H



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

namespace app {
    // Registers section
    void reg(std::string name, std::function<void(std::map<std::string, std::function<void()>>&)>);

    void run(int argc, char** argv);

    void register_app_commands(std::map<std::string, std::function<void()>>& context);

    void print_commands();

}

#endif