#include "dataServer.h"
#include "dataMap.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

#pragma comment(lib, "Ws2_32.lib")


#define SEC 1000 


int DataServer::waitForConnection(short port) {
	WSADATA WSAData;

	// Created socket server 
	// and client 

	// Socket address for server 
	// and client 
	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);

	// Making server 
	serverSocket = socket(AF_INET,
		SOCK_STREAM, 0);

	// If invalid socket created, 
	// return -1 
	if (serverSocket == INVALID_SOCKET) {
		std::cout << "Socket creation failed with error:"
			<< WSAGetLastError() << std::endl;
		return -1;
	}
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);




	// If socket error occurred, 
	// return -1 
	if (bind(serverSocket,
		(SOCKADDR*)&serverAddr,
		sizeof(serverAddr))
		== SOCKET_ERROR) {
		std::cout << "Bind function failed with error: "
			<< WSAGetLastError() << std::endl;
		return -1;
	}

	// Get the request from 
	// server 
	if (listen(serverSocket, 5)
		== SOCKET_ERROR) {
		std::cout << "Listen function failed with error:"
			<< WSAGetLastError() << std::endl;
		return -1;
	}

	std::cout << "Listening for incoming connections...." << std::endl;


	// Intialise client address 
	int clientAddrSize = sizeof(clientAddr);

	// If connection established 
	if ((clientSocket = accept(serverSocket,
		(SOCKADDR*)&clientAddr,
		&clientAddrSize))
		!= INVALID_SOCKET) {
		connected = true;
		std::cout << "Client connected!" << std::endl;
	}
	return 0;
}

int DataServer::receive(short timesPerSec) {
	char buf[1024] = { 0 };
	while (true) {
		if (recv(clientSocket, buf, sizeof(buf), 0)
			== SOCKET_ERROR) {
			std::cout << "recv function failed with error "
				<< WSAGetLastError() << std::endl;
			return -1;
		}
		fromBuffer(buf);
		memset(buf, 0,
			sizeof(buf));
		Sleep(SEC / timesPerSec);
	}
}


int DataServer::close()
{
	closesocket(clientSocket);

	// If socket closing 
	// failed. 
	if (closesocket(serverSocket)
		== SOCKET_ERROR) {
		std::cout << "Close socket failed with error: "
			<< WSAGetLastError() << std::endl;
		return -1;
	}
	WSACleanup();
	return 0;
}


DataServer::DataServer() {
	clientSocket = INVALID_SOCKET;
	connected = false;
}


void DataServer::fromBuffer(char msg[]) {
	double dataArr[36] = { 0 };
	std::string dt(msg);
	std::string tmp = "";
	int indx = 0;
	for (char c : dt)
	{
		//cout << c;

		if (c == ',')
		{
			char* p;
			double dbl = strtod(tmp.c_str(), &p);
			dataArr[indx++] = dbl;
			tmp = "";
		}
		else
		{
			tmp += c;
		}
		if (indx == 36)
			break;
	}
	DataMap::Instance().setAll(dataArr);
}


bool DataServer::getStatus() { return connected; }


DataServer& DataServer::Instance() {
	static DataServer instance;
	return instance;
}


