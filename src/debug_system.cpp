#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>

#include "../include/debug_system.h"

namespace main_player::core::debug
{
    constexpr auto RED = "\033[31m";
    constexpr auto GREEN = "\033[32m";
    constexpr auto RESET = "\033[0m";

    static std::string _text_log = "";
    static std::string _text_error = "";

    std::string get_time()
    {
        auto now = std::chrono::system_clock::now();

        std::time_t time = std::chrono::system_clock::to_time_t(now);
        std::tm local_time = *std::localtime(&time);
        std::ostringstream oss;

        oss << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S");

        return oss.str();
    }

    void debug_system::log(const std::string& tag, const std::string& text)
    {
        auto log = "\n" + get_time() + " " + tag + " => " + text;

        std::cout << log << std::flush;
    }

    void debug_system::log_green(const std::string& tag, const std::string& text)
    {
        auto log = "\n" + get_time() + " " + tag + " => " + text;

        std::cout << GREEN << log << RESET << std::flush;
    }

    void debug_system::error(const std::string& tag, const std::string& text)
    {
        auto log = "\n" + get_time() + " " + tag + " => " + text;

        std::cout << RED << log << RESET << std::flush;
    }

    void debug_system::info_log()
    {
        std::system("/usr/bin/clear");

        std::cout << "\n" << _text_log << std::endl;
    }

    void debug_system::info_log(const std::string& tag)
    {
        std::system("/usr/bin/clear");

        std::cout << "\n" << "logs null" << std::endl;
    }

    void debug_system::info_error()
    {
        std::system("/usr/bin/clear");

        std::cout << "\n" << _text_error << std::endl;
    }

    void debug_system::info_error(const std::string& tag)
    {
        std::system("/usr/bin/clear");

        std::cout << "\n" << "logs null" << std::endl;
    }
}
