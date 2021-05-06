#include "client.h"
#include <WS2tcpip.h>



void flightGearClient::sendMsg(const char msg[], int size) {
	int n = 0;
	if ((n = send(server,
		msg,
		size, 0))
		== SOCKET_ERROR) {
		std::cout << "send failed with error: "
			<< WSAGetLastError() << std::endl;
		return;
	}
	//receive();
	return;
}



void flightGearClient::startConnection(short port)
{
	// Input data 
	WSADATA WSAData;

	// Created socket server 
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);

	// If invalid socket created, 
	// return -1 
	if ((server = socket(AF_INET,
		SOCK_STREAM, 0))
		== INVALID_SOCKET) {
		std::cout << "Socket creation failed with error: "
			<< WSAGetLastError() << std::endl;
		return;
	}


	inet_pton(
		AF_INET,
		"127.0.0.1",
		&addr.sin_addr.s_addr
	);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);


	// If connection failed 
	if (connect(server,
		(SOCKADDR*)&addr,
		sizeof(addr))
		== SOCKET_ERROR) {
		std::cout << "Server connection failed with error: "
			<< WSAGetLastError() << std::endl;
		return;
	}

	// If connection established 
	std::cout << "Connected to server!"
		<< std::endl;
	return;
}

void flightGearClient::close() {
	closesocket(server);
	WSACleanup();
}



void flightGearClient::receive() {//receive immidiate response from the simul 
	char buffer[1024] = { 0 };
	// Client executes continuously 
	while (true) {
		int n;
		if ((n = recv(server, buffer,
			sizeof(buffer), 0))
			== SOCKET_ERROR) {
			std::cout << "recv function failed with error: "
				<< WSAGetLastError()
				<< std::endl;
			return;
		}
		if (n > 0)
		{
			std::cout << "Server: " << buffer << std::endl;
			break;
		}
	}
	return;
}


flightGearClient& flightGearClient::Instance() {
	static flightGearClient instance;
	return instance;
}
