#include "menu.h"
#include "user.h"

int main() {
    User usr;
    string option;
    string choice;
    begin:
    system("cls");
    Menu::preDisplay();
    cin >> option;
    if (option == "2") {
        suspensionC:
        system("cls");
        Menu::Display2();
    }
    else if (option == "0") {
        cout << "欢迎下次使用" << endl;
        system("pause");
        return 0;
    }
    else {
        suspensionD:
        system("cls");
        Menu::Display1();
    }
    cin >> choice;
    if (choice=="0")       //option=="2"操作手机卡
            goto begin;
    else if (choice=="1")
            option=="2"?usr.addContactC():usr.addContactD();
    else if (choice=="2")
            option=="2"?usr.delContactC():usr.delContactD();
    else if (choice=="3")
            option=="2"?usr.editContactC():usr.editContactD();
    else if (choice=="4")
            option=="2"?usr.findContactC():usr.findContactD();
    else if (choice=="5")
            option=="2"?usr.displayAllC():usr.displayAllD();
    else if (choice=="6")
            option=="2"?usr.moveCardToDev():usr.moveDevToCard();
    else if (choice=="7")
            option=="2"?usr.copyCardToDev():usr.copyDevToCard();
    else{
            cout << "请重新输入" << endl;
            system("pause");
    }
    if (option=="2")
        goto suspensionC;
    goto suspensionD;
}
