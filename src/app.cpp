#include "sys.h"
#include "prefix_sums/prefix_sums.h"

namespace app {

    static std::vector<std::function<void(std::map<std::string, std::function<void()>>&)>> sectionCallbacks;

    static std::map<std::string, std::function<void()>> appCallbacks;

    // Registers section
    void reg(std::function<void(std::map<std::string, std::function<void()>>&)> section) {
        sectionCallbacks.push_back(section);
    }

    void run(int argc, char** argv) {

        // Register Sections
        reg(app::register_app_commands);
        reg(presums::register_examples);
        
        if(argc > 1) {
            for(int i = 0; i < sectionCallbacks.size(); i++) {
                sectionCallbacks[i](appCallbacks);
            }

            if(appCallbacks.find(argv[1]) != appCallbacks.end()) {
                appCallbacks.at(argv[1])();
            } else {
                std::cout << "Error: this app " << argv[1] << " doesn't exist.\n";
                std::cout << "if you wan't a complete list of app you can use with this command.\n";
                std::cout << "Please use \"print-command\" in the [app] argument for further details!\n" ;
            }
        } else {
            std::cout << "./run [app]\n";
            std::cout << "if you wan't a complete list of app you can use with this command.\n";
            std::cout << "Please use \"print-command\" in the [app] argument for further details!\n" ;
        }
    }

    void register_app_commands(std::map<std::string, std::function<void()>>& context) {
        context["print-command"] = print_commands;
    }

    void print_commands() {
        std::cout << "List of commands the application can use... ./run [app] \n";
        std::cout << "```````````````````````````````````````````\n";

        for(std::map<std::string, std::function<void()>>::iterator it = appCallbacks.begin(); it != appCallbacks.end(); it++) {
            std::cout << it->first << "\n";
        }

        std::cout << "```````````````````````````````````````````\n";
    }
}