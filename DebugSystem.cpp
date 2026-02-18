#include "DebugSystem.h"
#include <chrono>
#include <string>
#include <iostream>
//#include <unordered_map>

using namespace std;

namespace main_player::core::debug
{
    constexpr auto RED = "\033[31m";
    constexpr auto GREEN = "\033[32m";
    constexpr auto RESET = "\033[0m";

    //static unordered_map<std::string, std::string> _dict_log = unordered_map<std::string, std::string>();
    //static unordered_map<std::string, std::string> _dict_error = unordered_map<std::string, std::string>();
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

    /*void add_text_log(const std::string& key, const std::string& log)
    {
        if (_dict_log.contains(key)) _dict_log[key] += log;
        else _dict_log[key] = log;
    }

    void add_text_error(const std::string& key, const std::string& log)
    {
        if (_dict_error.contains(key)) _dict_error[key] += log;
        else _dict_error[key] = log;
    }*/

    //Выводят в консоль и кешируют логи
    void DebugSystem::log(const std::string& tag, const std::string& text)
    {
        auto log = "\n" + get_time() + " " + tag + " => " + text;

        cout << log << std::flush;

        //add_text_log(tag, log);
        //_text_log += log;
    }

    void DebugSystem::log_green(const std::string& tag, const std::string& text)
    {
        auto log = "\n" + get_time() + " " + tag + " => " + text;

        cout << GREEN << log << RESET << std::flush;

        //add_text_log(tag, log);
        //_text_log += log;
    }

    void DebugSystem::error(const std::string& tag, const std::string& text)
    {
        auto log = "\n" + get_time() + " " + tag + " => " + text;

        cout << RED << log << RESET << std::flush;

        //add_text_error(tag, log);
        //_text_error += log;
    }

    //Вывод кешированных логов
    void DebugSystem::info_log()
    {
        std::system("/usr/bin/clear");
        cout << "\n" << _text_log << endl;
    }

    void DebugSystem::info_log(const std::string& tag)
    {
        std::system("/usr/bin/clear");
        //if (_dict_log.contains(tag)) cout << _dict_log[tag] << endl;
        //else
        cout << "\n" << "logs null" << endl;
    }

    void DebugSystem::info_error()
    {
        std::system("/usr/bin/clear");
        cout << "\n" << _text_error << endl;
    }

    void DebugSystem::info_error(const std::string& tag)
    {
        std::system("/usr/bin/clear");
        //if (_dict_error.contains(tag)) cout << _dict_error[tag] << endl;
        //else
        cout << "\n" << "logs null" << endl;
    }
}
