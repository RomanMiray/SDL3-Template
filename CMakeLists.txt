cmake_minimum_required(VERSION 3.21)

project(SDL3-Template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXE_NAME SDL3-Template)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(${EXE_NAME} ${SRC_FILES})

target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/lib"
)

target_link_directories(${EXE_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/lib"
)

target_link_libraries(${EXE_NAME} PRIVATE
    SDL3
    SDL3_image
    SDL3_ttf
    SDL3_mixer
)

set_target_properties(${EXE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "@loader_path/lib"
)