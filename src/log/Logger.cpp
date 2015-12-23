#include "Logger.h"
#include<iostream>
#include<string>

/* Static variable to hold the number of instances
   at any instant, not more than one instance is allowed */
int Logger::log_instance = 0;

/* Private Constructor */
Logger::Logger(string path)
{

	this->logpath = path;
	try {

		if (this->logpath.empty()) {
			throw " NULL LOG FILE PATH";
		} else {
			this->logfile.open(this->logpath.c_str(), std::fstream::out);
			if (!this->logfile.is_open()) {
				std::cout << " Log file not opened, Check the path and permissions" << std::endl;
			} else {
				this->logfile << " log file opened and I am writing the first line "<<this->logpath << endl;
			}
		}
	} catch (string str) {
		std::cout << " Exception :" << str <<std::endl;
	}

}

/*Logger desstructor -- reduce the instance variable and also, close the file. */
Logger::~Logger()
{
	Logger::log_instance--;
	this->logfile << " Logger: Destructor called "<< endl;
	this->logfile.close();
}

/* Static function of the logger class which acts as an interface to
   get the Logger object */

Logger *Logger::logger_get_instance(string logpath)
{

	if ((Logger::log_instance == 0) && (!logpath.empty())) {
		Logger *log = new Logger(logpath);
		Logger::log_instance++;
		return log;
	}
	return NULL;

}

/* TODO operator <<  overloading on fstream object of the Logger class */
void Logger::log_debug(string str)
{
	if (!(str.empty())) {
		this->logfile << str <<endl;
	}
}
