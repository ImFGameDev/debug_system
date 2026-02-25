#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <vector>

#include "../include/debug_system.h"
#include "../include/debug_api.h"

namespace main_player::core::debug
{
	constexpr auto RED = "\033[31m";
	constexpr auto GREEN = "\033[32m";
	constexpr auto RESET = "\033[0m";

	//options
	static std::unordered_set<std::string> _tags = std::unordered_set<std::string>();
	static bool _is_init = false;
	//data
	static std::string _logs = "";
	static std::vector<std::pair<std::string, std::string>> _list_logs = std::vector<std::pair<std::string,
		std::string>>();

	std::string get_time()
	{
		auto now = std::chrono::system_clock::now();

		std::time_t time = std::chrono::system_clock::to_time_t(now);
		std::tm local_time = *std::localtime(&time);
		std::ostringstream oss;

		oss << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S");

		return oss.str();
	}

	//====== DEBUG SYSTEM ==============================================================================================

	void debug_system::log(const std::string& tag, const std::string& text)
	{
		_list_logs.emplace_back(tag, text);

		if (_tags.contains(tag)) return;

		auto log = get_time() + " " + tag + " => " + text + "\n";

		std::cout << log << std::flush;
	}

	void debug_system::log_green(const std::string& tag, const std::string& text)
	{
		_list_logs.emplace_back(tag, text);

		if (_tags.contains(tag)) return;

		auto log = get_time() + " " + tag + " => " + text + "\n";

		std::cout << GREEN << log << RESET << std::flush;
	}

	void debug_system::error(const std::string& tag, const std::string& text)
	{
		_list_logs.emplace_back(tag, text);

		if (_tags.contains(tag)) return;

		auto log = get_time() + " " + tag + " => " + text + "\n";

		std::cout << RED << log << RESET << std::flush;
	}

	//====== DEBUG API =================================================================================================
	//show
	void debug_api::show_logs() {}

	void debug_api::show_logs(const std::string& tag) {}

	void debug_api::show_errors() {}

	void debug_api::show_errors(const std::string& tag) {}

	//options
	void debug_api::enable_showing_logs_tag(const std::string& tag)
	{
		_tags.insert(tag);
	}

	void debug_api::disable_showing_logs_tag(const std::string& tag)
	{
		_tags.erase(tag);
	}

	void debug_api::enable_showing_logs(const std::string& tag, const std::string& log) {}

	void debug_api::disable_showing_logs(const std::string& tag, const std::string& log) {}
}
