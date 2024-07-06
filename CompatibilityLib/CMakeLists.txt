CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

project(CompatibilityLib C)

include_directories(../wined3d/src/)
include_directories(../general/)
add_library(${PROJECT_NAME} STATIC src/compat.c)

if (MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Releae>:Release>")
endif ()

target_include_directories(${PROJECT_NAME} PUBLIC ./inc)

