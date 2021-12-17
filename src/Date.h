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
     * Returns string with Date - DD/MM/YYYY
     */
    string displayDate();

    /**
     * Returns string with Time - HH:MM
     */
    string displayTime();

    /**
     * Returns string with Date and Time - DD/MM/YYYY - HH:MM
     */
    string displayDateTime();

    /**
     * Passes date to string
     * @param date - date to change to string
     * @return - Returns date in string
     */
    string toString(Date date) const;

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

private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    bool is_date;
};


#endif //FEUP_AED_DATE_H
