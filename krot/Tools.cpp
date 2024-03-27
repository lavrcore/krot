#include "Tools.h"
#include <string>


void Tools::showMenu() {
	cout << "1 - Посмотреть погоду." << std::endl;
	cout << "2 - Посмотреть прогноз на 5 дней." << std::endl;
	cout << "3 - Ввести новый город." << std::endl;
	cout << "4 - Выход" << std::endl;
}


void Tools::showCurrentWeather(nlohmann::json data) {
	cout << "Погода: " << data["weather"][0]["main"] << std::endl;
	cout << "Температура: " << (int)(data["main"]["temp"].get<double>() - 273.15) << endl;
}


void Tools::showFiveDaysForecast(nlohmann::json data) {
	for (int i = 0; i < data["list"].size(); i++) {
		cout << data["list"][i]["dt_txt"];
		cout << " " << data["list"][i]["weather"][0]["main"];
		cout << " Temp: " << (int)(data["list"][i]["main"]["temp"].get<double>() - 273.15) << endl;
	}
}
void Tools::showFiveDaysForecast(nlohmann::json data) {
	int i = 0;
	int j = i + 1;
	string dateDay;
	string dateDayJ;
	int counter = 0;
	double sum = 0;
	while (i < data["list"].size()) {
		dateDay = data["list"][i]["dt_txt"].get<string>().substr(8, 2);
		counter = 1;
		sum = data["list"][i]["main"]["temp"].get<double>() - 273.15;
		dateDayJ = data["list"][j]["dt_txt"].get<double>() - 273.15;
		while (dateDay == dateDayJ && j < data["list"].size()) {
			counter++;
			sum+= data["list"][j]["main"]["temp"].get<double>() - 273.15;
			dateDayJ = data["list"][j]["dt_txt"].get<double>() - 273.15;
			j++;
		}
		cout << data["list"][i]["dt_txt"].get<string>().substr(0, 10);
		cout << "Average Temp: " << (int)(sum / counter) << endl;
		i = j;
		j = i + 1;
	}
}
