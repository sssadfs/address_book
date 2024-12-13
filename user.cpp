#include "user.h"
#include "iostream"

void User::addContactC() {
    CB.addContact();
}
void User::addContactD() {
    DB.addContact();
}

void User::delContactC() {
    CB.delContact();
}
void User::delContactD() {
    DB.delContact();
}

void User::displayAllC() {
    CB.displayAll();
}
void User::displayAllD() {
    DB.displayAll();
}

void User::editContactC() {
    CB.editContact();
}
void User::editContactD() {
    DB.editContact();
}

void User::findContactC() {
    CB.findContact();
}
void User::findContactD() {
    DB.findContact();
}

void User::copyDevToCard() {
    for (int k =0; k < CB.m_Contact_Count; k++) {
        delete CB.m_Card_Person_Array[k];
        CB.m_Card_Person_Array[k] = nullptr;
    }
    for (int i = 0; i < DB.m_Contact_Count; i++) {
        CB.m_Card_Person_Array[i] = new Card_Person(DB.m_Dev_Person_Array[i]->getName(),DB.m_Dev_Person_Array[i]->getPhonenumber());
    }
    CB.m_Contact_Count = DB.m_Contact_Count;
    cout << "复制完成" << endl;
    CB.save();
    system("pause");
    system("cls");
}
void User::moveDevToCard() {
    for (int i = 0,j = CB.m_Contact_Count; i < DB.m_Contact_Count; i++, j++) {
        CB.m_Card_Person_Array[j] = new Card_Person(DB.m_Dev_Person_Array[i]->getName(),DB.m_Dev_Person_Array[i]->getPhonenumber());
        delete DB.m_Dev_Person_Array[i];
        DB.m_Dev_Person_Array[i] = nullptr;
    }
    CB.m_Contact_Count += DB.m_Contact_Count;
    DB.m_Contact_Count = 0;

    cout << "移动完成" << endl;
    DB.save();
    CB.save();
    system("pause");
    system("cls");
}

void User::copyCardToDev() {
    for (int k =0; k < DB.m_Contact_Count; k++) {
        delete DB.m_Dev_Person_Array[k];
        DB.m_Dev_Person_Array[k] = nullptr;
    }
    for (int i = 0; i < CB.m_Contact_Count; i++) {
        DB.m_Dev_Person_Array[i] = new Dev_Person(CB.m_Card_Person_Array[i]->getName(),"None",CB.m_Card_Person_Array[i]->getPhonenumber(),"None");
    }
    DB.m_Contact_Count = CB.m_Contact_Count;
    cout << "复制完成" << endl;
    DB.save();
    system("pause");
    system("cls");
}
void User::moveCardToDev() {
    for (int i = 0,j = DB.m_Contact_Count; i < CB.m_Contact_Count; i++, j++) {
        DB.m_Dev_Person_Array[j] = new Dev_Person(CB.m_Card_Person_Array[i]->getName(),"None",CB.m_Card_Person_Array[i]->getPhonenumber(),"None");
        delete CB.m_Card_Person_Array[i];
        CB.m_Card_Person_Array[i] = nullptr;
    }
    DB.m_Contact_Count += CB.m_Contact_Count;
    CB.m_Contact_Count = 0;

    cout << "移动完成" << endl;
    DB.save();
    CB.save();
    system("pause");
    system("cls");
}
