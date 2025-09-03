#pragma once
#include "dev-book.h"
#include <fstream>
#include <iostream>
#define FILENAME_D "dev-book.txt"

void Dev_Book::addContact() {
    if (this->m_Dev_Person_Array == nullptr) {
        this->m_Dev_Person_Array = new Dev_Person*[1000];
    }
    cout << "请输入新增联系人的姓名" << endl;
    string name;
    cin >> name;
    cout << "请输入新增联系人的籍贯" << endl;
    string native;
    cin >> native;
    cout << "请输入新增联系人的电话号码" << endl;
    string phonenumber;
    cin >> phonenumber;
    cout << "请输入新增联系人的QQ号码" << endl;
    string qqnumber;
    cin >> qqnumber;

    this->m_Dev_Person_Array[this->m_Contact_Count] = new Dev_Person(name, native, phonenumber, qqnumber);
    this->m_Contact_Count += 1;

    this->save();
    cout << "成功添加一名联系人" << endl;
    system("pause");
    system("cls");
}

void Dev_Book::delContact() {
    if (this->m_Contact_Count<=0) {
        cout << "记录为空" << endl;
    }
    else {
        cout << "请输入需要删除的联系人的电话号码" << endl;
        string phone;
        cin >> phone;
        int ret = this->isExistP(phone);     //获取待删联系人的数组下标
        if(ret==-1) {
            cout << "删除失败，查无此人" << endl;
        }
        else {
            for (int i = ret; i < this->m_Contact_Count; i++) {
                this->m_Dev_Person_Array[i] = this->m_Dev_Person_Array[i+1];
            }
            this->m_Contact_Count-=1;
            cout << "删除成功" << endl;
            this->save();

        }
    }
    system("pause");
    system("cls");
}

 void Dev_Book::displayAll() {
     if (this->m_Contact_Count<=0) {
         cout << "记录为空" << endl;
     }
     else {
         for (int i = 0; i < this->m_Contact_Count; i++) {
             cout << *this->m_Dev_Person_Array[i] << endl;
         }
     }
     system("pause");
     system("cls");
 }

void Dev_Book::editContact(){
    if (this->m_Contact_Count<=0) {
        cout << "记录为空" << endl;
    }
    else{
        cout << "请输入修改的联系人的号码" << endl;
        string phone;
        cin >> phone;
        int ret = this->isExistP(phone);
        if(ret==-1) {
            cout << "修改失败，查无此人" << endl;
        }
        else {
            cin >> *this->m_Dev_Person_Array[ret];
            cout << "修改成功" << endl;
            this->save();
        }
    }
    system("pause");
    system("cls");
}

void Dev_Book::findContact(){
    if (this->m_Contact_Count<=0) {
        cout << "记录为空" << endl;
    }
    else {
        string name;
        cout << "请输入查找的联系人的姓名" << endl;
        cin >> name;
        int ret = this->isExistN(name);
        if (ret == -1) {
            cout << "查无此人" << endl;
        }
        else {
            cout << "查找倒了名为" << name << "的联系人，详细信息如下："<< endl;
            cout << *this->m_Dev_Person_Array[ret] << endl;
        }
    }
    system("pause");
    system("cls");
}

Dev_Book::Dev_Book(){
    ifstream ifs(FILENAME_D,ios::in);
    char bof;
    ifs >> bof;
    if (!ifs.is_open() or ifs.eof()) {
        this->m_Contact_Count=0;
        ifs.close();
        // cout << "empty file" << endl;
    }
    else {
        this->init_Cont();

    }
}

void Dev_Book::init_Cont() {
    this->m_Contact_Count = getContactCount();
    // cout << m_Contact_Count << endl;
    ifstream ifs;
    ifs.open(FILENAME_D, ifstream::in);
    string name;
    string native;
    string phonenumber;
    string qqnumber;
    int index = 0;
    while(ifs >> name >> native >> phonenumber >> qqnumber) {
        m_Dev_Person_Array[index] = new Dev_Person(name, native, phonenumber, qqnumber);
        index += 1;
    }
    ifs.close();
}

int Dev_Book::getContactCount() {
    ifstream ifs(FILENAME_D,ios::in);
    int num = 0;
    string name;
    string native;
    string phonenumber;
    string qqnumber;
    while(ifs >> name >> native >> phonenumber >> qqnumber) {
        num++;
    }
    ifs.close();
    return num;
}

int Dev_Book::isExistP(const string& phone) const {
    int flag = -1;
    for (int i =0;i<this->m_Contact_Count;i++) {
        if (m_Dev_Person_Array[i]->getPhonenumber() == phone) {
            flag = i;
        }
    }
    return flag;
}

int Dev_Book::isExistN(const string& name) const {
    int flag = -1;
    for (int i =0;i<this->m_Contact_Count;i++) {
        if (m_Dev_Person_Array[i]->getPhonenumber() == name) {
            flag = i;
        }
    }
    return flag;
}

Dev_Book::~Dev_Book() {
    this->save();
}

void Dev_Book::save() const{
    ofstream ofs;
    ofs.open(FILENAME_D,ios::out);
    for (int i = 0; i < m_Contact_Count; i++) {
        ofs << m_Dev_Person_Array[i]->getName() << " "
        << m_Dev_Person_Array[i]->getNative() << " "
        << m_Dev_Person_Array[i]->getPhonenumber() << " "
        << m_Dev_Person_Array[i]->getQNumber() << endl;
    }
    // if (ofs.is_open()) {
    //     cout << "test";
    //     system("pause");
    // }
    ofs.close();
}
