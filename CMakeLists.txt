cmake_minimum_required(VERSION 3.10.2)
project(echobot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(Boost_USE_MULTITHREADED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDES LIST_DIRECTORIES false ${INCLUDE_DIR}/*.hpp)


find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()


add_library(${CMAKE_PROJECT_NAME}_lib 
            ${SOURCES}
            ${INCLUDES})

add_executable(${CMAKE_PROJECT_NAME}_exe src/main.cpp)

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES)

add_dependencies(${CMAKE_PROJECT_NAME}_exe ${CMAKE_PROJECT_NAME}_lib)

target_link_libraries(${CMAKE_PROJECT_NAME}_exe /usr/local/lib/libTgBot.a 
            ${CMAKE_PROJECT_NAME}_lib
            ${CMAKE_THREAD_LIBS_INIT} 
            ${OPENSSL_LIBRARIES} 
            ${Boost_LIBRARIES} 
            ${CURL_LIBRARIES})