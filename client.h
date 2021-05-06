#pragma once
#include <Winsock2.h>
#include <iostream>



class flightGearClient {
	//singlton stuff
	flightGearClient() { server = INVALID_SOCKET; }
	~flightGearClient() { close(); } // Prevent unwanted destruction
private:
	SOCKET server;
public:
	void startConnection(short port);
	void sendMsg(const char msg[], int size);
	void receive();	
	void close();
	static flightGearClient& Instance();

	//singleton
	flightGearClient& operator=(const flightGearClient&) = delete;
	flightGearClient(flightGearClient&) = delete;
};




