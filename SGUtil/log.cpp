/*
* Copyright (c) 2020 Mohamed E. Saleh
* The code is licensed under the MIT License.
* You can check the file LICENSE for the full license.
*/

#include "log.h"

using namespace sgl;

LogFile lf;

LogFile::LogFile()
{
	path = "";
	printToConsole = true;
}

LogFile::~LogFile()
{

}

void LogFile::setPath(const std::string& p)
{
	path = p;
}

void LogFile::save(const std::string& fileName)
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