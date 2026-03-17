cmake_minimum_required(VERSION 3.26)
project(Saper)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Saper main.cpp
        MinesweeperBoard.h
        MinesweeperBoard.cpp
        MSBoardTextView.cpp
        MSBoardTextView.h
        MSTextController.cpp
        MSTextController.h
)

add_executable( Saper_sfml main-sfml.cpp
        MinesweeperBoard.cpp
        MinesweeperBoard.h
        MSBSFMLView.cpp
        MSBSFMLView.h
        MSSFMLController.h
        MSSFMLController.cpp
)

file(COPY Images DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(Saper_sfml sfml-graphics)
