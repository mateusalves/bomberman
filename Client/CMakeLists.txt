cmake_minimum_required(VERSION 3.26)
project(Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*)

set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../External/asio-1.30.2")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${BOOST_INCLUDEDIR}
    PRIVATE
)

