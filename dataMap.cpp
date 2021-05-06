#pragma once
#include <iostream>
#include "dataMap.h"



DataMap& DataMap::Instance() {
	static DataMap instance;
	return instance;
}




void DataMap::set(const char key[], double value) {
	dataMap[key] = value;
}

double DataMap::get(const char key[]) {
	return dataMap[key];
}

void DataMap::setAll(double* dataArray) 
{
	dataMap["/instrumentation/airspeed-indicator/indicated-speed-kt"] = dataArray[0];
	dataMap["/sim/time/warp"] = dataArray[1];
	dataMap["/controls/switches/magnetos"] = dataArray[2];
	dataMap["/instrumentation/heading-indicator/offset-deg"] = dataArray[3];
	dataMap["/instrumentation/altimeter/indicated-altitude-ft"] = dataArray[4];
	dataMap["/instrumentation/altimeter/pressure-alt-ft"] = dataArray[5];
	dataMap["/instrumentation/attitude-indicator/indicated-pitch-deg"] = dataArray[6];
	dataMap["/instrumentation/attitude-indicator/indicated-roll-deg"] = dataArray[7];
	dataMap["/instrumentation/attitude-indicator/internal-pitch-deg"] = dataArray[8];
	dataMap["/instrumentation/attitude-indicator/internal-roll-deg"] = dataArray[9];
	dataMap["/instrumentation/encoder/indicated-altitude-ft"] = dataArray[10];
	dataMap["/instrumentation/encoder/pressure-alt-ft"] = dataArray[11];
	dataMap["/instrumentation/gps/indicated-altitude-ft"] = dataArray[12];
	dataMap["/instrumentation/gps/indicated-ground-speed-kt"] = dataArray[13];
	dataMap["/instrumentation/gps/indicated-vertical-speed"] = dataArray[14];
	dataMap["/instrumentation/heading-indicator/indicated-heading-deg"] = dataArray[15];
	dataMap["/instrumentation/magnetic-compass/indicated-heading-deg"] = dataArray[16];
	dataMap["/instrumentation/slip-skid-ball/indicated-slip-skid"] = dataArray[17];
	dataMap["/instrumentation/turn-indicator/indicated-turn-rate"] = dataArray[18];
	dataMap["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = dataArray[19];
	dataMap["/controls/flight/aileron"] = dataArray[20];
	dataMap["/controls/flight/elevator"] = dataArray[21];
	dataMap["/controls/flight/rudder"] = dataArray[22];
	dataMap["/controls/flight/flaps"] = dataArray[23];
	dataMap["/controls/engines/engine/throttle"] = dataArray[24];
	dataMap["/controls/engines/current-engine/throttle"] = dataArray[25];
	dataMap["/controls/switches/master-avionics"] = dataArray[26];
	dataMap["/controls/switches/starter"] = dataArray[27];
	dataMap["/engines/active-engine/auto-start"] = dataArray[28];
	dataMap["/controls/flight/speedbrake"] = dataArray[29];
	dataMap["/sim/model/c172p/brake-parking"] = dataArray[30];
	dataMap["/controls/engines/engine/primer"] = dataArray[31];
	dataMap["/controls/engines/current-engine/mixture"] = dataArray[32];
	dataMap["/controls/switches/master-bat"] = dataArray[33];
	dataMap["/controls/switches/master-alt"] = dataArray[34];
	dataMap["/engines/engine/rpm"] = dataArray[35];
}

void DataMap::printAll() {
	for (const auto& [key, value] : this->dataMap)
	{
		std::cout << key << " = " << value << ";"<< std::endl;
	}
}