cmake_minimum_required(VERSION 3.29)
project(Addresse_Books)

set(CMAKE_CXX_STANDARD 26)

add_executable(Addresse_Books main.cpp
        menu.h
        menu.cpp
        user.h
        user.cpp
        card-person.h
        card-person.cpp
        dev-person.h
        dev-person.cpp
        address-book.h
        dev-book.cpp
        dev-book.h
        card-book.h
        card-book.cpp
)
