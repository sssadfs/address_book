#include "card-person.h"
#include <iostream>

Card_Person::Card_Person(){
    this->m_name = "李华";
    this->m_phoneNumber= "12345678901";
}

Card_Person::Card_Person(const string &name, const string &phonenumber){
    this->m_name = name;
    this->m_phoneNumber= phonenumber;
}

string Card_Person::getName() {
    return this->m_name;
}
string Card_Person::getPhonenumber() {
    return this->m_phoneNumber;
}

void Card_Person::set(const string &name, const string &phonenumber) {
    this->m_name = name;
    this->m_phoneNumber= phonenumber;
}
void Card_Person::modify() {
    cin >> *this;
}

void Card_Person::Display() {
    cout << *this;
}

ostream& operator<<(ostream& os, Card_Person& p) {
    os << p.m_name << "\t" << p.m_phoneNumber;
    return os;
}

istream& operator>>(istream& is, Card_Person& p) {
    cout << "请输入修改后的姓名" << endl;
    cin >> p.m_name;
    cout << "请输入修改后的电话号码" << endl;
    cin >> p.m_phoneNumber;
    return is;
}