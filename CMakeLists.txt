cmake_minimum_required(VERSION 3.5)

project(N2ChatServer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core LinguistTools Network REQUIRED)

set(TS_FILES N2ChatServer_en_US.ts)

add_executable(N2ChatServer
  main.cpp
  n2chserver.cpp
  n2thread.cpp
  n2thread.h
  n2chserver.h
  ${TS_FILES}
)
target_link_libraries(N2ChatServer Qt5::Core Qt5::Network)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
