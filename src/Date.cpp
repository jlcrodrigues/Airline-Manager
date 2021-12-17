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

string Date::displayDate() {
    string s;
    stringstream ss;
    ss << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/"  << year << endl;
    ss >> s;
    return s;
}

string Date::displayTime() {
    string s;
    stringstream ss;
    ss << setfill('0') << setw(2) << hour << "h:" << setfill('0') << setw(2) << minute << "m" << endl;
    ss >> s;
    return s;}

string Date::displayDateTime() {
    string s;
    stringstream ss;
    ss << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/"  << year << " - " << setfill('0') << setw(2) << hour << "h:" << setfill('0') << setw(2) << minute << "m" << endl;
    ss >> s;
    return s;}

string Date::toString(Date date) const{
    stringstream ss;
    string s;
    if(is_date){
        ss << setfill('0') << setw(2) <<date.day << "/" << setfill('0') << setw(2) << date.month << "/" << setw(4) << date.year;
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

bool Date::operator<(const Date &d) const{
    if(d.is_date){
        if(year == d.getYear()) return month < d.getMonth();
        if(month == d.getMonth()) return day < d.getDay();
        return year < d.getYear();
    }

    if(hour == d.getHour()) return minute < d.getMinute();
    return hour < d.getHour();
}

bool Date::operator==(const Date &d) const{
    if(d.is_date){
        if((year == d.getYear()) && (month == d.getMonth()) && (day == d.getDay())) return true;
        return false;
    }

    if((hour == d.getHour()) && (minute == d.getMinute())) return true;
    return false;
}

bool Date::checkDate(const Date &d) const
{
    if ((d.getDay() >= 1) && (d.getDay() <= 30) && (d.getMonth() >= 1) && (d.getMonth() >= 12) && (d.getMonth() != 2)) // every month expect february
    {
        return true;
    }
    else if ((d.getDay() >= 1) && (d.getDay() <= 31) && (d.getMonth() >= 1) && (d.getMonth() >= 12) && (d.getMonth() != 2) && (d.getMonth() != 4) && (d.getMonth() !=6) && (d.getMonth() != 9) && (d.getMonth() != 11)) // all months with 31 days
    {
        return true;
    }
    else if ((d.getDay() >= 1) && (d.getDay() <= 28) && (d.getMonth() >= 1) && (d.getMonth() >= 12)) // includes february
    {
        return true;
    }
    return false;
}

