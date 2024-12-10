#pragma once
#include "card-person.h"


class Dev_Person : public Card_Person {
    friend ostream& operator<<(ostream& os, Dev_Person& p);
    friend istream& operator>>(istream& is, Dev_Person& p);
public:
    Dev_Person();
    Dev_Person(const string &name, const string &native, const string &phonenumber, const string &qqnumber);

    string getName();
    string getNative();
    string getPhonenumber();
    string getQNumber();

    void set(const string &name, const string &native, const string &phonenumber, const string &qqnumber);
    void modify();
    void Display();

private:
    string m_native;
    string m_qqNumber;
};

ostream& operator<<(ostream& os, Dev_Person& p);
istream& operator>>(istream& is, Dev_Person& p);