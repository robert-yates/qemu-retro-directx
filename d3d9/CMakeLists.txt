cmake_minimum_required(VERSION 3.15)
project(d3d9 C)

add_library(${PROJECT_NAME} SHARED  src/buffer.c
                                    src/d3d9_main.c
                                    src/device.c
                                    src/directx.c
                                    src/query.c
                                    src/shader.c
                                    src/stateblock.c
                                    src/surface.c
                                    src/swapchain.c
                                    src/texture.c
                                    src/vertexdeclaration.c
                                    src/volume.c
                                    src/d3d9.def
)

if (MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Releae>:Release>")
endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../general)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../general/wine)
target_link_libraries(${PROJECT_NAME} PRIVATE wined3d opengl32 user32 gdi32 advapi32)
