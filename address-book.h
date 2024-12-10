#pragma once

class Address_Book {
public:
    virtual ~Address_Book() = default;

    virtual void addContact() = 0;
    virtual void delContact() = 0;
    virtual void displayAll() = 0;
    virtual void editContact() = 0;
    virtual void findContact() = 0;
};
