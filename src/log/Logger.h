#ifndef _LOGGER_H
#define _LOGGER_H
#include <fstream>
using namespace std;

/* A singleton class which logs all the debug messages to the logs.txt */
class Logger
{
public:
	static Logger *logger_get_instance(std::string logpath);
	static int log_instance;
	~Logger();
	void log_debug(std::string log);
private:
	Logger(std::string logpath);
	string logpath;
	fstream logfile;
};
#endif

