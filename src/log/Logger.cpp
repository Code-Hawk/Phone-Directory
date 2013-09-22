#include "Logger.h"
#include<iostream>
#include<string> 

int Logger::log_instance = 0; 

Logger::Logger(string path){
this->logpath = path;
try{
  
  if(this->logpath.empty()){
     throw " NULL LOG FILE PATH";
    } 
  else{
       this->logfile.open(this->logpath.c_str(), std::fstream::out);
       if(!this->logfile.is_open())
           std::cout << " Log file not opened, Check the path and permissions" << std::endl;
      else{
          this->logfile << " log file opened and I am writing the first line "<<this->logpath << endl;
        }
  } 
  }
 catch(string str){
      std::cout << " Exception :" << str <<std::endl;
}

}

Logger::~Logger(){
   Logger::log_instance--;   
   cout << " Logger: Destructor called "<< endl;
   this->logfile.close();
}

Logger * Logger::logger_get_instance(string logpath){
        
         if((Logger::log_instance == 0) && (!logpath.empty())){
            Logger* log = new Logger(logpath);
            Logger::log_instance++;
            return log;
      }
   return NULL;

 }

//std::fstream& operator<<(std::fstream &fstream

void Logger::log_debug(string str){
     if(!(str.empty())){
     int i=10;  
     this->logfile << str << i;
}
}
