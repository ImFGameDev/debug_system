#ifndef DEBUG_API_H
#define DEBUG_API_H

#include <string>

namespace main_player::core::debug
{
	class debug_api
	{
	public:
		debug_api() = delete;

		~debug_api() = delete;

		static void show_logs();

		static void show_logs(const std::string& tag);

		static void show_errors();

		static void show_errors(const std::string& tag);

		static void enable_showing_logs_tag(const std::string& tag);

		static void disable_showing_logs_tag(const std::string& tag);

		static void enable_showing_logs(const std::string& tag, const std::string& log);

		static void disable_showing_logs(const std::string& tag, const std::string& log);
	};
}

#endif //DEBUG_API_H
