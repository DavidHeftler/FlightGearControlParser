#pragma once

#include "dataServer.h"
#include <thread>



//the DataServer thread is kept in a singletone class for handling reasons
class ServerThread {
	~ServerThread() { 
		if(t)
			delete t; 
	}
public:
	std::thread* t = nullptr;

	//singleton
	static ServerThread& Instance();
};
