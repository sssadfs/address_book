#pragma once
#include "address-book.h"
#include "dev-person.h"

class Card_Book : public Address_Book {
public:
    int m_Contact_Count = 0;
    Card_Person** m_Card_Person_Array = new Card_Person*[1000];

    void addContact() override;
    void delContact() override;
    void displayAll() override;
    void editContact() override;
    void findContact() override;

    Card_Book();
    void init_Cont();
    static int getContactCount();
    [[nodiscard]] int isExistP(const string& phone) const;
    [[nodiscard]] int isExistN(const string& phone) const;

    ~Card_Book() override;

    void save() const;
};
