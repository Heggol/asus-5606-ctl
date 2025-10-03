#include "Commands.h"
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
#include <string>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if(!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string get_fan_state() {
    try {
        return exec("pkexec fan_state get");
    } catch (const std::runtime_error& e) {
        std::cerr << "Error getting fan state: " << e.what() << std::endl;
        return "unknown";
    }
}

void set_fan_state(int state) {
    if (state >= 0 && state <= 3) {
        std::string command = "pkexec fan_state set " + std::to_string(state);
        system(command.c_str());
    } else {
        std::cerr << "Invalid fan state" << std::endl;
    }
}