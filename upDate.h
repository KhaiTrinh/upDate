#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include <string>

using namespace std;

class upDate {
    private:
        int *dptr;
        static int count;

    public:
        upDate();
        upDate(int, int, int);
        upDate(int);
        upDate(const upDate&);
        ~upDate();
        upDate operator=(const upDate&);
        upDate operator+=(int);
        upDate operator-=(int);
        upDate operator+(int);
        upDate operator-(int);
        upDate operator++(int);
        upDate operator++();
        upDate operator--(int);
        upDate operator--();
        bool operator==(upDate);
        bool operator<(upDate);
        bool operator>(upDate);
        friend upDate operator+(int, const upDate&);
        friend int operator-(const upDate&, const upDate&);
        friend ostream& operator<<(ostream&, const upDate&);
        static int GetDateCount();
        int julian();
        int getMonth();
        int getDay();
        int getYear();
        void setDate(int, int, int);
        string getMonthName();
};

#endif