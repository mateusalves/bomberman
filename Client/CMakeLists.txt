cmake_minimum_required(VERSION 3.26)
project(Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*)

set(ASIO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../External/asio")
set(ASIO_INCLUDEDIR "${ASIO_ROOT}/include")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${ASIO_INCLUDEDIR}
    PRIVATE
)

