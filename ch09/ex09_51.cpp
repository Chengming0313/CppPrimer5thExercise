//
//  ex09_51.cpp
//  cpp primer 5th exercise 9.51
//
//  Created by Tang Chengming on 04/17/2021
//
//  @Brief  Write a class that has three unsigned members representing year,
//          month, and day. Write a constructor that takes a string representing
//          a date. Your constructor should handle a variety of date formats,
//          such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.

#include <iostream>
#include <string>

class MDate {
public:
    MDate(std::string const &date);
    void Print() { std::cout << _month << "/" << _day << "/" << _year << "\n"; }

private:
    unsigned _year;
    unsigned _month;
    unsigned _day;
};

MDate::MDate(std::string const &date) {
    // 获取 year
    _year = std::stoi(date.substr(date.size() - 4));
    // 获取 day
    char bch = ' ', ech = ' ';
    if (date.find(",") != std::string::npos) {
        ech = ',';
    }
    else if (date.find("/") != std::string::npos) {
        bch = '/';
        ech = '/';
    }
    _day = std::stoi(date.substr(date.find(bch) + 1, date.find(ech) - date.find(bch) - 1));
    // 获取 month
    if (date.find("/") != std::string::npos) {
        _month = std::stoi(date.substr(0, date.find_first_of("/")));
        return;
    }
    if (date.find("Jan") < date.size()) _month = 1;
    if (date.find("Feb") < date.size()) _month = 2;
    if (date.find("Mar") < date.size()) _month = 3;
    if (date.find("Apr") < date.size()) _month = 4;
    if (date.find("May") < date.size()) _month = 5;
    if (date.find("Jun") < date.size()) _month = 6;
    if (date.find("Jul") < date.size()) _month = 7;
    if (date.find("Aug") < date.size()) _month = 8;
    if (date.find("Sep") < date.size()) _month = 9;
    if (date.find("Oct") < date.size()) _month = 10;
    if (date.find("Nov") < date.size()) _month = 11;
    if (date.find("Dec") < date.size()) _month = 12;
}

int main() {
    MDate date1{ "January 1, 1990" };
    MDate date2{ "1/1/1990" };
    MDate date3{ "Jan 1 1990" };

    date1.Print();
    date2.Print();
    date3.Print();
    return 0;
}
