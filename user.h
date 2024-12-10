#pragma once
#include <iostream>
using namespace std;

#include "card-book.h"
#include "dev-book.h"

class User {
public:
    Card_Book CB;
    Dev_Book DB;

    void addContactC();
    void addContactD();

    void delContactC();
    void delContactD();

    void displayAllC();
    void displayAllD();

    void editContactC();
    void editContactD();

    void findContactC();
    void findContactD();

    void copyDevToCard();
    void moveDevToCard();
    void copyCardToDev();
    void moveCardToDev();
};