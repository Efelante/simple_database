#include <string>
#include <map>
#include <set>
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

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear()){
		return lhs.GetYear() < rhs.GetYear();
	} else if (lhs.GetMonth() != rhs.GetMonth()){
		return lhs.GetMonth() < rhs.GetMonth();
	} else {
		return lhs.GetDay() < rhs.GetDay();
	} 
}

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

void CheckDelimeterAndSkip(stringstream &stream)
{
	if (stream.peek() != '-'){
		throw runtime_error("Wrong date format:");
	} else {
		stream.ignore(1);
	}
}

void CheckMonth(int month)
{
	if (month < 1 || month > 12){
		throw runtime_error("Month value is invalid: " + to_string(month));
	} else {
		// Do nothing
	}
}

void CheckDay(int day)
{
	if (day < 1 || day > 31){
		throw runtime_error("Day value is invalid: " + to_string(day));
	} else {
		// Do nothing
	}
}

Date ParseDate(string date_string)
{
	stringstream date_stream(date_string);
	int year;
	int month;
	int day;
	if (date_stream >> year){
		// Year is a number
		// Read month and day
		CheckDelimeterAndSkip(date_stream);
		if (date_stream >> month){
			// Month is a number
			// Read the day
			CheckDelimeterAndSkip(date_stream);
			if (date_stream >> day){
					string date_tail;
					if(date_stream >> date_tail){
							throw runtime_error("Wrong date format: " +
											date_string);
					} else {
							CheckMonth(month);
							CheckDay(day);
							return Date(Year(year),
											Month(month),
											Day(day));
					}
			} else {
				// Not a day
				throw runtime_error("Wrong date format: " +
						date_string);
			}
		} else {
			// Not a month
			throw runtime_error("Wrong date format: " +
					date_string);
		}
	} else {
		// Not a year
		throw runtime_error("Wrong date format: " +
				    date_string);
	}

}
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Database {
public:
		void AddEvent(const Date& date, const string& event)
		{
				database[date].insert(event);
		}
		bool DeleteEvent(const Date& date, const string& event);
		int  DeleteDate(const Date& date);

		///* ??? */ Find(const Date& date) const;

		void Print() const
		{
			for (const auto &record : database){
				for (const auto &event : record.second){
					cout << record.first << " " << 
						event << 
						endl;
				}
			}
		}
private:
		map<Date, set<string>> database;
};

int main() {
	//Date date1;
	//Date date2;
	//cin >> date1 >> date2;
	//cout << date1 << endl << date2 << endl;
	Database db;

	string command;
	while (getline(cin, command)) {
		if (command != ""){
				stringstream input(command);
				string operation;
				input >> operation;
				if (operation == "Add"){
						cout << "Add command" << endl;
						string date_string;
						input >> date_string;
						Date date;
						try {
								date = ParseDate(date_string);
						} catch (exception &e){
								cout << e.what() << endl;
								return -1;
						}
						cout << date << endl;
						string event;
						input >> event;
						db.AddEvent(date, event);
				} else if (operation == "Del"){
						cout << "Del command" << endl;
				} else if (operation == "Find"){
						cout << "Find command" << endl;
				} else if (operation == "Print"){
						cout << "Print command" << endl;
						db.Print();
				} else {
						cout << "Unknown command" << endl;
				}
		} else {
				// Empty command
		}

		// Считайте команды с потока ввода и обработайте каждую
	}

	return 0;
}
