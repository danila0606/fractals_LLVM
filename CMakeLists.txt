cmake_minimum_required(VERSION 3.19)

project(fractals)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} 
    main.c
    graphics.cpp)


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/bin ${CMAKE_CURRENT_BINARY_DIR})

find_package(LLVM REQUIRED CONFIG)
add_executable(generator LLVM_gen.cpp)
target_link_libraries(generator LLVM)
target_include_directories(generator PRIVATE ${LLVM_INCLUDE_DIRS})

