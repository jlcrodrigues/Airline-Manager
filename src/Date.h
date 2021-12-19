#ifndef FEUP_AED_DATE_H
#define FEUP_AED_DATE_H

#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Date
{
public:

    /** Date's default constructor **/
    Date() = default;

    /**
    * Constructor for Date
    * @param day - day of Date
    * @param month - month of Date
    * @param year - year of Date
    */
    Date(unsigned int day, unsigned int month, unsigned int year);

    /**
     * Constructor for Time
     * @param hour - hour of Time
     * @param minute - minute of Time
     */
    Date(unsigned int hour, unsigned int minute);

    /**
    * Getter for day
    * @return - Returns Date's day
    */
    unsigned getDay() const;

    /**
    * Getter for month
    * @return - Returns Date's month
    */
    unsigned getMonth() const;

    /**
    * Getter for year
    * @return - Returns Date's year
    */
    unsigned getYear() const;

    /**
     * Getter for hour
     * @return - Returns Date's hour
     */
    unsigned getHour() const;

    /**
    * Getter for minute
    * @return - Returns Date's minute
    */
    unsigned getMinute() const;

    /**
     * Setter for day.
     * @param day - day value to set
     */
    void setDay(unsigned int day);

    /**
     * Setter for month.
     * @param month - month value to set
     */
    void setMonth(unsigned int month);

    /**
     * Setter for year.
     * @param year - year value to set
     */
    void setYear(unsigned int year);

    /**
     * Setter for hour.
     * @param hour - hour value to set
     */
    void setHour(unsigned int hour);

    /**
     * Setter for minute.
     * @param minute - minute value to set
     */
    void setMinute(unsigned int minute);

   /**
    * Function to display date in format dd/mm/yyyy.
    * @return - Returns string of date in correct format.
    */
    string displayDate() const;

    /**
    * Function to display time in format hh:mm
    * @return - Returns string of date in correct time format.
    */
    string displayTime() const;

    /**
     * Function to display date and time in format: dd/mm/yyyy - hh:mm
     * @return - Returns string of date in correct format.
     */
    string displayDateTime() const;

    /**
     * Passes date to string.
     * @param date - date to pass to string
     * @return - Returns date in string dd/mm/yyyy
     */
    string toStringDate(const Date &date) const;

    /**
     * Passes time to string
     * @param date - time to pass to string
     * @return - Returns time in string hh::mm
     */
    string toStringTime(const Date &date) const;


    /**
     * Bool to determinate if object is a date(dd/mm/yyyy) or a time(hh:mm)
     * @return - Returns if object Date is date or time
     */
    bool isDate();

    /**
    * Date's < operator.
    * @param d - A Date object.
    * @return - Returns true if the Date is older.
    */
    bool operator < (const Date& d) const;

    /**
    * Date's == operator.
    * @param d - A Date object.
    * @return - Returns true if the Date is equal.
    */
    bool operator == (const Date& d) const;

    /**
     * Checks if Date is valid.
     * @param d - Date object to verify.
     * @return - Returns true if date is valid, false otherwise.
     */
    bool checkDate(const Date& d) const;

    /**
     * Checks if time is valid.
     * @param t - Date object to verify
     * @return - Returns true if time is valid, false otherwise.
     */
    bool checkTime(const Date& t) const;

private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    bool is_date;
};


#endif //FEUP_AED_DATE_H
