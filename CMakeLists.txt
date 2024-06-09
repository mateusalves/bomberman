cmake_minimum_required(VERSION 3.26)
project(chatroom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Networking)
add_subdirectory(Server)
add_subdirectory(Client)
