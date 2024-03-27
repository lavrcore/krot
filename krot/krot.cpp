#include "WebApp.h"
#include "Tools.h"
using namespace std;

using namespace Tools;
	

const string API = "1c6fbd94f02e0bfa31e590642d42d8b8";


int main() {
	setlocale(LC_ALL, "RUS");
	using json = nlohmann::json;

	string city;
	cout << "Введите город: ";
	cin >> city;

	WebApp app("http://api.openweathermap.org", API, city);

	json data;
	int choice;
	bool flag = true;

	while (flag) {
		showMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			data = app.getCurrentWeather();
			showCurrentWeather(data);
			break;
		case 2:
			data = app.getFiveDaysForecast();
			showFiveDaysForecast(data);
			break;
		case 3:
			cout << "Введите город: ";
			cin >> city;
			app.setCityName(city);
			break;
		case 4:
			flag = false;
			break;

		}
	}
	return 0;
}