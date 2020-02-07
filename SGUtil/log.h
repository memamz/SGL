/*
* Copyright (c) 2020 Mohamed E. Saleh
* The code is licensed under the MIT License.
* You can check the file LICENSE for the full license.
*
* A class for creating and saving logs.
*/

#ifndef SGLLOG_H
#define SGLLOG_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

namespace sgl
{
	class LogFile
	{
		std::ofstream os;
		std::stringstream ss;
		std::string path;
	public:
		bool printToConsole;

		LogFile();
		~LogFile();

		void setPath(const std::string& p);
		void save(const std::string& fileName = "default.log");

		template<class T>
		LogFile& operator << (T const& val)
		{
			ss << val;
			if (printToConsole)
				std::cout << val;
			return *this;
		}

	};

}

extern sgl::LogFile lf;

#endif
