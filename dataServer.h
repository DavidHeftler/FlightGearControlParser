#pragma once
#include <Winsock2.h> 


class DataServer {
private:
	SOCKET serverSocket;
	SOCKET clientSocket;
	DataServer(); // Prevent construction
	~DataServer() { close(); } // Prevent unwanted destruction
	bool connected;
public:
	static DataServer& Instance();
	int waitForConnection(short port);
	int receive(short timesPerSec);
	int close();
	virtual void fromBuffer(char msg[]);
	bool getStatus();
};

 












