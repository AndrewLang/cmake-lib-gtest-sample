#pragma once
#include "../stdafx.h"
#include <string>

namespace Matrix
{
	class EXPORT Logger
	{
	public:
		Logger(std::string loggerName);

		~Logger();

		Logger& debug(std::string message);

	private:
		std::string mName;
	};
}
