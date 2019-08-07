#pragma once
#include "../stdafx.h"
#include <string>

namespace SharedLib
{
	class EXPORT_SYMBOL Logger
	{
	public:
		Logger(std::string loggerName);

		~Logger();

		Logger& debug(std::string message);

	private:
		std::string mName;
	};
}
