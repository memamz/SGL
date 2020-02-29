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
			Error_High, Error, Error_Low, 
			Warning_High, Warning, Warning_low, 
			Info_0, Info_1, Info_2, Info_3, Info_4, Info_5, Info, 
			Other_0, Other_1, Other_2, Other_3, Other_4, Other_5, Other
		};
		enum Type : unsigned char
		{
			ErrorLog, WarningLog, InfoLog, OtherLog
		};

	private:
		static std::ofstream os;
		static std::stringstream ss;
		static std::string path;
		static Level displayLevel;

		std::stringstream logss;
		Type logType;
		Level logLevel;
		std::string displayType;
		bool newLine;


	public:
		bool printToConsole;

	public:
		Log(Type t, Level lvl, const std::string& display);
		~Log();

		static void setDisplayLevel(Level lvl);
		static void setMainPath(const std::string& p);
		static void saveAll(const std::string& fileName = "default.log");

		void saveLog(const std::string& fileName);

		template<class T>
		Log& operator << (T const& val)
		{
			if ((displayLevel >= logLevel))
			{
				if (newLine)
				{
					ss << "[" << displayType << "]: ";
					logss << "[" << displayType << "]: ";
					if (printToConsole)
						std::cout << "[" << displayType << "]: ";
					newLine = false;
				}
				std::stringstream temp;
				temp << val;
				ss << val;
				logss << val;
				if (printToConsole)
					std::cout << val;

				if (temp.str().find("\n") != std::string::npos)
					newLine = true;
			}
			
			return *this;
		}

	};

	extern Log error;
	extern Log warn;
	extern Log info;
}


#endif
