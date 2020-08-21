#include "upDate.h"

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
    int j = g2j(m, d, y);
    j2g(j, m1, d1, y1);
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

// Displays the date in mm/dd/yyyy format
ostream& operator<<(ostream& out, const upDate& d) {
    out << d.dptr[0] << "/" << d.dptr[1] << "/" << d.dptr[2];
    return out;
}




// Takes in month, day, and year as parameters
// And converts them into a Julian integer
int g2j(int m, int d, int y) {
    return d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
}

// Month, day, and year are passed in as reference in the parameters
// The Julian int is then converted back into months, day, and year
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