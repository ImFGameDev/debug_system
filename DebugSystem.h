#pragma once
#include <string>

using namespace std;

namespace main_player::core::debug
{
	class DebugSystem
	{
	public:
		DebugSystem() = delete;
		~DebugSystem() = delete;

		static void log(const std::string& tag,const  std::string& text);

		static void log_green(const std::string& tag, const std::string& text);

		static void info_log();

		static void info_log(const std::string& tag);

		static void error(const std::string& tag,const  std::string& text);

		static void info_error();

		static void info_error(const std::string& tag);
	};
}
