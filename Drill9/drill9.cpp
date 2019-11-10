#include "std_lib_facilities.h"
//9.4.1
/*
struct Date{
    int year;
    int month;
    int day;
};

void init_day(Date& date, int y, int m, int d){
    // check that (y,m,d) is a valid date
    if(m<1 || m>12) error("Invalid month");
    if(m<1 || m>31) error("Invalid day");

    // if it is, use it to initialize date
    date.year=y;
    date.month=m;
    date.day=d;
}

void add_day(Date& date, int n){
    date.day=date.day+n;
    if(date.day>31){
        date.day%=31;
    }
}

ostream& operator<< (ostream& os, const Date& d){
    return os << '(' << d.year << ',' << d.month << ',' << d.day << ')';
}

int main(){
    Date today;
    init_day(today,1978,6,25);
    Date tomorrow = today;
    add_day(tomorrow,1);

    cout << today <<'\n';
    cout << tomorrow << '\n';


}
*/

//9.4.2
/*
struct Date{
    int year,month,day;
    Date(int year,int month,int day);// check for valid date and initialize
    void add_day(int n); // increase the Date by n days
};

Date::Date(int y,int m,int d):year{y},month{m},day{d}
{
    if(m<1||m>12) error("Invalid month");
    if(d<1||d>31) error("Invalid day");
}

void Date::add_day(int n){
    day+=n;
    if(day>31) day%=31;
}

ostream& operator<< (ostream& os, const Date& d){
    return os << '(' << d.year << ',' << d.month << ',' << d.day << ')';
}

int main(){
    try{
        Date today(1978,6,25);
        Date tomorrow=today;
        tomorrow.add_day(1);

        cout << today <<'\n';
        cout << tomorrow << '\n';

        Date bad_Day(2004,7,-5);
        cout<< bad_Day;

    }
    catch(exception& e){
        cerr << e.what() <<'\n';
        return 1;
    }
    catch(...){
        cerr << "unknown error"<<'\n';
        return 2;
    }

}
*/

//9.4.3
/*
class Date{
    int y,m,d;

    public:
        Date(int y,int m,int d);
        void add_day(int n);

        int month() const {return m;}
        int year() const {return y;}
        int day() const {return d;}

};

Date::Date(int yy, int mm, int dd):y{yy}, m{mm}, d{dd}{
    if(m<1||m>12) error("Invalid month");
    if(d<1||d>31) error("Invalid day");
}

void Date::add_day(int n){
    d+=n;
     if(d>31) d%=31;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}


int main(){
    try{
        Date today(1978,6,25);
        Date tomorrow=today;
        tomorrow.add_day(1);

        cout << today <<'\n';
        cout << tomorrow << '\n';

        Date bad_Month(2004,77,25);
        cout<< bad_Month;


    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }

    catch(...) {
        cerr << "unknown error" << '\n';
        return 2;
    }

}

*/
//9.7.1

/*
enum Month {
    jan=1, feb=2, mar=3, apr=4, may=5, jun=6, jul=7, aug=8, sep=9, oct=10, nov=11, dec=12
};

vector<string> month_name = { "January", "February", "March", "April",
                             "May", "June", "July", "August", "September",
                             "October", "November", "December" };

class Date {
    int y;
    Month m;
    int d;
public:
    Date(int y, Month m, int d);
    void add_day(int n);
    int year() const { return y; }
    Month month() const { return m; }
    int day() const { return d; }
};

Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    if (d < 1 || 31 < d) error("impossible day");
}

void Date::add_day(int n)
{
    d += n;
    if (d > 31) d %= 31;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}

int main()
try {
    Date today(1978, Month::jun, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << today << '\n'
         << tomorrow << '\n';

    //Date bad_day(2004, 13, -5);
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "unknown error" << '\n';
    return 2;
}
*/
//9.7.4

namespace Chrono {

    enum class Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };


Month operator+(const Month& m, int n)
    {
        int r = int(m) + n;
        r %= int(Month::dec);

        if (r == 0) return Month::dec;
        return Month(r);
    }

Month operator-(const Month& m, int n) { return (m+(-n)); }
Month& operator+=(Month& m, int n) { m = m + n; return m; }
bool operator<(const Month& m, int n) { return int(m) < n; }
bool operator>(const Month& m, int n) { return int(m) > n; }

class Date {
    public:
        class Invalid {};
        Date(int yy, Month mm, int dd);

        Month month() const { return m; }
        int day() const { return d; }
        int year() const { return y; }

        void add_day(int n);            // increase the Date by n days
        void add_month(int n);          // increase the Date by n months
        void add_year(int n);           // increase the Date by n years

    private:
        int y;          // year
        Month m;
        int d;          // day
        bool is_valid();
};

    Date::Date(int yy, Month mm, int dd):y{yy}, m{mm}, d{dd}
    {
        if (!is_valid()) throw Invalid{};
    }

    bool Date::is_valid()//Check values
    {
        if (d < 1 || d > 31) return false;
        if (m < Month::jan || m > Month::dec) return false;
        return true;
    }

    void Date::add_day(int n)
    {
    int n_d = n % 31;          // days out of months, to increase
    int n_m = (n / 31) % 12;   // months out of years, to increase
    int n_y = n / (31*12);     // years to increase

    d += n_d;
    if(d>31){
        ++n_m;
        d -=31;
    }
    if(d<1){
        --n_m;
        d+=31;
    }
    if (Month::dec < (int(m)+n_m)) ++n_y;
    if (Month::jan > (int(m)+n_m)) --n_y;


    m += n_m;
    y += n_y;
}

    void Date::add_month(int n)
    {
        int n_m = n % 12;   // months out of years, to increase
        int n_y = n / 12;   // years to increase

        if (Month::dec < (int(m)+n_m)) ++n_y;
        if (Month::jan > (int(m)+n_m)) --n_y;
        m += n_m;
        y += n_y;
    }

    void Date::add_year(int n)
    {
        y += n;
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
    }

}; // namespace Chrono

int main()
try
{
    using Chrono::Date;
    using Chrono::Month;

    Date today{1978, Month::jun, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    Date test{2019, Month::dec, 31};
    cout << '\n';
    test.add_day(6);   // 2011 January 6th
    cout << "January the 6th 2020? " << test << '\n';
    test.add_day(-6);  // 2010 December 31st again
    cout << "December the 31st 2019? " << test << '\n';

    cout <<"\n";

    // Test add_month() and add_year()
    test.add_month(27);
    cout << "March the 5th 2022? " << test << '\n';
    test.add_month(-25);
    test.add_year(8);
    cout << "February the 5th 2027? " << test << '\n';
    test.add_year(-8);
    cout << "February the 5th 2019? " << test << '\n';

    // Invalid date
    Date today_e{1998, Month::dec, -5};

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(Chrono::Date::Invalid)
{
    cerr << "Invalid date!\n";
    return 2;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 3;
}
