#pragma once
#include "address-book.h"
#include "dev-person.h"

class Dev_Book final : public Address_Book {
public:
    int m_Contact_Count = 0;
    Dev_Person** m_Dev_Person_Array = new Dev_Person*[1000];

    void addContact() override;
    void delContact() override;
    void displayAll() override;
    void editContact() override;
    void findContact() override;

    Dev_Book();
    void init_Cont();
    static int getContactCount();
    [[nodiscard]] int isExistP(const string& phone) const;
    [[nodiscard]] int isExistN(const string& phone) const;

    ~Dev_Book() override;

    void save() const;

};
