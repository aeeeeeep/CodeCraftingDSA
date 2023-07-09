cmake_minimum_required(VERSION 3.12)
project(MainCompiler)

file(GLOB subdirectories RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory})
        file(GLOB source_files ${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory}/main.cpp)

        if(source_files)
            add_executable(${subdirectory}_main ${source_files})

            set_target_properties(${subdirectory}_main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory})
        endif()
    endif()
endforeach()
