cmake_minimum_required(VERSION 3.16)

project(objectDetection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(objectDetection src/main.cpp
    readme.md
    .gitignore)

include(GNUInstallDirs)
install(TARGETS objectDetection
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
