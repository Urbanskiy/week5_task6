#include "TDate.h"
TDate::TDate()
{
    day = 0;
    mounth = 0;
    year = 0;
}
TDate::TDate(int d, int m, int y)
{
    if( (d < 1 || d > 31) || (m < 1 || m > 12))
    {
        cout << "\n Bad initialize of date";
    }
    else
    {
        day = d;
        mounth = m;
        year = y;
    }
}
TDate::TDate(TDate &date)
{
    cout << "COPY CONSTRUCTOR" << endl;
    this->day = date.day;
    this->mounth = date.mounth;
    this->year = date.year;
}
char * TDate::DateToStr()
{
    char * p = new char[9];
    if(mounth < 10)
        sprintf(p,"%d-0%d-%d",year,mounth,day);
    else
        sprintf(p,"%d-%d-%d",year,mounth,day);
    return p;
}
 bool TDate::operator>(TDate date)
 {
    if( strcmp(this->DateToStr(),date.DateToStr()) > 0 )
        return true;
    else
        false;
 }
  bool TDate::operator<(TDate date)
 {
    if( strcmp(this->DateToStr(),date.DateToStr()) < 0 )
        return true;
    else
        false;
 }
 TDate& TDate::operator=(TDate& date)
 {
     if(this == &date)
        throw "\n Cannot use operation= to itself";
     cout << "OPERATOR =" << endl;
     this->day = date.day;
     this->mounth = date.mounth;
     this->year = date.year;

     return *this;
 }
