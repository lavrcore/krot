#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;
namespace Tools {
	void showMenu();

	void showCurrentWeather(nlohmann::json data);

	void showFiveDaysForecast(nlohmann::json data);

	
}
