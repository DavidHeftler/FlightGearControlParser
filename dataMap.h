#pragma once

#include <string>
#include <map>
#include <atomic>



class DataMap {
	//singletone
	DataMap() {}
	~DataMap() {} 

	std::map<std::string, std::atomic<double>> dataMap;
public:
	void set(const char key[], double value);
	double get(const char key[]);
	//for dataServer use. stores data received by the simulator
	void setAll(double* dataArray);
	void printAll();

	//singleton stuff
	static DataMap& Instance();
	DataMap(const DataMap&) = delete; 
	DataMap& operator=(const DataMap&) = delete;
};