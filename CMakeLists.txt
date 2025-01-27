cmake_minimum_required(VERSION 3.16)

project(objectDetection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(objectDetection src/main.cpp
    readme.md
    .gitignore
    resources/cars2.mp4
    resources/plate_number.xml
)

target_include_directories(objectDetection PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(objectDetection PRIVATE ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS objectDetection
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
