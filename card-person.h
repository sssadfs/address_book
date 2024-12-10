#pragma once
#include <string>
using namespace std;

class Card_Person {
    friend ostream& operator<<(ostream& os, Card_Person& p);
    friend istream& operator>>(istream& is, Card_Person& p);
public:
    Card_Person();
    Card_Person(const string &name, const string &phonenumber);

    string getName();
    string getPhonenumber();

    void set(const string &name, const string &phonenumber);
    void modify();
    void Display();

protected:
    string m_name;
    string m_phoneNumber;
};

ostream& operator<<(ostream& os, Card_Person& p);
istream& operator>>(istream& is, Card_Person& p);