cmake_minimum_required(VERSION 3.16)

project(licence-detection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(src)

find_package(OpenCV REQUIRED)

add_executable(licence-detection src/main.cpp
    readme.md
    .gitignore
    resources/cars2.mp4
    resources/plate_number.xml
    src/main.h
    src/base.h src/base.cpp

)

target_include_directories(licence-detection PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(licence-detection PRIVATE ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS licence-detection
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
