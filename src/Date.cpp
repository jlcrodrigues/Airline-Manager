#include "Date.h"


Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    is_date = true;
}

Date::Date(unsigned int hour, unsigned int minute) {
    this->hour = hour;
    this->minute = minute;
    is_date = false;
}

unsigned Date::getDay() const {
    return day;
}

unsigned Date::getMonth() const {
    return month;
}

unsigned Date::getYear() const {
    return year;
}

unsigned Date::getHour() const {
    return hour;
}

unsigned Date::getMinute() const {
    return minute;
}

void Date::displayDate() {
    cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/"  << year << endl;
}

void Date::displayTime() {
    cout << setfill('0') << setw(2) << hour << "h:" << setfill('0') << setw(2) << minute << "m" << endl;
}

void Date::displayDateTime() {
    cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/"  << year << " - " << setfill('0') << setw(2) << hour << "h:" << setfill('0') << setw(2) << minute << "m" << endl;
}

string Date::toString(Date date) const{
    stringstream ss;
    string s;
    if(is_date){
        ss << setfill('0') << setw(2) <<date.day << "/" << setfill('0') << setw(2) << date.month << "/" << date.year;
        ss >> s;
        return s;
    }
    else{
        ss << setfill('0') << setw(2) <<date. hour << ":" << setfill('0') << setw(2) << date.minute;
        ss >> s;
        return s;
    }
}

bool Date::isDate() {
    return is_date;
}

