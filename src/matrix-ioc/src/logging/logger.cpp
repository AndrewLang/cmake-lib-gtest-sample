#include "stdafx.h"

#include "logging/logger.h"
#include "common/StringExtensions.h"
#include <iostream>

namespace Matrix
{
	Logger::Logger(std::string loggerName)
		: mName(loggerName)
	{
	}

	Logger::~Logger()
	{
	}

	Logger& Logger::debug(std::string message)
	{
		std::cout << "[" << StringExtensions::getTimestamp() << "] " << "[" << mName << "] " << message << std::endl;

		return *this;
	}
}