cmake_minimum_required(VERSION 3.6)
project(ProgressBar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        CMakeLists.txt
        Display.h
        FileManager.cpp
        FileManager.h
        GUIBar.cpp
        GUIBar.h
        main.cpp
        Observer.h
        Subject.h GUIProgressBar.cpp GUIProgressBar.h ResourceFile.cpp ResourceFile.h)

add_subdirectory(test)
set(SOURCE_FILE FileManager.h FileManager.cpp GUIBar.h GUIBar.cpp GUIProgressBar.h GUIBar.cpp ResourceFile.cpp ResourceFile.h)
add_executable(ProgressBar main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ProgressBar core)


set(CURSES_NEED_NCURSES,TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
target_link_libraries(ProgressBar ${CURSES_LIBRARIES})