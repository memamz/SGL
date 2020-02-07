/*
* Copyright (c) 2020 Mohamed E. Saleh
* The code is licensed under the MIT License.
* You can check the file LICENSE for the full license.
*
* A class for setting configurations.
*/

#ifndef SGLCONFIG_H
#define SGLCONFIG_H

#include <string>
#include <vector>
#include <unordered_map>
#include <any>

#include "log.h"

namespace sgl
{
	struct ConfigParam
	{
		std::string id;
		std::string name;
		std::any val;

		ConfigParam();

		template <typename T>
		ConfigParam(const std::string& pid, T value, const std::string& pname)
		{
			id = pid;
			val = value;
			name = pname;
		}

		template <typename T>
		T getValue()
		{
			return std::any_cast<T>(val);
		}

	};

	class Config
	{
		std::unordered_map<std::string, ConfigParam> configs;
		std::string path;
		LogFile configlog;

	public:

		// Default Constructor
		Config();

		// Default Destructor
		~Config();

		// Initialize Configurations from File
		void init(const std::string &fileName);

		// Register a Parameter
		template <typename T>
		void registerParam(const std::string& pid, T value, const std::string& paramName = "")
		{
			ConfigParam param;
			param.id = pid;
			param.val = value;
			if (paramName != "")
				param.name = paramName;
			else
				param.name = pid;

			if (configs.find(pid) == configs.end())
				configs[pid] = param;
			else
				configlog << "Parameter (" << pid << ") already exists\n";

		}

		// Adjust a Parameter
		template <typename T>
		void adjust(const std::string& pid, T val, const std::string& paramName = "")
		{
			if (configs.find(pid) != configs.end())
			{
				ConfigParam param;
				param.id = pid;
				param.val = val;
				if (paramName != "")
					param.name = paramName;
				else
					param.name = configs[pid].name;

				configs[pid] = param;
			}
			else
				configlog << "Parameter (" << pid << ") doesn't exist\n";
		}

		// Log Configurations
		void log(bool print = true);
		void log(const std::string& fileName, bool print = true);

		// Set Configurations Path
		void setPath(const std::string& path);

		// Save Configurations to file
		void save(const std::string &fileName);

		// Get Configuration
		template <typename T>
		T get(const std::string& pid)
		{
			if (configs.find(pid) != configs.end())
				return (configs[pid]).getValue<T>();
			configlog << "Parameter (" << pid << ") doesn't exist\n";
			return false;
		}

		// Fix this
		template <typename T>
		T operator[] (const std::string& pid)
		{
			if (configs.find(pid) != configs.end())
				return (configs[pid]).getValue();
			configlog << "Parameter (" << pid << ") doesn't exist\n";
			return false;
		}

	};

	extern Config config;
}

#endif

