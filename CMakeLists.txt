cmake_minimum_required(VERSION 3.0)
project(Calculator)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(Calculator main.cpp)
target_link_libraries(Calculator ${wxWidgets_LIBRARIES})
