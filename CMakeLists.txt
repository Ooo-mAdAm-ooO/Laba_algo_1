cmake_minimum_required(VERSION 3.25)
project(Rooster LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.1
)

FetchContent_MakeAvailable(fmt)

add_executable(rooster
    src/main.cpp 
    src/array_utils.cpp
    src/array_utils.h
    src/matrix_utils.cpp
    src/matrix_utils.h
    src/student_utils.cpp
    src/student_utils.h
)

target_link_libraries(rooster PRIVATE fmt::fmt)
