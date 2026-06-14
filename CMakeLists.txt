cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(server VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE client)
add_executable(${EXECUTABLE} main.cpp)

target_sources(${EXECUTABLE}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Networking/BindingSocket.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/Networking/ConnectingSocket.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/Networking/ListeningSocket.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/Networking/Socket.cc

    PUBLIC
        FILE_SET HEADERS
        # TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Networking
        FILES
            Networking/BindingSocket.hpp
            Networking/ConnectingSocket.hpp
            Networking/ListeningSocket.hpp
            Networking/Socket.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Networking
)
