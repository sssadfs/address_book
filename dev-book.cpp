#pragma once
#include "dev-book.h"
#include <fstream>
#include <iostream>
#define FILENAME_D "dev-book.txt"

void Dev_Book::addContact() {
    auto** newSpace = new Dev_Person*[1000];
    if (this->m_Dev_Person_Array != nullptr) {    //��ԭ���ռ��µ����ݿ������¿ռ���
        for (int i = 0; i < this->m_Contact_Count; i++) {
            newSpace[i] = this->m_Dev_Person_Array[i];
        }
    }
    cout << "������������ϵ�˵�����" << endl;
    string name;
    cin >> name;
    cout << "������������ϵ�˵ļ���" << endl;
    string native;
    cin >> native;
    cout << "������������ϵ�˵ĵ绰����" << endl;
    string phonenumber;
    cin >> phonenumber;
    cout << "������������ϵ�˵�QQ����" << endl;
    string qqnumber;
    cin >> qqnumber;
    newSpace[this->m_Contact_Count] = new Dev_Person(name, native, phonenumber, qqnumber);

    this->m_Dev_Person_Array = nullptr;
    delete [] this->m_Dev_Person_Array;

    this->m_Dev_Person_Array = newSpace;
    this->m_Contact_Count += 1;
    this->save();
    cout << "�ɹ����һ����ϵ��" << endl;
    system("pause");
    system("cls");
}

void Dev_Book::delContact() {
    if (this->m_Contact_Count<=0) {
        cout << "��¼Ϊ��" << endl;
    }
    else {
        cout << "��������Ҫɾ������ϵ�˵ĵ绰����" << endl;
        string phone;
        cin >> phone;
        int ret = this->isExist(phone);     //��ȡ��ɾ��ϵ�˵������±�
        if(ret==-1) {
            cout << "ɾ��ʧ�ܣ����޴���" << endl;
        }
        else {
            for (int i = ret; i < this->m_Contact_Count; i++) {
                this->m_Dev_Person_Array[i] = this->m_Dev_Person_Array[i+1];
            }
            this->m_Contact_Count-=1;
            cout << "ɾ���ɹ�" << endl;
            this->save();

        }
    }
    system("pause");
    system("cls");
}

 void Dev_Book::displayAll() {
     if (this->m_Contact_Count<=0) {
         cout << "��¼Ϊ��" << endl;
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
        cout << "��¼Ϊ��" << endl;
    }
    else{
        cout << "�������޸ĵ���ϵ�˵ĺ���" << endl;
        string phone;
        cin >> phone;
        int ret = this->isExist(phone);
        if(ret==-1) {
            cout << "�޸�ʧ�ܣ����޴���" << endl;
        }
        else {
            cin >> *this->m_Dev_Person_Array[ret];
            cout << "�޸ĳɹ�" << endl;
            this->save();
        }
    }
    system("pause");
    system("cls");
}

void Dev_Book::findContact(){
    if (this->m_Contact_Count<=0) {
        cout << "��¼Ϊ��" << endl;
    }
    else {
        string name;
        cout << "��������ҵ���ϵ�˵�����" << endl;
        cin >> name;
        int ret = this->isExist(name);
        if (ret == -1) {
            cout << "���޴���" << endl;
        }
        else {
            cout << "���ҵ�����Ϊ" << name << "����ϵ�ˣ���ϸ��Ϣ���£�"<< endl;
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
        this->m_Dev_Person_Array = nullptr;
        ifs.close();
        // cout << "empty file" << endl;
    }
    else {
        // cout << "yes" << endl;
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

int Dev_Book::isExist(const string& phone) const {
    int flag = -1;
    for (int i =0;i<this->m_Contact_Count;i++) {
        if (m_Dev_Person_Array[i]->getPhonenumber() == phone) {
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
