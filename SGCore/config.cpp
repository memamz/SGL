/*
* Copyright (c) 2020 Mohamed E. Saleh
* The code is licensed under the MIT License.
* You can check the file LICENSE for the full license.
*/

#include "config.h"

using namespace sgl;

Config sgl::config;

ConfigParam::ConfigParam()
{

}

Config::Config() : configlog(Log::InfoLog, Log::Info, "CONFIG")
{

}

void Config::init(const std::string &fileName)
{
	
}

void Config::log(bool print)
{
	log("configurations.log", print);
}

void Config::log(const std::string& fileName, bool print)
{
	configlog.printToConsole = print;
	for (auto& it : configs)
	{
		std::string name = (it.second).name;
		if (int* v = std::any_cast<int>(&(it.second).val))
			configlog << name << ": " << *v << "\n";
		else if (float* v = std::any_cast<float>(&(it.second).val))
			configlog << name << ": " << *v << "\n";
		else if (double* v = std::any_cast<double>(&(it.second).val))
			configlog << name << ": " << *v << "\n";
		else if (bool* v = std::any_cast<bool>(&(it.second).val))
			configlog << name << ": " << std::boolalpha << *v << "\n";
		else if (char* v = std::any_cast<char>(&(it.second).val))
			configlog << name << ": " << std::any_cast<char>((it.second).val) << "\n";
		else if (std::string* v = std::any_cast<std::string>(&(it.second).val))
			configlog << name << ": " << *v << "\n";
		else if (std::any_cast<const char*>(&(it.second).val))
			configlog << name << ": " << std::string(std::any_cast<const char*>((it.second).val)) << "\n";
		else
			configlog << name << ": unrecognized value\n";

	}
	configlog.saveLog(fileName);
}

void Config::setPath(const std::string& p)
{
	path = p;
}

void Config::save(const std::string &fileName)
{

}

Config::~Config()
{

}

