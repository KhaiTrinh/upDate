/* 
===========================================================================
Name: Khai Trinh
Date: 08/21/2020
Description: This program utilizes operator overloading, Gregorian date,
and Julian date to perform arithmetic with date-objects. The objective
of the program is to familiarize the concept of operator overloading and 
dynamic memory alloction in c++.
=========================================================================== 
*/

#include "upDate.h"
#include <cstdlib>

int upDate::count = 0;	// Keeps count of how many upDate objects exist

int g2j(int, int, int);				// Converts Gregorian date to Julian
void j2g(int, int&, int&, int&);	// Converts Julian date to Gregorian

upDate::upDate() {	// Default constructor
    dptr = new int[3];
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
    count++;
}

upDate::upDate(int m, int d, int y) {	// Multi constructor
    dptr = new int[3];
    int m1, d1, y1;

	// This converts the Gregorian date to Julian and then back to Gregorian
    int j = g2j(m, d, y);
    j2g(j, m1, d1, y1);

	// This compares the inputed date with the converted date to see if they match
	if(m == m1 && d == d1 && y == y1) {	// Matching = date is valid
		dptr[0] = m;
		dptr[1] = d;
		dptr[2] = y;
	} else {	// If not then just set the date to the default
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
}

upDate::upDate(int j) {	// Constructor using Julian date
	dptr = new int[3];
	int m, d, y;
	j2g(j, m, d, y);
	dptr[0] = m;
	dptr[1] = d;
	dptr[2] = y;
	count++;
}

upDate::upDate(const upDate& d) {	// Constructor using another upDate object
	dptr = new int[3];
	dptr[0] = d.dptr[0];
	dptr[1] = d.dptr[1];
	dptr[2] = d.dptr[2];
	count++;
}

upDate::~upDate() {	// Destructor
    count--;
    delete []dptr;
}

upDate upDate::operator=(const upDate& d) {	// Assignment operator
	// If the addresses match then just return this object
	if(&d != this) {
		dptr[0] = d.dptr[0];
		dptr[1] = d.dptr[1];
		dptr[2] = d.dptr[2];
	}
	return *this;
}

// Add n days to this date and reassigns it back to itself
upDate upDate::operator+=(int n) {
	int j = g2j(dptr[0], dptr[1], dptr[2]) + n;
	j2g(j, dptr[0], dptr[1], dptr[2]);
	return *this;
}

// Subtract n days from this date and reassigns it back to itself
upDate upDate::operator-=(int n) {
	int j = g2j(dptr[0], dptr[1], dptr[2]) - n;
	j2g(j, dptr[0], dptr[1], dptr[2]);
	return *this;
}

// Allows for date obj to add n days
upDate upDate::operator+(int n) {
	upDate d;
	int j = g2j(dptr[0], dptr[1], dptr[2]) + n;
	j2g(j, d.dptr[0], d.dptr[1], d.dptr[2]);
	return d;
}

// Allows for date obj to subtract n days
upDate upDate::operator-(int n) {
	upDate d;
	int j = g2j(dptr[0], dptr[1], dptr[2]) - n;
	j2g(j, d.dptr[0], d.dptr[1], d.dptr[2]);
	return d;
}

// Allows for n days to be added to date obj
upDate operator+(int n, const upDate& d) {
	upDate temp;
	int j = g2j(d.dptr[0], d.dptr[1], d.dptr[2]) + n;
	j2g(j, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

// Allows for n days to be subtracted from date obj
upDate operator-(int n, const upDate& d) {
	upDate temp;
	int j = g2j(d.dptr[0], d.dptr[1], d.dptr[2]) - n;
	j2g(j, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

// Calculates the number of days between two dates
int operator-(const upDate& d1, const upDate& d2) {
	int j1 = g2j(d1.dptr[0], d1.dptr[1], d1.dptr[2]);
	int j2 = g2j(d2.dptr[0], d2.dptr[1], d2.dptr[2]);
	return abs(j1 - j2);
}

// Post-increment
upDate upDate::operator++(int dummy) {
	int j = g2j(this->dptr[0], this->dptr[1], this->dptr[2]) + 1;
	j2g(j, this->dptr[0], this->dptr[1], this->dptr[2]);
	return *this;
}

// Pre-increment
upDate upDate::operator++() {
	int j = g2j(this->dptr[0], this->dptr[1], this->dptr[2]) + 1;
	j2g(j, this->dptr[0], this->dptr[1], this->dptr[2]);
	return *this;
}

// Post-decrement
upDate upDate::operator--(int dummy) {
	int j = g2j(this->dptr[0], this->dptr[1], this->dptr[2]) - 1;
	j2g(j, this->dptr[0], this->dptr[1], this->dptr[2]);
	return *this;
}

// Pre-decrement
upDate upDate::operator++() {
	int j = g2j(this->dptr[0], this->dptr[1], this->dptr[2]) - 1;
	j2g(j, this->dptr[0], this->dptr[1], this->dptr[2]);
	return *this;
}

// Displays the date in mm/dd/yyyy format
ostream& operator<<(ostream& out, const upDate& d) {
    out << d.dptr[0] << "/" << d.dptr[1] << "/" << d.dptr[2];
    return out;
}

// Returns number of existing date objs while program is operational
int upDate::GetDateCount() { return count; }

// Returns the Julian date
int upDate::julian() { return g2j(dptr[0], dptr[1], dptr[2]); }

int upDate::getMonth() { return dptr[0]; }

int upDate::getDay() { return dptr[1]; }

int upDate::getYear() { return dptr[2]; }

// Setter checks for the validity of the date before setting
void upDate::setDate(int m, int d, int y) {
	int m1, d1, y1;
	int j = g2j(m, d, y);
	j2g(j, m1, d1, y1);

	if (m == m1 && d == d1 && y == y1) {
		dptr[0] = m;
		dptr[1] = d;
		dptr[2] = y;
	} else {
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
}

string upDate::getMonthName() {
	switch (dptr[0]) {
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	}
}

// Takes in month, day, and year as parameters
// And converts them into a Julian integer
int g2j(int m, int d, int y) {
    return d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
}

// Month, day, and year are passed in as reference in the parameters
// The Julian int is then converted back into month, day, and year
// And assigns them back to each corresponding variable
void j2g(int jd, int & m, int & d, int & y) {
	int l, n, i, j, k;

	l = jd + 68569;
	n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	i = 4000 * (l + 1) / 1461001;
	l = l - 1461 * i / 4 + 31;
	j = 80 * l / 2447;
	k = l - 2447 * j / 80;
	l = j / 11;
	j = j + 2 - 12 * l;
	i = 100 * (n - 49) + i + l;

	y = i;
	m = j;
	d = k;
}