#pragma once
#include <iostream>
#include <string>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <vector>
using namespace std;

class WebApp {
	httplib::Client* cli;
	string API;
	string request;
	nlohmann::json result;
	string cityName;
	
public:
	void setCityName(std::string& cityName);

	WebApp();

	WebApp(string client, string API, string cityName);

	nlohmann::json getResult(string request);

	nlohmann::json getCurrentWeather();

	nlohmann::json getFiveDaysForecast();


};