cmake_minimum_required(VERSION 3.16)
project("App")

set(TARGET_NAME "Server")

set(HEADERS
    inc/SimpleSerial.h
    inc/Handler.h)

set(SOURCES
    src/SimpleSerial.cpp
    src/Handler.cpp
    src/main.cpp)

add_executable(${TARGET_NAME}
        ${HEADERS}
        ${SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC "inc")
target_include_directories(${TARGET_NAME} PRIVATE "../ext/cpp-httplib")
target_include_directories(${TARGET_NAME} PRIVATE "../ext/json/single_include/nlohmann")
target_include_directories(${TARGET_NAME} PRIVATE "../ext/asio-1.18.2/include")
