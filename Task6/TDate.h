#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class TDate
{
private:
    int day;
    int mounth;
    int year;
public:
    TDate();
    TDate(int,int,int);
    TDate(TDate &);

    void SetDate(int d,int m,int y) { day = d; mounth = m; year = y;}
    int GetDay() { return day;}
    int GetMounth() { return mounth;}
    int GetYear() { return year;}
    char * DateToStr();

    bool operator>(TDate);
    bool operator<(TDate);
    TDate & operator=(TDate &);
};

#endif // MAIN_H_INCLUDED
