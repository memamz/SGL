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
	class Log
	{
	public:
		enum Level : unsigned char
		{
			Error, Warning, Info
		};

	private:
		std::ofstream os;
		std::stringstream ss;
		std::string path;
		Level level = Info;

	public:
		bool printToConsole;

		Log();
		~Log();

		void setLevel(Level lvl);
		void setPath(const std::string& p);
		void save(const std::string& fileName = "default.log");
		void error(const std::string& msg);
		void warn(const std::string& msg);
		void info(const std::string& msg);

		template<class T>
		Log& operator << (T const& val)
		{
			ss << val;
			if (printToConsole)
				std::cout << val;
			return *this;
		}

	};

	extern Log lf;
}


#endif
