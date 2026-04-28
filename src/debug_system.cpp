#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <vector>
#include <shared_mutex>
#include <mutex>

#include "../include/debug_system.h"
#include "../include/debug_api.h"

namespace main_player::core::debug
{
	constexpr auto RED = "\033[31m";
	constexpr auto GREEN = "\033[32m";
	constexpr auto RESET = "\033[0m";

	//options - защищены мьютексом
	static std::unordered_set<std::string> _tags = std::unordered_set<std::string>();
	static std::shared_mutex _tags_mutex;

	//data - защищены мьютексом
	static std::string _logs = "";
	static std::vector<std::pair<std::string, std::string>> _list_logs = std::vector<std::pair<std::string, std::string>>();
	static std::shared_mutex _logs_mutex;

	std::string get_time()
	{
		auto now = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(now);

		std::tm local_time;

#ifdef _WIN32
		localtime_s(&local_time, &time);
#else
		localtime_r(&time, &local_time);
#endif

		std::ostringstream oss;
		oss << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S");
		return oss.str();
	}

	// Вспомогательная функция для безопасной записи в лог
	void write_to_console(const std::string& color, const std::string& tag, const std::string& text)
	{
		std::string log;
		log.reserve(64 + tag.length() + text.length());

		log += get_time();
		log += " ";
		log += tag;
		log += " => ";
		log += text;
		log += "\n";

		std::cout << color << log << RESET << std::flush;
	}

	//====== DEBUG SYSTEM ==============================================================================================

	void debug_system::log(const std::string& tag, const std::string& text)
	{
		// Сохраняем лог в историю
		{
			std::unique_lock<std::shared_mutex> lock(_logs_mutex);
			_list_logs.emplace_back(tag, text);
		}

		// Проверяем, нужно ли показывать этот тег
		{
			std::shared_lock<std::shared_mutex> lock(_tags_mutex);
			if (_tags.contains(tag)) return;
		}

		write_to_console("", tag, text);
	}

	void debug_system::log_green(const std::string& tag, const std::string& text)
	{
		{
			std::unique_lock<std::shared_mutex> lock(_logs_mutex);
			_list_logs.emplace_back(tag, text);
		}

		{
			std::shared_lock<std::shared_mutex> lock(_tags_mutex);
			if (_tags.contains(tag)) return;
		}

		write_to_console(GREEN, tag, text);
	}

	void debug_system::error(const std::string& tag, const std::string& text)
	{
		{
			std::unique_lock<std::shared_mutex> lock(_logs_mutex);
			_list_logs.emplace_back(tag, text);
		}

		{
			std::shared_lock<std::shared_mutex> lock(_tags_mutex);
			if (_tags.contains(tag)) return;
		}

		write_to_console(RED, tag, text);
	}

	//show
	void debug_api::show_logs()
	{
		std::shared_lock<std::shared_mutex> lock(_logs_mutex);
		for (const auto& [tag, text] : _list_logs)
		{
			std::cout << get_time() << " " << tag << " => " << text << std::endl;
		}
	}

	void debug_api::show_logs(const std::string& tag)
	{
		std::shared_lock<std::shared_mutex> lock(_logs_mutex);
		for (const auto& [log_tag, text] : _list_logs)
		{
			if (log_tag == tag)
			{
				std::cout << get_time() << " " << log_tag << " => " << text << std::endl;
			}
		}
	}

	void debug_api::show_errors()
	{
		// Эта функциональность требует отдельного хранения ошибок
		// Пока просто заглушка
		std::cout << "show_errors: not implemented yet" << std::endl;
	}

	void debug_api::show_errors(const std::string& tag)
	{
		std::cout << "show_errors: not implemented yet" << std::endl;
	}

	//options
	void debug_api::enable_showing_logs_tag(const std::string& tag)
	{
		std::unique_lock<std::shared_mutex> lock(_tags_mutex);
		_tags.insert(tag);
	}

	void debug_api::disable_showing_logs_tag(const std::string& tag)
	{
		std::unique_lock<std::shared_mutex> lock(_tags_mutex);
		_tags.erase(tag);
	}

	void debug_api::enable_showing_logs(const std::string& tag, const std::string& log)
	{
		// Заглушка для будущей реализации
	}

	void debug_api::disable_showing_logs(const std::string& tag, const std::string& log)
	{
		// Заглушка для будущей реализации
	}
}