#include "servThread.h"
#include <iostream>


ServerThread& ServerThread::Instance() {
	static ServerThread instance;
	return instance;
}
