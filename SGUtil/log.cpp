/*
* Copyright (c) 2020 Mohamed E. Saleh
* The code is licensed under the MIT License.
* You can check the file LICENSE for the full license.
*/

#include "log.h"

using namespace sgl;

Log sgl::lf;

Log::Log()
{
	path = "";
	printToConsole = true;
}

Log::~Log()
{

}

void Log::setLevel(Level lvl)
{
	level = lvl;
}

void Log::setPath(const std::string& p)
{
	path = p;
}

void Log::save(const std::string& fileName)
{
	std::string f = path + fileName;
	os.open(f);
	if (os.is_open())
	{
		os << ss.str();

		os.close();
	}
	else std::cout << "Unable to open Log File";
}

void Log::error(const std::string& msg)
{
	if(level >= Error)
		std::cout << "[ERROR]: " << msg << std::endl;
}

void Log::warn(const std::string& msg)
{
	if (level >= Warning)
		std::cout << "[WARNING]: " << msg << std::endl;
}

void Log::info(const std::string& msg)
{
	if (level >= Info)
		std::cout << "[INFO]: " << msg << std::endl;
}