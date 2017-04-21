#include<iostream>
#include<string>

#include "Logger.h"

/* Static variable to hold the number of instances
   at any instant, not more than one instance is allowed */
int Logger::log_instance = 0;

Logger::Logger(std::string path)
{
	this->logpath = path;

	try {
		if (this->logpath.empty()) {
			throw " NULL LOG FILE PATH";
		} else {
			this->logfile.open(this->logpath.c_str(), std::fstream::out);
			if (!this->logfile.is_open()) {
				std::cout << " Log file not opened, Check the path and permissions" <<std::endl;
			} else {
				this->logfile << " Logger instatiation success!! "<<this->logpath << std::endl;
			}
		}
	} catch (std::string str) {
		std::cout << " Exception :" << str << std::endl;
	}
}

Logger::~Logger()
{
	Logger::log_instance--;
	this->logfile << " Logger: Destructor called "<< std::endl;
	this->logfile.close();
}

Logger *Logger::logger_get_instance(std::string logpath)
{
	if ((Logger::log_instance == 0) && (!logpath.empty())) {
		Logger *log = new Logger(logpath);
		Logger::log_instance++;
		return log;
	}
	return NULL;
}

void Logger::log_debug(std::string str)
{
	if (!(str.empty())) {
		this->logfile << str <<std::endl;
	}
}
