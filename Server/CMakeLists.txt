cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(server VERSION 1.0.0 LANGUAGES CXX)


set(TARGET_NAME server)

add_executable(${TARGET_NAME} test.cpp)

target_sources(${TARGET_NAME} 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Server.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/TestServer.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/../Networking/BindingSocket.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/../Networking/ListeningSocket.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/../Networking/Socket.cc
        
    PUBLIC
        FILE_SET HEADERS
        # BASE_DIRS 
        #     ${CMAKE_CURRENT_SOURCE_DIR}/../Networking/
        #     ${CMAKE_CURRENT_SOURCE_DIR}
        FILES    
            Server.hpp
            TestServer.hpp
            # ${CMAKE_CURRENT_SOURCE_DIR}/../Networking/BindingSocket.hpp
            # ListeningSocket.hpp
)

target_include_directories(${TARGET_NAME} 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/../Networking/
)