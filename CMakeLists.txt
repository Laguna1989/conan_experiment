cmake_minimum_required(VERSION 3.27)
project(approvaltest_conan)

find_program(CONAN_CMD conan)
if(NOT CONAN_CMD)
    message(FATAL_ERROR "conan not found")
endif()

message(STATUS "Found conan ${CONAN_CMD}")
execute_process(
    COMMAND "${CONAN_CMD}" install
        --build=missing
        --output-folder=${CMAKE_BINARY_DIR}
        .
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RESULT_VARIABLE CONAN_RESULT
)

if(NOT CONAN_RESULT EQUAL 0)
    message(FATAL_ERROR "conan command failed")
endif()

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(Catch2 REQUIRED)


add_executable(approvaltest_conan main.cpp)
target_link_libraries(approvaltest_conan Catch2::Catch2WithMain)


