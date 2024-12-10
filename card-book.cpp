#pragma once
#include "card-book.h"
#include <fstream>
#include <iostream>
#define FILENAME_C "card-book.txt"

void Card_Book::addContact() {
    auto** newSpace = new Card_Person * [1000];
    if (this->m_Card_Person_Array != nullptr) {    //将原来空间下的数据拷贝到新空间下
        for (int i = 0; i < this->m_Contact_Count; i++) {
            newSpace[i] = this->m_Card_Person_Array[i];
        }
    }
    cout << "请输入新增联系人的姓名" << endl;
    string name;
    cin >> name;
    cout << "请输入新增联系人的电话号码" << endl;
    string phonenumber;
    cin >> phonenumber;
    newSpace[this->m_Contact_Count] = new Card_Person(name, phonenumber);

    this->m_Card_Person_Array = nullptr;
    delete[] this->m_Card_Person_Array;

    this->m_Card_Person_Array = newSpace;
    this->m_Contact_Count += 1;
    this->save();
    cout << "成功添加一名联系人" << endl;
    system("pause");
    system("cls");
}

void Card_Book::delContact() {
    if (this->m_Contact_Count <= 0) {
        cout << "记录为空" << endl;
    }
    else {
        cout << "请输入需要删除的联系人的电话号码" << endl;
        string phone;
        cin >> phone;
        int ret = this->isExist(phone);     //获取待删联系人的数组下标
        if (ret == -1) {
            cout << "删除失败，查无此人" << endl;
        }
        else {
            for (int i = ret; i < this->m_Contact_Count; i++) {
                this->m_Card_Person_Array[i] = this->m_Card_Person_Array[i + 1];
            }
            this->m_Contact_Count -= 1;
            cout << "删除成功" << endl;
            this->save();

        }
    }
    system("pause");
    system("cls");
}

void Card_Book::displayAll() {
    if (this->m_Contact_Count <= 0) {
        cout << "记录为空" << endl;
    }
    else {
        for (int i = 0; i < this->m_Contact_Count; i++) {
            cout << *this->m_Card_Person_Array[i] << endl;
        }
    }
    system("pause");
    system("cls");
}

void Card_Book::editContact() {
    if (this->m_Contact_Count <= 0) {
        cout << "记录为空" << endl;
    }
    else {
        cout << "请输入修改的联系人的号码" << endl;
        string phone;
        cin >> phone;
        int ret = this->isExist(phone);
        if (ret == -1) {
            cout << "修改失败，查无此人" << endl;
        }
        else {
            cin >> *this->m_Card_Person_Array[ret];
            cout << "修改成功" << endl;
            this->save();
        }
    }
    system("pause");
    system("cls");
}

void Card_Book::findContact() {
    if (this->m_Contact_Count <= 0) {
        cout << "记录为空" << endl;
    }
    else {
        string name;
        cout << "请输入查找的联系人的姓名" << endl;
        cin >> name;
        int ret = this->isExist(name);
        if (ret == -1) {
            cout << "查无此人" << endl;
        }
        else {
            cout << "查找倒了名为" << name << "的联系人，详细信息如下：" << endl;
            cout << *this->m_Card_Person_Array[ret] << endl;
        }
    }
    system("pause");
    system("cls");
}

Card_Book::Card_Book() {
    ifstream ifs(FILENAME_C, ios::in);
    char bof;
    ifs >> bof;
    if (!ifs.is_open() or ifs.eof()) {
        this->m_Contact_Count = 0;
        this->m_Card_Person_Array = nullptr;
        ifs.close();
        // cout << "empty file" << endl;
    }
    else {
        // cout << "yes" << endl;
        this->init_Cont();

    }
}

void Card_Book::init_Cont() {
    this->m_Contact_Count = getContactCount();
    cout << m_Contact_Count << endl;
    ifstream ifs;
    ifs.open(FILENAME_C, ifstream::in);
    string name;
    string native;
    string phonenumber;
    string qqnumber;
    int index = 0;
    while (ifs >> name >> phonenumber) {
        m_Card_Person_Array[index] = new Card_Person(name, phonenumber);
        index += 1;
    }
    ifs.close();
}

int Card_Book::getContactCount() {
    ifstream ifs(FILENAME_C, ios::in);
    int num = 0;
    string name;
    string phonenumber;
    while (ifs >> name >> phonenumber) {
        num++;
    }
    ifs.close();
    return num;
}

int Card_Book::isExist(const string& phone) const {
    int flag = -1;
    for (int i = 0; i < this->m_Contact_Count; i++) {
        if (m_Card_Person_Array[i]->getPhonenumber() == phone) {
            flag = i;
        }
    }
    return flag;
}


Card_Book::~Card_Book() {
    this->save();
}

void Card_Book::save() const {
    ofstream ofs;
    ofs.open(FILENAME_C, ios::out);
    for (int i = 0; i < m_Contact_Count; i++) {
        ofs << m_Card_Person_Array[i]->getName() << " "
            << m_Card_Person_Array[i]->getPhonenumber() << endl;
    }
    ofs.close();
}
