#include "dev-person.h"
#include <iostream>

Dev_Person::Dev_Person(){
    this->m_name = "李华";
    this->m_native = "泰安市";
    this->m_phoneNumber= "12345678901";
    this->m_qqNumber = "987654321";
}

Dev_Person::Dev_Person(const string &name, const string &native, const string &phonenumber, const string &qqnumber){
    this->m_name = name;
    this->m_native = native;
    this->m_phoneNumber= phonenumber;
    this->m_qqNumber = qqnumber;
}

void Dev_Person::set(const string &name, const string &native, const string &phonenumber, const string &qqnumber) {
    this->m_name = name;
    this->m_native = native;
    this->m_phoneNumber= phonenumber;
    this->m_qqNumber = qqnumber;
}

string Dev_Person::getName() {
    return this->m_name;
}
string Dev_Person::getNative() {
    return this->m_native;
}
string Dev_Person::getPhonenumber() {
    return this->m_phoneNumber;
}
string Dev_Person::getQNumber() {
    return this->m_qqNumber;
}


void Dev_Person::modify() {
    cin >> *this;
}

void Dev_Person::Display() {
    cout << *this;
}

ostream& operator<<(ostream& os, Dev_Person& p) {
    os << p.m_name << "\t" << p.m_native << "\t" << p.m_phoneNumber << "\t" << p.m_qqNumber;
    return os;
}

istream& operator>>(istream& is, Dev_Person& p) {
    cout << "请输入修改后的姓名" << endl;
    cin >> p.m_name;
    cout << "请输入修改后的籍贯" << endl;
    cin >> p.m_native;
    cout << "请输入修改后的电话号码" << endl;
    cin >> p.m_phoneNumber;
    cout << "请输入修改后的QQ号码" << endl;
    cin >> p.m_qqNumber;
    return is;
}