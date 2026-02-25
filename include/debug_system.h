#ifndef DEBUG_SYSTEM_H
#define DEBUG_SYSTEM_H

#include <string>

namespace main_player::core::debug
{
	class debug_system
	{
	public:
		debug_system() = delete;

		~debug_system() = delete;

		static void log(const std::string& tag, const std::string& text);

		static void log_green(const std::string& tag, const std::string& text);

		static void error(const std::string& tag, const std::string& text);
	};
}

#endif //DEBUG_SYSTEM_H
