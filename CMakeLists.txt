cmake_minimum_required(VERSION 3.6)
project(SecureInternetRelayChat_Server)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        catch.hpp
        Client.cpp
        Client.hpp
        clientinfo.cpp
        clientinfo.h
        Connection.cpp
        Connection.h
        main.cpp
        Server.cpp
        Server.hpp)

add_executable(SecureInternetRelayChat_Server ${SOURCE_FILES})