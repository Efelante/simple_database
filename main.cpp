#include <string>
#include <iostream>
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

struct Date {
		Date(){}
		Date(const Year& new_year, const Month& new_month, const Day& new_day){
			year = new_year.value;	
			month = new_month.value;
			day = new_day.value;
		}
		int year;
		int month;
		int day;
};

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
	stream << setfill('0') << setw(4) << date.year;
	stream << delimeter;
	stream << setfill('0') << setw(2) << date.month;
	stream << delimeter;
	stream << setfill('0') << setw(2) << date.day;
	return stream;
}
int main(void)
{
	Date date(Year(2020), Month(12), Day(31));
	Date date1;
	Date date2;
	cin >> date1 >> date2;
	cout << date1 << endl << date2 << endl;
	return 0;
}
