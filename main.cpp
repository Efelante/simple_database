#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Year {
	explicit Year(int new_year){
		value = new_year;
	}
	int value;
};

struct Month {
	explicit Month(int new_month){
		value = new_month;
	}
	int value;
};

struct Day {
	explicit Day(int new_day){
		value = new_day;
	}
	int value;
};

class Date {
public:
	Date(){}
	Date(const Year& new_year, 
	     const Month& new_month, 
	     const Day& new_day){
		year = new_year.value;	
		month = new_month.value;
		day = new_day.value;
	}
	int GetYear() const {return year;};
	int GetMonth() const {return month;};
	int GetDay() const {return day;};
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs);

istream& operator>>(istream &stream, Date &date)
{
	int year;
	int month;
	int day;
	stream >> year;
	stream.ignore(1);
	stream >> month;
	stream.ignore(1);
	stream >> day;
	date = Date(Year(year), Month(month), Day(day));
	return stream;
}

ostream& operator<<(ostream &stream, const Date &date)
{
	char delimeter = '-';
	stream << setfill('0') << setw(4) << date.GetYear();
	stream << delimeter;
	stream << setfill('0') << setw(2) << date.GetMonth();
	stream << delimeter;
	stream << setfill('0') << setw(2) << date.GetDay();
	return stream;
}
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Database {
public:
  void AddEvent(const Date& date, const string& event);
  bool DeleteEvent(const Date& date, const string& event);
  int  DeleteDate(const Date& date);

  ///* ??? */ Find(const Date& date) const;
  
  void Print() const;
};

int main() {
	//Date date1;
	//Date date2;
	//cin >> date1 >> date2;
	//cout << date1 << endl << date2 << endl;
	//Database db;

	string command;
	while (getline(cin, command)) {
		stringstream input(command);
		if (command == "Add"){
			cout << "Add command" << endl;
		} else if (command == "Del"){
			cout << "Del command" << endl;
		} else if (command == "Find"){
			cout << "Find command" << endl;
		} else if (command == "Print"){
			cout << "Print command" << endl;
		} else {
			cout << "Unknown command" << endl;
		}

		// Считайте команды с потока ввода и обработайте каждую
	}

	return 0;
}
