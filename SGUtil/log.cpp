/*
* Copyright (c) 2020 Mohamed E. Saleh
* The code is licensed under the MIT License.
* You can check the file LICENSE for the full license.
*/

#include "log.h"

using namespace sgl;

Log sgl::error(Log::ErrorLog, Log::Error, "ERROR");
Log sgl::warn(Log::WarningLog, Log::Warning, "WARNING");
Log sgl::info(Log::InfoLog, Log::Info, "INFO");

std::ofstream Log::os;
std::stringstream Log::ss;
std::string Log::path = "";
Log::Level Log::displayLevel = Other;

Log::Log(Type t, Level lvl, const std::string& display)
{
	printToConsole = true;
	logType = t;
	logLevel = lvl;
	displayType = display;
	newLine = true;
}

Log::~Log()
{

}

void Log::setDisplayLevel(Level lvl)
{
	displayLevel = lvl;
}

void Log::setMainPath(const std::string& p)
{
	path = p;
}

void Log::saveAll(const std::string& fileName)
{
	std::string f = path + fileName;
	os.open(f);
	if (os.is_open())
	{
		os << ss.str();

		os.close();
		os.clear();
	}
	else std::cout << "Unable to open Log File";
}

void Log::saveLog(const std::string& fileName)
{
	std::string f = path + fileName;
	os.open(f);
	if (os.is_open())
	{
		os << logss.str();

		os.close();
		os.clear();
	}
	else std::cout << "Unable to open Log File";
}